#include <stdio.h>
#include <stdlib.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"

int main() {
    
    //initialisation du Labyrinthe
  int sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem;	
  char *monLab[4096];
  connectToServer("172.105.76.204", 1234 , "SarahLpb"); 
  waitForLabyrinth("TRAINING DONTMOVE", monLab, &sizeX, &sizeY);
  int turn = getLabyrinth(&lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
  
  //mon tour de jouer 
  
  t_return_code WoL;
  t_move *moveME;
  int number1,rotation1,X1,Y1;
  int insertion; // entre 0 et 3 
  t_insertion tuile;
  
		
	 	printLabyrinth();
	  	printf("%d, %d, %d, %d, %d, %d, %d, %d \n", sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem);
	  		printf("insertion merci\n");
	  		scanf("%d ", &insertion);
	  		switch(insertion){
	  		case 0 : tuile = INSERT_LINE_LEFT; 
	  			  break;
	  		case 1 : tuile = INSERT_LINE_RIGHT;
	  			   break;
	  		case 2 : tuile = INSERT_COLUMN_TOP;
	  			break;
	  		case 3 : tuile = INSERT_COLUMN_BOTTOM;
	  			break;
	  		}
	  		printf("number impaire qui indique le numéro de la ligne ou de la colonne où on insère la tuile\n");
	  		scanf("%d",&number1);
	  		printf("rotation qui indique de combien de quart de tour (entre 0 et 3)\n");
	  		scanf("%d",&rotation1);
	  		printf("x et y qui indique les coordonnées d’où se déplace le pion\n");
	  		scanf("%d %d", &X1, &Y1);
	  		moveME->insert = tuile;
	  		moveME->number = number1;
	  		moveME->rotation = rotation1;
	  		WoL = sendMove(moveME);
	  		printf("ici");
	  		if(WoL == NORMAL_MOVE)
	  		{
	  			int suc = 1;
	  		}
	  		if(WoL == WINNING_MOVE)
	  		{
	  			printf("Vous avez gagné");
	 
	  		}
	  		if(WoL == LOOSING_MOVE)
	  		{
	  			printf("Vous avez perdu");
	  		}
	  		
	  	
 

  
  closeConnection();
	
}
