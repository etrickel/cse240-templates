

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "songinfo.h"

void printPassed(const char *format, ...) {
    va_list args;

    // Start red text
    printf("\x1b[32mTest PASSED ");

    // Initialize args to store all arguments after format
    va_start(args, format);

    // Print the formatted string with the variable arguments
    vprintf(format, args);

    // End red text
    printf("\x1b[0m");

    // Cleanup args
    va_end(args);
}

void printFailed(const char *format, ...) {
    va_list args;

    // Start red text
    printf("\x1b[31mTest Failed ");

    // Initialize args to store all arguments after format
    va_start(args, format);

    // Print the formatted string with the variable arguments
    vprintf(format, args);

    // End red text
    printf("\x1b[0m");

    // Cleanup args
    va_end(args);
}


/**
 * This unit test will test whether createArrayList initalizes the list
 */
bool testCreateArrayList(){
    char functionName[] = "createArrayList";
    ArrayList_of_Songs list;
    char testarr[] = "testarr";
    int initalCapacity1 = 10;
    list.songs = NULL;

    // CODE: ADD CREATE LIST
    

    if (list.songs == NULL){
        printFailed("for %s because list.songs is null\n", functionName);
        return false;
    }

    printPassed("for %s\n", functionName);
    return true;

}

bool testAddElement(){
    char functionName[] = "addElement";
    ArrayList_of_Songs list;
    
    int initalCapacity1 = 10;
    list.songs = NULL;
    createArrayList(&list, initalCapacity1);
    
    // CODE which ever array location you will test, create a dummy value to make sure that the add element overwrote it

    Song song1 = {"REPLACE_ME_WITH_GENRE", "REPLACE_ME_WITH_ARTIST", "REPLACE_ME_WITH_TITLE"};

    // CODE: add song1 to the list
    
    if ( /* CODE: USE strcmp to see if artist of first element of songs is not equal to song1.artist */){
        printFailed("for %s because list.songs[%d].artist == %s instead of '%s'\n", functionName, 0, list.songs[0].artist, song1.artist);
        return false;
    }

    printPassed("for %s\n", functionName);
    return true;

}

bool testLoadSongs_TestFirstValue(){
    char functionName[] = "loadSongs";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs list;
    
    int initalCapacity1 = 10;
    list.songs = NULL;
    
    createArrayList(&list, initalCapacity1);

    loadSongs(filename, &list);

    if (strcmp(list.songs[0].genre,"REPLACE_ME_WITH_FIRST_LINE_GENRE_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].genre == %s instead of '%s'\n", functionName, 0, list.songs[0].genre, "REPLACE_ME_WITH_FIRST_LINE_GENRE_FROM_SONGSMINOR");
        return false;
    }
    if (strcmp(list.songs[0].artist,"REPLACE_ME_WITH_FIRST_LINE_ARTIST_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].artist == %s instead of '%s'\n", functionName, 0, list.songs[0].artist, "REPLACE_ME_WITH_FIRST_LINE_ARTIST_FROM_SONGSMINOR");
        return false;
    }
    if (strcmp(list.songs[0].title,"REPLACE_ME_WITH_FIRST_LINE_TITLE_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].title == %s instead of '%s'\n", functionName, 0, list.songs[0].title, "REPLACE_ME_WITH_FIRST_LINE_ARTIST_FROM_SONGSMINOR");
        return false;
    }
    printPassed("for %s\n", functionName);
    return true;
}
bool testLoadSongs_TestLastValue(){
    char functionName[] = "loadSongs";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs list;
    
    int initalCapacity1 = 10;
    list.songs = NULL;
    createArrayList(&list, initalCapacity1);

    loadSongs(filename, &list);
   
    if (strcmp(list.songs[list.count-1].genre,"REPLACE_ME_WITH_LAST_LINE_GENRE_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].genre == %s instead of '%s'\n", functionName, list.count-1, list.songs[list.count-1].genre, "REPLACE_ME_WITH_LAST_LINE_GENRE_FROM_SONGSMINOR");
        return false;
    }
    if (strcmp(list.songs[list.count-1].artist,"REPLACE_ME_WITH_LAST_LAST_LINE_ARTIST_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].artist == %s instead of '%s'\n", functionName, list.count-1, list.songs[list.count-1].artist, "REPLACE_ME_WITH_LAST_LAST_LINE_ARTIST_FROM_SONGSMINOR");
        return false;
    }
    if (strcmp(list.songs[list.count-1].title,"REPLACE_ME_WITH_LAST_LAST_LINE_ARTIST_FROM_SONGSMINOR") != 0){
        printFailed("for %s because list.songs[%d].title == %s instead of '%s'\n", functionName, list.count-1, list.songs[list.count-1].title, "REPLACE_ME_WITH_LAST_LAST_LINE_ARTIST_FROM_SONGSMINOR");
        return false;
    }
    printf("%ld\n", list.count-1);
    printPassed("for %s\n", functionName);
    return true;
}

int main(int argc, char **argv){

    // The assert MACRO comes from assert.h and tests for true conditions 
    // if the condition is false, it will stop executing the program and return and error
    if (argc == 1){
        if (!testCreateArrayList()){
            return 130;
        }
        if (!testAddElement()){
            return 131;
        }
        if (!testLoadSongs_TestFirstValue()){
            return 132;
        }
        if (!testLoadSongs_TestLastValue()){
            return 133;
        }
        printf("All tests completed successfully!\n");
        return 0;
    }

    if (strcmp(argv[1], "testCreateArrayList") == 0 || strcmp(argv[1], "1") == 0){
        return testCreateArrayList() ? 0 : 129;
    }
    if (strcmp(argv[1], "testAddElement") == 0 || strcmp(argv[1], "2") == 0){
        return testAddElement() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadSongs_TestFirstValue") == 0 || strcmp(argv[1], "3") == 0){
        return testLoadSongs_TestFirstValue() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadSongs_TestLastValue") == 0 || strcmp(argv[1], "4") == 0){
        return testLoadSongs_TestLastValue() ? 0 : 129;
    }
    
    printf("Test case %s not found\n", argv[1]);

    return 0;
   
}
