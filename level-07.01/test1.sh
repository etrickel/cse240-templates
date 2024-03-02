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
printf "" > /tmp/INPUT

./${targetBinary} songsminor.csv < /tmp/INPUT > /tmp/OUTPUT

EXPECTED_OUTPUT="REPLACE_ME_WITH_SONG1.*REPLACE_ME_WITH_SONG2.*REPLACE_ME_WITH_SONG3"

if grep -Eziq "$EXPECTED_OUTPUT" /tmp/OUTPUT; then
    echo "Found '$EXPECTED_OUTPUT'"    
else
    echo "Missing '$EXPECTED_OUTPUT' in the output"
    echo ">>>>>>> Program's Output <<<<<<"
    cat /tmp/OUTPUT
    echo "Test Failed"
    exit 1
fi 


printf "\033[38;5;10mTest Passed\033[0m\n"


