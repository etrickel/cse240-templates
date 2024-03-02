#! /usr/bin/env bash
if [[ -n "$1" ]]; then
    targetBinary=$1
else    
    targetBinary="main.bin"
fi 

# Black box tester 
########################################################
## DO NOT REMOVE $CFLAGS FROM COMPILE STATEMENT
if [[ $targetBinary != *"model"* ]]; then
    gcc -g -Wall -Werror main.c $CFLAGS -o "${targetBinary}"
fi 
# make clean && make
############################################################

printf "[REPLACE_ME_PICK_AN_ENGLISH_WORD_STARTING_WITH_TWO_OR_MORE_CONSONANTS]" > /tmp/INPUT 

./${targetBinary} < /tmp/INPUT > /tmp/OUTPUT

EXPECTED_OUTPUT="[REPLACE_ME_PIG_LATIN_TRANSLATION_OF_THE_WORD]"

if grep -q -i -E "$EXPECTED_OUTPUT" /tmp/OUTPUT; then
    echo "Found '$EXPECTED_OUTPUT'"    
else
    echo "Missing '$EXPECTED_OUTPUT' in the output"
    echo ">>>>>>> Program's Output <<<<<<"
    cat /tmp/OUTPUT
    echo "Test Failed"
    exit 1
fi 

printf "\033[38;5;10mTest Passed\033[0m\n"


