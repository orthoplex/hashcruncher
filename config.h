#include <stdint.h>
#define MAGIC_LEN 4
#define MAGIC_MIN 32
#define MAGIC_MAX 126
typedef int64_t pyint;
typedef struct { char* input; int output; } pair;

/*
// Knight Moves
#define MODULUS 3
const pair PAIRS[] = {
 {"a", 0}, {"b", 1}, {"c", 2}, {"d", 2}, {"e", 2}, {"f", 2}, {"g", 1}, {"h", 0},
 {"1", 0}, {"2", 1}, {"3", 2}, {"4", 2}, {"5", 2}, {"6", 2}, {"7", 1}, {"8", 0},
 {"'", 2}
};
*/

// Golf scores
#define MODULUS 9
const pair PAIRS[] = {
 {"Condor",       0},
 {"Albatross",    1},
 {"Eagle",        2},
 {"Birdie",       3},
 {"Par",          4},
 {"Bogey",        5},
 {"Double Bogey", 6},
 {"Triple Bogey", 7}
};

const int INPUTS = sizeof(PAIRS) / sizeof(pair);
