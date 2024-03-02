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
REPLACE_ME_WITH_INPUT_THAT_WILL_CAUSE_DESIRED_OUTPUT
q
" > /tmp/INPUT

./${targetBinary} songsminor.csv < /tmp/INPUT > /tmp/OUTPUT


# we want to handle any amount of spaces between the fields and the next rows
# So we use ".*" between the literal values
# Using -Eziq the EXPECTED_OUTPUT must be a single line
EXPECTED_OUTPUT="REPLACE_ME_WITH_SOME_LINES_EXPECTED_IN_OUTPUT"


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
