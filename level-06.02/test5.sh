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
printf "[REPLACE_ME_WITH_COMMANDS_TO_RUN" > /tmp/INPUT

# test case sending input into program and saving output to /tmp/OUTPUT
./${targetBinary} < /tmp/INPUT > /tmp/OUTPUT


# HINT :::::::: if you use brackets in the EXPECTED, this will interfere with grep
#               you must escape the brackets like this \[5\]
EXPECTED_OUTPUT="[REPLACE_ME_WITH_EXPECTED_OUTPUT]
THIS CAN TEST MULTIPLE LINES OF OUTPUT
"

while read -r line; do

  if grep "$line" /tmp/OUTPUT > /dev/null ; then
    continue
  else
    
    echo "Missing '$line' in the output"
    
    echo ">>>>>>> Program's Output <<<<<<"
    cat /tmp/OUTPUT
    echo "Test Failed"
    
    exit 1
  fi

done <<< $EXPECTED_OUTPUT


printf "\033[38;5;10mTest Passed\033[0m\n"


