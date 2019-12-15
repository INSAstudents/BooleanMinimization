# Boolean Minimizer

This program, written in C++, features:
- the [Quine-McCluskey algorithm](https://en.wikipedia.org/wiki/Quine%E2%80%93McCluskey_algorithm)
- several heuristics to find a subset of prime implicants covering minterms
- [Petrick's method](https://en.wikipedia.org/wiki/Petrick%27s_method)

This program was developed for [differential cryptanalysis](https://en.wikipedia.org/wiki/Differential_cryptanalysis) purposes: some [S-boxes](https://en.wikipedia.org/wiki/S-box) are included (the Rijndael S-box used in AES, and the four S-boxes of Midori128), as well as functions to generate DDTs and minterms from them.

The code is based on [github.com/tempteamcode/QuineMcCluskey](https://github.com/tempteamcode/QuineMcCluskey/).