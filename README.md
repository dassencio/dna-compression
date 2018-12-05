[![Build Status](https://api.travis-ci.com/dassencio/dna-compression.svg?branch=master)](https://travis-ci.com/dassencio/dna-compression)

# Description

This project is a simple example which shows how DNA data can be efficiently
stored in C++. It implements the algorithm described
[here](http://diego.assencio.com/?index=79a3928625303f53593f2112ebd8ac86).

# License

All code from this project is licensed under the GPLv3. See the
[`LICENSE`](https://github.com/dassencio/dna-compression/tree/master/LICENSE)
file for more information.

# Usage instructions

To compile the project, create a subdirectory called `build` and run the
following commands inside it:

    cmake ..
    make

This will generate an executable called `dna`. This executable runs a test for
a randomly generated DNA sequence, i.e., it generates a DNA sequence first,
compresses it into a sequence of bits, then recovers it back as a sequence of
characters. If the recovered sequence differs from the original one, the test
fails.

# Contributors & contact information

Diego Assencio / diego@assencio.com
