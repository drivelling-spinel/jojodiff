# JojoDiff - diff utility for binary files

`JDIFF` is a program that outputs the differences between two (binary) files.
`JPTCH` can then be used to reconstruct the second file from the first file.
For example:   
   `*jdiff* archive0000.tar archive0001.tar archive0001.jdf`   
   `*jptch* archive0000.tar archive0001.jdf archive0001b.tar`   
will create a file `archive0001b.tar` which is identical to `archive0001.tar`.

See original [readme.txt](readme.txt) for more information.

This fork provides DOS versions of `JDIFF` and `JPATCH` and also adds text format for saving patch files.
Executables are renamed to `jdiffT` and `jpatchT` respectively (_casing for emphasis only_) to differentiate from the original ones.
While `jdifft` supports argument `-t` for saving patches in text format, 
`jpatcht` capability to read and apply them is work in progerss and currently they are unsupported.

The code is offered with support for Watcom C++ compiler and has been validated wtih Open Watcom 1.9 in FreeDOS,
no binaries built with Open Watcom are provided due to licensing conflict.

See `makedmc.cmd` for instructions on cross-compiling `JPATCH` with Digital Mars C++ Compiler from Windows.

Copyright © 2002-2011 Joris Heirbaut   
Forked in 2026 by Ludicrous_peridot

