#!/bin/bash

set -eu

CC=clang

for i in `ls ./*.c` ; do
	$CC -o `echo $i | sed -e "s/\.c$//"`.out $i `pkg-config --libs --cflags gtk+-3.0`
done;

