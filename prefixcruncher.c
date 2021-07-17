#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#define MOD(a, b) ((a % b + b) % b)
#define P (pyint)(1000003)

void dump(char *str) {
 for (int i = 0; str[i] != '\0'; i++) printf("%02x ", str[i]);
 putchar(' ');
 for (int i = 0; str[i] != '\0'; i++) putchar(32 <= str[i] && str[i] <= 126 ? str[i] : '.');
 putchar('\n');
}

int main(void) {
 // Validation and Initialization
 if (MODULUS % 2 == 0) fprintf(stderr, "Warning: Finding a magic string may be impossible with an even MODULUS.\n");

 int strlens[INPUTS];
 for (int j = 0; j < INPUTS; j++) {
  strlens[j] = strlen(PAIRS[j].input);
  if (strlens[j] == 0) {
   fprintf(stderr, "Error: pair.input must not be the empty string.\n");
   exit(EXIT_FAILURE);
  }
 }
 
 char magic[MAGIC_LEN + 1];
 for (int i = 0; i < MAGIC_LEN; i++) magic[i] = MAGIC_MIN;
 magic[MAGIC_LEN] = '\0';
 char *final_magic = magic + MAGIC_LEN - 1;

 pyint cache[MAGIC_LEN][INPUTS];
 for (int j = 0; j < INPUTS; j++) {
  cache[0][j] = (P * (PAIRS[j].input[0] << 7)) ^ PAIRS[j].input[0];
  for (int l = 1; l < strlens[j]; l++) cache[0][j] = (P * cache[0][j]) ^ PAIRS[j].input[l];
 }

 int k = 0;
 for (;;) {
  // Fill cache
  for (int i = k + 1; i < MAGIC_LEN; i++)
   for (int j = 0; j < INPUTS; j++) cache[i][j] = (P * cache[i - 1][j]) ^ magic[i - 1];

  // Test magic string (loop over final magic character)
  for (*final_magic = MAGIC_MIN; MAGIC_MIN <= *final_magic && *final_magic <= MAGIC_MAX; (*final_magic)++) {
   int valid = 1;
   for (int j = 0; j < INPUTS && valid; j++) {
    pyint hash = (P * cache[MAGIC_LEN - 1][j]) ^ *final_magic ^ (strlens[j] + MAGIC_LEN);
    hash = (hash == -1) ? -2 : hash;
    valid &= MOD(hash, MODULUS) == PAIRS[j].output;
   }
   if (valid) dump(magic);
  }

  // Increment string
  int k = MAGIC_LEN - 2;
  for (;magic[k] == MAGIC_MAX; k--) {
   if (k == 0) exit(EXIT_SUCCESS);
   magic[k] = MAGIC_MIN;
  }
  magic[k]++;
 }
}
