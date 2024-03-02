#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "songinfo.h"
#include "genreinfo.h"

void generateUniqueGenresLL(LLNode ** headPtr, ArrayList_of_Songs songList){
    // commented out to aid compiling eaarly
    // CODE: char ** genreList;
    // CODE: int genreNameCount = 0;
    
}

void getUniqueGenres(ArrayList_of_Songs songList, char *** genreListPtr, int * genreNameCount){
    int capacity = 2;       // do not change initial capacity.
    const int GROW_BY = 2;  // use GROW_BY for the adjustment to capacity
                            // **EXAMPLE:**
                            //    capacity += GROW_BY;
                            //    genreList = realloc(genreList, sizeof(char *) * capacity);
                            
    char ** genreList; // use this to build genreList then the function sets it to the triple pointer at the end 

    // CODE: INSERT genreList creation code here
    
    *genreListPtr = genreList; // setting the address of genreListPtr so that it will be returned to calling function
}   

void createLLFromList(LLNode ** headPP, char ** genreList, int genreNameCount){
     // commented out to aid compiling eaarly
    *headPP = NULL; // b/c new LL, we want to start with head = NULL.
        
    // CODE: INSERT code that creates the linked list, keep the list in the same order as the genreList entries    
        
}

void countSongsInEachGenre(LLNode * head, ArrayList_of_Songs songList){
    
}

void printGenres(LLNode * head){
    
}

