#include <stdio.h>
#include <stdlib.h>
//#include "labyrinthAPI.h"
//#include "clientAPI.h"

int main() {
    int sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem;
   
 	//Variables pour mon tour 
	int number1;				
	int rotation1;
	int x1, y1; 			
	//int nextItem1;	//numéro du prochain trésor (entre 1 et 24/ 0 sinon)
	
//  t_return_code WoL;
  //char insertion[50];
  //t_move moveME;
  //Variables pour un tour de l'adversaire
  
 // t_move moveYOU;
  	
  char *monLab[50];
  
  connectToServer("172.105.76.204", 1234, "SarahLbp");
  
  waitForLabyrinth("TRAINING DONTMOVE", monLab, &sizeX, &sizeY);
  
  int turn;
  turn  = getLabyrinth(&lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
  
 /*	NORMAL_MOVE = 0,
	WINNING_MOVE = 1,
	LOOSING_MOVE = -1
*/
  
	while(turn){
			if(turn) {
		 	printLabyrinth();
		 	
		  	printf("%d, %d, %d, %d, %d, %d, %d, %d \n", sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem);
		  	
		  	/*printf("C'est à votre tour de jouer \n");
		  	
		  	printf("Rentrez l'endroit ou vous souhaitez insérer la tuile 'INSERT_COLUMN_<endroit à jouer> \n");
		  	
		  	scanf(" %s", insertion);
		  	
		  	printf("Rentrez dans l'ordre la ligne ou de la colonne ou vous voulez jouer \n");
		  	
		  	scanf("%d ", &number1);
		  	
			  	if(number1%2 > 0){
			  		WoL = LOOSING_MOVE;
			  		break;
			  	}
				  	printf("Rentrez dans la rotation de la case à effectuer\n");
				  	scanf("%d \n", &rotation1);
			
				  		// Remplissage de sendMove
				  		
				  	moveME.number = number1;
				  	moveME.rotation = rotation1;	
				  	WoL= sendMove(&moveME);
				  		
				  	
				  	printf("Les coordonnées de la nouvelle case sont %d  %d %d %d \n", tileN, tileE, tileS, tileW); 

				  	printf("Le prochain numéro du trésor est %d", nextItem1);
				  	
								if(tileItem > 0){
									printf("Il y a un trésor sur la case");
								}
				
			  	else{ // (turn == 0) c'est à l'adversaire de jouer
			  	
			  		WoL = sendMove(&moveYOU);
			  		if(WoL == LOOSING_MOVE){
			  			break;
			  			exit(0);
			  		}
			  
			  	}
			}
			
  }
  printf("FIN DU JEU \n");
  if ( WoL== WINNING_MOVE){
  	printf("Vous avez gagné\n");
  }
  if( WoL == LOOSING_MOVE){
  	printf("Vous avez perdu\n");
  }*/
  
  	}
  closeConnection();
}

}
