# JojoDiff - diff utility for binary files

`JDIFF` is a program that outputs the differences between two (binary) files.
`JPTCH` can then be used to reconstruct the second file from the first file.
For example:   
   `*jdiff* archive0000.tar archive0001.tar archive0001.jdf`   
   `*jptch* archive0000.tar archive0001.jdf archive0001b.tar`   
will create a file `archive0001b.tar` which is identical to `archive0001.tar`.

See original [readme.txt](readme.txt) for more information.

This fork provides DOS versions of `JDIFF` and `JPATCH` and also adds [text format](text.md) for storing binary patches.

Copyright © 2002-2011 Joris Heirbaut
Forked in 2026 by Ludicrous_peridot

