#!/bin/bash
# kompilacja z opcjami i nadaniem nazwy plikowi wykonywalnemu
gcc --std=c99 pi_2.c -o pi_2 --pedantic -lm
gcc --std=c99 pi_1.c -o pi_1 --pedantic -lm
#uruchomienie
./pi_2
./pi_1