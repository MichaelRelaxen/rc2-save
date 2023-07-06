#!/bin/bash
s() {
    powerpc64-linux-gnu-as -o $1.o -mregnames -mcell -be -o out/$1.o src/$1.s
    powerpc64-linux-gnu-ld --oformat=binary -o out/$1.bin out/$1.o
    rm out/$1.o
    echo "0x$2: $1.bin" >> out/patch.txt
}

c() {
    powerpc64-linux-gnu-gcc -mcpu=cell -mbig -m32 -Wl,--oformat=binary,-Ttext=$2 -nostdlib -O2 -o out/$1.bin src/$1.c
    echo "0x$2: $1.bin" >> out/patch.txt
}

p() {
    echo "0x$1: 0x$2" >> out/patch.txt
}

name="rc2-save"
friendly_name="Savefile Helper"
author="king_dedede"
version="1.0"

rm out/patch.txt
echo "#- name: $friendly_name" >> out/patch.txt
echo "#- author: $author" >> out/patch.txt
echo "#- version: $version" >> out/patch.txt

c patch1 10cd11c
p b086b0 490cd11f

mv out $name
zip $name.zip -r $name
mv $name out