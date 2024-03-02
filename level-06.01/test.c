
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "data.h"

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
 * 
*/
bool testRoomValues(const char * functionName, Room expectedRoom, Room targetRoom){    

    if (expectedRoom.id != targetRoom.id){
        printFailed("for %s with the world.json file because rooms[%d].id == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.id, targetRoom.id);
        return false;
    }
    if (strcmp(expectedRoom.name, targetRoom.name) != 0){
        printFailed("for %s with the world.json file because rooms[%d].name == %s instead of '%s'\n", functionName, targetRoom.id,expectedRoom.name, targetRoom.name);
        return false;
    }
    if (strcmp(expectedRoom.description, targetRoom.description) != 0){
        printFailed("for %s with the world.json file because rooms[%d].name == %s instead of '%s'\n", functionName, targetRoom.id,expectedRoom.description, targetRoom.description);
        return false;
    }
    if (expectedRoom.north != targetRoom.north){
        printFailed("for %s with the world.json file because rooms[%d].north == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.north, targetRoom.north);
        return false;
    }
    if (expectedRoom.south != targetRoom.south){
        printFailed("for %s with the world.json file because rooms[%d].south == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.south, targetRoom.south);
        return false;
    }
    if (expectedRoom.east != targetRoom.east){
        printFailed("for %s with the world.json file because rooms[%d].east == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.east, targetRoom.east);
        return false;
    }
    if (expectedRoom.west != targetRoom.west){
        printFailed("for %s with the world.json file because rooms[%d].west == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.west, targetRoom.west);
        return false;
    }
    if (expectedRoom.object != targetRoom.object){
        printFailed("for %s with the world.json file because rooms[%d].object == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.object, targetRoom.object);
        return false;
    }
    if (expectedRoom.starting != targetRoom.starting){
        printFailed("for %s with the world.json file because rooms[%d].starting == %d instead of %d\n", functionName,targetRoom.id,expectedRoom.starting, targetRoom.starting);
        return false;
    }
    return true;
}

bool testObjectValues(const char * functionName, Object expectedObject, Object targetObject){
   
    if (expectedObject.id != targetObject.id){
        printFailed("for %s with the world.json file because rooms[%d].id == %d instead of %d\n", functionName,targetObject.id,expectedObject.id, targetObject.id);
        return false;
    }
    if (strcmp(expectedObject.name, targetObject.name) != 0){
        printFailed("for %s with the world.json file because rooms[%d].name == %s instead of '%s'\n", functionName, targetObject.id,expectedObject.name, targetObject.name);
        return false;
    }
    if (strcmp(expectedObject.description, targetObject.description) != 0){
        printFailed("for %s with the world.json file because rooms[%d].name == %s instead of '%s'\n", functionName, targetObject.id,expectedObject.description, targetObject.description);
        return false;
    }
    return true;
}


/**
 * This unit test will test whether testFindMaxId is operating correctly in data.c program
 * It should open a json file and pass the file pointer to it
 * Then check if the values are correct
 * If they are correct it should return true otherwise it should return false.
*/
bool testFindMaxId(){
    const char * functionName = "findMaxId";
    printf("Testing %s\n", functionName);
    
    // ADD test code

    if (maxRoomId != REPLACE_ME_WITH_MAX_ROOM_ID){
        printFailed("for %s because found wrong max room Id found %d was expecting 359\n", functionName, maxRoomId);
        return false;
    }

    if (maxObjectId != REPLACE_ME_WITH_MAX_OBJECT_ID){
        printFailed("for %s because found wrong max object Id found %d was expecting 378\n", functionName, maxObjectId);
        return false;
    }
    printPassed("for %s\n", functionName);
    return true; 
}


/**
 * This unit test will test that the allocateObjectAndRoom function allocates
 * the memory for the rooms and objects heap-based arrays. 
 * It tests if the rooms pointer is null and whether it has the correct size 
*/
bool testAllocateObjectAndRoom_Rooms(){
    printf("Testing allocateObjectAndRoom\n");

    Room *rooms;
    Object * objects;

    allocateObjectAndRoom("world.json", &rooms, &objects);
    if (rooms[359].id == -1 && rooms[359].north == -1){
        printPassed("for testAllocateObjectAndRoom_Rooms\n");
        return true;
    }   
    
    printFailed("for testAllocateObjectAndRoom_Rooms the room values did not equal -1 rooms[359].id=%d, rooms[359].north=%d \n", rooms[359].id, rooms[359].north);
    return false; 
}

/**
 * This unit test will test that the allocateObjectAndRoom function allocates
 * the memory for the objects and objects heap-based arrays. 
 * It tests if the objects pointer is null and whether it has the correct size 
*/
bool testAllocateObjectAndRoom_Objects(){
    printf("Testing allocateObjectAndRoom\n");
    Room *rooms;
    Object * objects;

    allocateObjectAndRoom("world.json", &rooms, &objects);
    if (objects[378].id == -1 ){
        printPassed("for testAllocateObjectAndRoom_Objects\n");
        return true;
    }   
    printFailed("for allocateObjectAndRoom because values for object[378].id is equal to %d instead of -1\n", objects[378].id);
    
    return false; 
}

/**
 * This unit test verifies that loadRoom function creates a Room struct
 * with the appropriate values, it creates a test file with just a Room
 * value in the JSON format and then uses loadRoom to read it in  
*/
bool testLoadRoom(){
    const char * functionName = "loadRoom";
    printf("Testing %s\n", functionName);
    const char *testInput =  " \
    { \n\
	    \"id\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"name\": \"REPLACE_WITH_NAME_TO_TEST\",\n\
	    \"description\": \"REPLACE_WITH_DESCRIPTION_TO_TEST\",\n\
	    \"south\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"north\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"east\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"west\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"object\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"starting\": REPLACE_WITH_STARTING_VALUE_TO_TEST\n\
	}\n\
    END\n";

    FILE *tmpf = tmpfile();
    if (tmpf == NULL) {
        perror("Unable to create temporary file");
        return false;
    }

    // Write \"hihi\" to the temporary file
    fprintf(tmpf,"%s", testInput);
    
    rewind(tmpf);

    struct Room r = loadRoom(tmpf);
    
    char line[100];
    fgets(line, sizeof(line), tmpf);
    
    fclose(tmpf);

    if (strstr(line,"END")){
        // great going perfect
    } else {
        printFailed("for Test %s because the current line in the file pointer did not contain the closing character instead it contained '%s'\n", functionName, line);
        return false;
    }
    
    Room targetRoom1 = {/* REPLACE_ME_WITH_THE_SAME_ROOM_DATA_PROVIDED_ABOVE  */};
    if (!testRoomValues(functionName, r, targetRoom1 )) {
        return false;
    }
    
    printPassed("for %s\n", functionName);
    return true; 
}

/**
 * This unit test verifies that loadObject function creates a Object struct
 * with the appropriate values, it creates a test file with just a Object
 * value in the JSON format and then uses loadObject to read it in  
*/
bool testLoadObject(){
    char * functionName = "loadObjects";
    printf("Testing %s\n", functionName);
    const char *testInput =  " \
    { \n\
	    \"id\": REPLACE_WITH_ID_TO_TEST,\n\
	    \"name\": \"REPLACE_ME_WITH_NAME\",\n\
	    \"description\": \"REPLACE_ME_WITH_DESCRIPTION\"\n\
	}\n\
    END\n";
    
    FILE *tmpf = tmpfile();
    if (tmpf == NULL) {
        perror("Unable to create temporary file");
        return false;
    }

    // Write to the temporary file
    fprintf(tmpf,"%s", testInput);
    
    rewind(tmpf);

    struct Object o = loadObject(tmpf);
    
    char line[100];
    fgets(line, sizeof(line), tmpf);
    
    fclose(tmpf);

    if (strstr(line,"END")){
        // great going perfect
    } else {
        printFailed("for Test %s because the current line in the file pointer did not contain the closing character instead it contained '%s'\n", functionName, line);
        return false;
    }
    
    Object targetObject1 = {/* REPLACE_ME_WITH_OBJECT_DATA_LOADED_TO_FILE */};
    if (!testObjectValues(functionName, o, targetObject1)) {
        return false;
    }
    printPassed("for %s\n", functionName);
    return true; 
}

/**
 * This unit test verifies that loadJSON function loads the JSON
 * from the miniworld.json and then spot checks the rooms and
 * objects values to be sure they match what is in the file 
*/
bool testLoadJSON_Small(){
    
    const char * functionName = "loadJSON";
    printf("Testing %s using miniworld.json\n", functionName);
    
    // CODE: add test code
    
    Room targetRoom1 = {/* Add room info for room 3 from miniworld.json */};
    if (!testRoomValues(functionName, rooms[3], targetRoom1 )) {
        return false;
    }
    printPassed("for testLoadJSON_Small\n");
    return true; 

}

/**
 * This unit test verifies that loadJSON function loads the JSON
 * from the world.json and then spot checks the rooms and
 * objects values to be sure they match what is in the file 
*/
bool testLoadJSON_Large(){
    const char * functionName = "loadJSON";
    printf("Testing %s using world.json\n", functionName);
    
    // CODE : add test
    
    Room targetRoom1 = {/* REPLACE_ME_WITH_ROOM_14_INFO */};
    if (!testRoomValues(functionName, rooms[14], targetRoom1 )) {
        return false;
    }

    Room targetRoom2 = {/*REPLACE_ME_WITH_ROOM_359_INFO*/};
    
    if (!testRoomValues(functionName, rooms[359], targetRoom2 )) {
        return false;
    }    
    Object targetObject1 = {/*REPLACE_ME_WITH_OBJECT_378_INFO*/};
    if (!testObjectValues(functionName, objects[378], targetObject1)) {
        return false;
    }
    
    printPassed("for %s\n", functionName);

    return true; 
     
}

/**
 * The test provides a non-existant filename to allocateObjectAndRoom and verifies
 * the function returns false.
*/
bool testLoadJSON_MissingFile(){
    const char * functionName = "loadJSON";
    printf("Testing %s using beep.json\n", functionName);
    
    // CODE: add code for test

    if (result){
        printFailed("for %s because it returned true from the function but the non-existing file should have caused a false \n", functionName);
        return false;
    } else {
        printPassed("for %s \n", functionName);
        return true;
    }    
     
}

/**********************
 * DO NOT MODIFY MAIN
***********************/
int main(int argc, char **argv){

    
    if (argc == 1){
        testFindMaxId(); 
        testAllocateObjectAndRoom_Rooms(); 
        testAllocateObjectAndRoom_Objects(); 
        testLoadRoom();
        testLoadObject();
        testLoadJSON_Small();
        testLoadJSON_Large();
        testLoadJSON_MissingFile();
        printf("All tests completed successfully!\n");
        return 0;
    }

    if (strcmp(argv[1], "testFindMaxId") == 0 || strcmp(argv[1], "1") == 0){
        return testFindMaxId() ? 0 : 129;
    }
    if (strcmp(argv[1], "testAllocateObjectAndRoom_Rooms") == 0 || strcmp(argv[1], "2") == 0){
        return testAllocateObjectAndRoom_Rooms() ? 0 : 129;
    }
    if (strcmp(argv[1], "testAllocateObjectAndRoom_Objects") == 0 || strcmp(argv[1], "3") == 0){
        return testAllocateObjectAndRoom_Objects() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadRoom") == 0 || strcmp(argv[1], "4") == 0){
        return testLoadRoom() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadObject") == 0 || strcmp(argv[1], "5") == 0){
        return testLoadObject() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadJSON_Small") == 0 || strcmp(argv[1], "6") == 0){
        return testLoadJSON_Small() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadJSON_Large") == 0 || strcmp(argv[1], "7") == 0){
        return testLoadJSON_Large() ? 0 : 129;
    }
    if (strcmp(argv[1], "testLoadJSON_MissingFile") == 0 || strcmp(argv[1], "8") == 0){
        return testLoadJSON_MissingFile() ? 0 : 129;
    }
    
    return 0;
   
}