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
make clean && make
############################################################

# test case sending input into program and saving output to /tmp/OUTPUT
printf "REPLACE_ME_WITH_INPUT_THAT_WILL_CAUSE_DESIRED_OUTPUT
q
" > /tmp/INPUT

./${targetBinary} songsminor.csv < /tmp/INPUT > /tmp/OUTPUT


# we want to handle any amount of spaces between the genre name and the song count, so we will use " *"
EXPECTED_OUTPUT="Rap *57.*Dance *42.*Pop *108.*Rock *34.*Hip-Hop *52.*Electronic *3.*Ska *4"

if grep -Eziq "$EXPECTED_OUTPUT" /tmp/OUTPUT; then
    echo "Found expected output"
else
    printf "\033[38;5;1mMissing '$EXPECTED_OUTPUT' in the output\n\033[0m"    
    echo ">>>>>>> Program's Output <<<<<<"
    cat /tmp/OUTPUT
    printf "\033[38;5;1mTest Failed\033[0m\n"    
    exit 1
fi 


printf "\033[38;5;10mTest Passed\033[0m\n"
