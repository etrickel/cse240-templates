

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "songinfo.h"
#include "genreinfo.h"

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
 * This unit test will test whether createArrayList initalizes the songList
 */
bool testCreateArrayList(){
    char functionName[] = "createArrayList";
    ArrayList_of_Songs songList;
    char testarr[] = "testarr";
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);
    
     if (songList.songs == NULL){
        printFailed("for %s because songList.songs is null\n", functionName);
        return false;
    }
    for (int x=0; x < initalCapacity1; x++){       
        songList.songs[x].artist = testarr;
    }
    for (int x=0; x < initalCapacity1; x++){
        if (strcmp(songList.songs[x].artist, testarr) != 0){
            printFailed("for %s because songList.songs[%d].artist == %s instead of '%s'\n", functionName, x, songList.songs[x].artist, testarr);
            return false;
        }
    }

    printPassed("for %s\n", functionName);
    return true;

}

bool testAddElement(){
    char functionName[] = "addElement";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);
    char testarr[] = "testarr";
    
    songList.songs[0].artist = strdup(testarr);

    Song song1 = {"Electric Crooner", "Putty", "Do not go there."};

    addElement(&songList, song1);
    
    if ( strcmp(songList.songs[0].artist, "Putty") != 0){
        printFailed("for %s because songList.songs[%d].artist == %s instead of '%s'\n", functionName, 0, songList.songs[0].artist, song1.artist);
    }

    printPassed("for %s\n", functionName);
    return true;

}

bool testLoadSongs_TestFirstValue(){
    char functionName[] = "loadSongs";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);

    loadSongs(filename, &songList);

    if (strcmp(songList.songs[0].genre,"Rap") != 0){
        printFailed("for %s because songList.songs[%d].genre == %s instead of '%s'\n", functionName, 0, songList.songs[0].genre, "Rap");
        return false;
    }
    if (strcmp(songList.songs[0].artist,"Post Malone") != 0){
        printFailed("for %s because songList.songs[%d].artist == %s instead of '%s'\n", functionName, 0, songList.songs[0].artist, "Post Malone");
        return false;
    }
    if (strcmp(songList.songs[0].title,"Too Young") != 0){
        printFailed("for %s because songList.songs[%d].title == %s instead of '%s'\n", functionName, 0, songList.songs[0].title, "Too Young");
        return false;
    }
    printPassed("for %s\n", functionName);
    return true;
}
bool testLoadSongs_TestLastValue(){
    char functionName[] = "loadSongs";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);

    loadSongs(filename, &songList);
   
    if (strcmp(songList.songs[songList.count-1].genre,"Rock") != 0){
        printFailed("for %s because songList.songs[%d].genre == %s instead of '%s'\n", functionName, 0, songList.songs[0].genre, "Rock");
        return false;
    }
    if (strcmp(songList.songs[songList.count-1].artist,"Red Hot Chili Peppers") != 0){
        printFailed("for %s because songList.songs[%d].artist == %s instead of '%s'\n", functionName, 0, songList.songs[0].artist, "Red Hot Chili Peppers");
        return false;
    }
    if (strcmp(songList.songs[songList.count-1].title,"Can't Stop") != 0){
        printFailed("for %s because songList.songs[%d].title == %s instead of '%s'\n", functionName, 0, songList.songs[0].title, "Can't Stop");
        return false;
    }
    //printf("%ld\n", songList.count-1);
    printPassed("for %s\n", functionName);
    return true;
}

// getUniqueGenres(ArrayList_of_Songs songList, char *** genreList, int * genreNameCount){
bool testGetUniqueGenres(){
    char functionName[] = "getUniqueGenres";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);
    loadSongs(filename, &songList);

    char ** genreList;
    int genreNameCount = 0;

    getUniqueGenres(songList, &genreList, &genreNameCount);
    char *expectedGenres[] = {"Rap","Dance","Pop","Rock","Hip-Hop","Electronic","Ska"};
    int sizeOfExpectedGenres = 7;

    if (genreNameCount != sizeOfExpectedGenres){
        printFailed("for %s because genreListSize is wrong, it is %d which is not equal to sizeOfExpectedGenres %d\n", functionName, genreNameCount, sizeOfExpectedGenres);
        return false; 
    }
    for (int x=0; x < genreNameCount; x++){        
            if (strcmp(genreList[x], expectedGenres[x]) != 0){
                printFailed("for %s because genreList[%d] == %s instead of '%s'\n", functionName, x, genreList[x], expectedGenres[x]);
                return false; 
            }     
    }
    printPassed("for %s\n", functionName);
    return true;
}

//void createLLFromList(LLNode ** uniqueGenreLLPtr, char ** genreList, int genreNameCount)
bool testCreateLLFromList(){
    char functionName[] = "createLLFromList";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);
    loadSongs(filename, &songList);

    char ** genreList;
    int genreNameCount = 0;

    getUniqueGenres(songList, &genreList, &genreNameCount);
    LLNode *head;
    createLLFromList(&head, genreList, genreNameCount);
    LLNode *current = head;
    int glIndex = 0;
    while(current != NULL){
        if (strcmp(current->gi.genreName, genreList[glIndex]) != 0){
            printFailed("for %s because for genre name in the Linked List '%s' does not match the genre array genreList[%d]=%s\n", functionName, current->gi.genreName, glIndex, genreList[glIndex]);
            return false; 
        }
        current = current->next;
        glIndex++;
    }
    
    printPassed("for %s\n", functionName);
    return true;
}

// countSongsInEachGenre(LLNode * head, ArrayList_of_Songs songList)
bool testCountSongsInEachGenre(){
    char functionName[] = "countSongsInEachGenre";
    char filename[] = "songsminor.csv";
    ArrayList_of_Songs songList;
    
    int initalCapacity1 = 10;
    songList.songs = NULL;
    createArrayList(&songList, initalCapacity1);
    loadSongs(filename, &songList);

    char ** genreList;
    int genreNameCount = 0;

    getUniqueGenres(songList, &genreList, &genreNameCount);
    LLNode *head;
    createLLFromList(&head, genreList, genreNameCount);
    LLNode *current = head;

    countSongsInEachGenre(head, songList);
    int expectedSongCount[] = {57,42,108,34,52,3,4};
    int i =0;
    while(current != NULL){
        //printf("%-10s %d\n", current->gi.genreName, current->gi.songCount);

        if (current->gi.songCount != expectedSongCount[i]){
            printFailed("for %s because for genre name in the Linked List '%s' the count is %d but the expected count is %d\n", functionName, current->gi.songCount, expectedSongCount[i]);
            return false; 
        }
        i++;
        current = current->next;
    }
    
    printPassed("for %s\n", functionName);
    return true;
}

int main(int argc, char **argv){

    // The assert MACRO comes from assert.h and tests for true conditions 
    // if the condition is false, it will stop executing the program and return and error
    if (argc == 1){
        if (!testCountSongsInEachGenre()){
            return 142;
        }
        if (!testCreateLLFromList()){
            return 141;
        }
        if (!testGetUniqueGenres()){
            return 140;
        }
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
    return 0;
   
}
