# hashcruncher

Consider the probem of mapping golf score names to their numeric values as succinctly as possible.
The complete mapping is as follows:

| Score Name   | Numerical value |
| ------------ |:---------------:|
| Condor       | -4              |
| Albatross    | -3              |
| Eagle        | -2              |
| Birdie       | -1              |
| Par          |  0              |
| Bogey        |  1              |
| Double Bogey |  2              |
| Triple Bogey |  3              |

In Python 2 we could use a magic formula like `hash(s+"V*? ")%9-4` (64-bit Python) or `hash(s+"N.H.")%9-4` (32-bit Python).
This program finds such magic strings using brute force.

## Customization
To specify a problem you have to edit the file config.h.
`MAGIC_LEN` determines the length of the magic string.
`MAGIC_MIN` and `MAGIC_MAX` determine the range of allowed characters in the magic string (end points included).
Use `typedef int64_t pyint;` for 64-bit Python and `typedef int32_t pyint;` for 32-bit Python.
`MODULUS` determines the modulus used in the magic formula.
This value should almost always be odd.
`PAIRS` is the table of the desired input / output pairs.

## Running the code
```
$ gcc -O3 prefixcruncher.c -o prefixcruncher.out
$ ./prefixcruncher.out
56 2a 3f 20  V*? 
```
