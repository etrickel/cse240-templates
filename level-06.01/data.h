#include<stdbool.h>

typedef struct Room {
    // CODE: Insert room fields here
} Room;

typedef struct Object {
    // CODE: Insert room fields here
} Object;

bool allocateObjectAndRoom(char * filename, Room ** roomsPP, Object ** objectPP);
void findMaxId(FILE *jsonFile, int * roomMaxId, int * objectMaxId);
bool loadJSON(char * filename, Room * rooms, Object * object);
struct Room loadRoom(FILE *jsonFile);
struct Object loadObject(FILE *jsonFile);

