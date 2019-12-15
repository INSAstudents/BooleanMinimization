# Boolean Minimization

The goal of our project is to find minimal reductions of boolean tables generated for [differential cryptanalysis](https://en.wikipedia.org/wiki/Differential_cryptanalysis). These tables contain minterms extracted from the DDTs of several [S-boxes](https://en.wikipedia.org/wiki/S-box) (the Rijndael S-box used in AES, and the four S-boxes of Midori128).

This repository is organized in several folders:
- "src" contains our boolean minimizer's source code (which contains implementations of the [Quine-McCluskey algorithm](https://en.wikipedia.org/wiki/Quine%E2%80%93McCluskey_algorithm), [Petrick's method](https://en.wikipedia.org/wiki/Petrick%27s_method), and some heuristics)
- "test" contains another program to check the validity of the outputs
- "results" contains the best reductions found and some related information
