#!/bin/bash
vasm6502_oldstyle -dotdir -c02 -Fbin $1 #-o basename($1).bin &&
./tomem.py -f a.out > current.mem
