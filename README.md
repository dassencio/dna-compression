[![Build Status](https://travis-ci.org/dassencio/dna-compression.svg?branch=master)](https://travis-ci.org/dassencio/dna-compression/)

Description
===========

A simple example showing how DNA data can be efficiently stored in C++.


License
=======

All code from this project is licensed under the GPLv3. See `LICENSE` for more.


Instructions
============

To compile the project, create a subdirectory called `build`, cd into it and run
the following commands in sequence:

	cmake ..
	make

This will generate an executable called `dna`. This executable runs a test for
a randomly generated DNA sequence, i.e., it generates a DNA sequence first,
compresses it into a sequence of bits, then recovers it back as a sequence of
characters. If the recovered sequence differs from the original one, the test
fails.


Contributors & Contact Information
==================================

Diego Assencio / diego@assencio.com
