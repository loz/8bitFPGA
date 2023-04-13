#!/bin/bash
vasm6502_oldstyle -dotdir -Fbin $1 #-o basename($1).bin
./tomem.py -f a.out > a.mem
