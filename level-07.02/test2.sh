#!/usr/bin/env bash
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
printf "" > /tmp/INPUT

./${targetBinary} songsminor.csv < /tmp/INPUT > /tmp/OUTPUT


# we want to handle any amount of spaces between the genre name and the song count, so we will use " *"
EXPECTED_OUTPUT="Rap *57
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
[REPLACE_ME_WITH_GENRE_SPACE_STAR_VALUE]
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

