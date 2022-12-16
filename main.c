#include <stdio.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"

int main(){
    int sizeX;
    int sizeY;
    char monLabyrinth[50];
    int lab;
    int tileN;
    int tileE;
    int tileS;
    int tileW;
    int tileItem;

    connectToServer("172.105.76.204", 1234,"SarahLpb");
    waitForLabyrinth("TRAINING DONTMOVE",monLabyrinth,&sizeX,&sizeY);
    int turn= getLabyrinth(&lab,&tileN,&tileE,&tileS, &tileW,&tileItem);
 
    printLabyrinth();
    closeConnection();

    
    return 0;
}
