#!/bin/bash

echo -n "Creating asm..."
for i in input/*;
do
    name=$(echo $i | cut -c7- | rev | cut -c6- | rev)
    ./alfa $i output/$name.asm
done
echo " [OK]"
echo -n "Compiling our asm..."
for i in output/*;
do
    name=$(echo $i | cut -c8- | rev | cut -c5- | rev)
    nasm -g -o compiled/$name.o -f elf32 $i
    gcc -g -m32 -o compiled/$name compiled/$name.o lib/alfalib.o
    rm compiled/$name.o
done
echo " [OK]"
