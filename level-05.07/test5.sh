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

printf "week" > /tmp/INPUT 

./${targetBinary} < /tmp/INPUT > /tmp/OUTPUT

EXPECTED_OUTPUT=""

cat /tmp/OUTPUT | tr -d "\n" | od -An -tx1 > /tmp/hexversion

# CODE: COPY LINE creating /tmp/hexversion

if # CODE: COPY GREP FROM REQUIREMENTS DOCUMENT 
then
    
    echo "Found non-printable characters in output"
    echo ">>>>>>> non-printable character information <<<<<<"
    
    # this code loops over each hex value, converts it to an integer value, 
    # checks if between 32 and 126, and prints out either
    # the character if printable or hex value if not
    for x in $(cat /tmp/hexversion ); do val=$(printf "\n%d\n" 0x$x); if (( val >= 32 && val <= 126 )); then printf "\x$x"; else printf "\033[31m %02x \033[0m" $val ;fi; done
    
    echo ""
    
    echo ">>>>>>> Program's Output <<<<<<"
    cat /tmp/OUTPUT
    echo "Test Failed"
    exit 1
else
    echo "Did not find any non-printable characters."    

fi 

printf "\033[38;5;10mTest Passed\033[0m\n"


