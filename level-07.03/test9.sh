#!/usr/bin/env bash
#! /usr/bin/env bash
if [[ -n "$1" ]]; then
    targetBinary=$1
else    
    targetBinary="main.bin"
fi 

# Black box tester 
########################################################
## DO NOT REMOVE $CFLAGS FROM COMPILE STATEMENT
#if [[ $targetBinary != *"model"* ]]; then
#    gcc -g -Wall -Werror main.c $CFLAGS -o "${targetBinary}"
#fi 
export CFLAGS="-fprofile-arcs -ftest-coverage" 
make clean && make
############################################################

# test case sending input into program and saving output to /tmp/OUTPUT
printf "REPLACE_ME_WITH_INPUT_THAT_WILL_EXERCISE_AS_MUCH_OF_THE_CODE_AS_POSSIBLE
q
" > /tmp/INPUT

./${targetBinary} songsminor.csv < /tmp/INPUT > /tmp/OUTPUT

./${targetBinary} missingfile.csv < /tmp/INPUT > /tmp/OUTPUT

echo "--------------------------"
# format is binary-sourcename
if [[ -f genreinfo.gcno ]]; then 
    gcov "genreinfo"
fi 
echo "--------------------------"
if [[ -f songinfo.gcno ]]; then 
    gcov "songinfo"
fi 
echo "--------------------------"
if [[ -f main.bin-main.gcno ]]; then
    gcov "main.bin-main.gcda"
fi 

# we want to handle any amount of spaces between the genre name and the song count, so we will use " *"



printf "\033[38;5;10mTest Passed\033[0m\n"
