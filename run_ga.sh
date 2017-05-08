#!/bin/sh

# For ga.c.

./kp.exe $1 $2 $3 $4 > $1-$2-$3-$4

echo 'grep ">> max_fitness" stdout > stdout.max'
grep ">> max_fitness" $1-$2-$3-$4 | tr -s " " " " | cut -f4,5 -d" " | cat -n > $1-$2-$3-$4.max

echo 'tail stdout > stdout.end'
tail $1-$2-$3-$4 > $1-$2-$3-$4.end
