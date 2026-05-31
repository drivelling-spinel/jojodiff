# Text format for binary patches

_Both format and its support in JojoDiff are work in progress_

## Rationale

Simple, portable, versionable and comparable representation of difference between two binary files, where description of the changes being made can be easily included in form of comments.

## Examples

Patch for `TIMEGATE.EXE` - a protected mode DOS game from 1995.

      #original *timegate.org* new *timegate.new*
      EQL 0002883c
      MOD 71 bc
      EQL 00000006
      MOD 71 bc
      EQL 00000348
      MOD 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 22 b4 01 00 2c b6 01 00 8f b6 01 00 8f b6 01 00 e0 b6 01 00 16 b7 01 00 d8 b7 01 00 d8 b7 01 00 d8 b7 01 00 d8 b7 01 00 d8 b7 01 00 d8 b7 01 00 e1 b7 01 00 3b b8
      EQL 00009739
      MOD a0 19
      EQL 00011c59
      BKT 00000090
      MOD 07 10 a6 09 02 0c ac 02 00 07 10 b0 09 02 0c ac 02 00 07 10 ba 09 02 0c ac 02 00 07 10 c4 09 02 0c ac 02 00 07 10 ce 09 02 6c 17 01 00 07 10 d8 09 02 6c 17 01 00 07 10 e2 09 02 6c 17 01 00 07 10 ec 09 02 0c ac 02 00 07 10 f6 09 02 0c ac 02 00 07 10 00 0a 02 0c ac 02 00 07 10 0a 0a 02 0c ac 02 00 07 10 14 0a 02 0c ac 02 00 07 10 1e 0a 02 0c ac 02 00 07 10 28 0a 02 0c ac 02 00 07 10 32 0a 02 0c ac 02 00 07 10 3c 0a 02 6c 17 01
      EQL 00000501
      DEL 00000090
      EQL 00000704
      MOD 2e
      EQL 00009b62
      MOD 2e
      EQL 00002654
      MOD 2e
      EQL 0000a78e
      MOD 2e
      EQL 000011bb
      MOD 2c
      EQL 00000060
      MOD 26
      EQL 0000001c
      MOD 18
      EQL 00000037
      MOD 2e
      EQL 0000000c
      MOD 2d
      EQL 000316d5
      BKT 000001c4
      EQL 00000046
      DEL 0001c6df
      MOD 11 01 01 00 00 00 0c ac 02 00 1f 01 02 00 00 00 0c ac 02 00 1e 01 04 00 00 00 0c ac 02 00 20 01 08 00 00 00 0c ac 02 00 02 01 01 00 00 00 0c ac 02 00 04 01 02 00 00 00 0c ac 02 00 05 01 04 00 00 00 0c ac 02 00 03 01 08 00 00 00 0c ac 02 00 2f 01 02 00 00 00 6c 17 01
      EQL 00000022
      BKT 00001109
      MOD 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
      EQL 0000001a
      BKT 0001b412
      EQL 0001c525
      ESC

