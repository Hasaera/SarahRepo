#include <stdio.h>
#include <stdlib.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"

//mdp git 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

int main() {
    
    //initialisation du Labyrinthe
  int sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem;	
  char *monLab[715];
  connectToServer("172.105.76.204", 1234 , "Sarahcmoi"); 
  waitForLabyrinth("TRAINING DONTMOVE start=0 timeout=1000 ", monLab, &sizeX, &sizeY);
  int turn = getLabyrinth(&lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
  
  //mon tour de jouer 
  t_return_code WoL = NORMAL_MOVE;
  t_move *moveME;
  moveME = malloc(sizeof(t_move));
  int number1,rotation1,X1,Y1;
  int insertion; // entre 0 et 3 
  t_insertion tuile;
  int comments = 4;
  char commentaires[500];
  
  //tour de l'adversaire
  t_move *moveYOU; //pourquoi ça ne marche pas si c'est un pointeur 
  moveYOU = malloc(sizeof(t_move)); 
  
	while(WoL == NORMAL_MOVE){
		if(turn == 0 ){
	 	printLabyrinth();
	 	
	 		//informations sur la partie en cours 
		 	if(tileItem > 0){
		 		printf("la tuile présente le trésor numéro : %d \n", tileItem);
		 	}
		 	else{
		 		printf("il n'y a pas de trésor sur la prochaine tuile \n");
		 	}
		 	if( tileN>0 ) printf("il y a un mur direction Nord\n");
		 	if( tileE>0 ) printf("il y a un mur direction Est\n");
		 	if( tileS>0 ) printf("il y a un mur direction Sud\n");
		 	if( tileW>0 ) printf("il y a un mur direction Ouest\n");
	  		printf("valeur de lab %d \n", lab);
	  		
	  		//Paramètrage de getMove();
	  		printf("Insérer la tuile \n 0 -> ligne gauche \n 1-> ligne droite \n 2-> colonne haut \n 3->colonne bas  \n ");
	  		scanf("%d",&insertion );
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
	  		printf("Entrez un nombre impaire qui indique le numéro de la ligne ou de la colonne où on insère la tuile\n");
	  		scanf("%d", &number1 );
	  		printf("Indiquez le nombre de rotation de quart de tour pour insérer la tuile  (entre 0 et 3)\n");
	  		scanf("%d", &rotation1 );
	  		printf("Entrez la ligne ou vous voulez déplacer votre pion (nombre entre 1 et %d) \n", sizeX);
	  		scanf("%d", &X1);
	  		printf("Entrez la colonne ou vous voulez déplacer votre pion(nombre entre 1 et %d) \n", sizeY);
	  		scanf("%d", &Y1);
	  		moveME->insert = tuile;
	  		moveME->number = number1;
	  		moveME->rotation = rotation1;
	  		moveME->x = X1;
	  		moveME->y = Y1;
	  		WoL = sendMove(moveME);
	  		printf("le prochain trésor à trouver est le numéro %d\n", moveME->nextItem);

			//Commentaires
			printf("Voulez vous envoyer un commentaire \n 0 pour oui et 1 pour non \n");
			scanf("%d", &comments);
			if(comments == 0){
				printf("Entrez le commentaire à envoyer\n");
				scanf("%s", commentaires);
				sendComment(commentaires);
			}
	  		
	  		//condition de sortie
	  		if(WoL == NORMAL_MOVE)
	  		{
	  			turn = (!turn) ;

	  		}
	  		if(WoL == WINNING_MOVE)
	  		{
	  			printf("Vous avez gagné\n");
	  			closeConnection();
	 
	  		}
	  		if(WoL == LOOSING_MOVE)
	  		{
	  			printf("Vous avez perdu\n");
	  			closeConnection();
	  		}
	  		
	  	}
	  	
	  	//tour de l'adversaire
	  	if( turn == 1){
	  		printLabyrinth();
	  		WoL = getMove(moveYOU);
	  		printf("Notation : 0 -> ligne gauche \n 1-> ligne droite \n 2-> colonne haut \n 3->colonne bas \n");
	  		printf("l'adversaire a cet endroit %d  \n", moveYOU->insert );
	  		printf("la tuile de la ligne/colonne: %d a été déplacé \n", moveYOU->number );
	  		printf("la tuile a été placé dans le sens %d \n", moveYOU->rotation);
	  		printf("les coordonnées du précedent déplacement sont : %d et %d \n", moveYOU->x, moveYOU->y);	 	
	  		if(WoL == NORMAL_MOVE)
	  		{
	  			int suc = 1;
	  			turn = (!turn);
	  		}
	  		if(WoL == WINNING_MOVE)
	  		{
	  			printf("Vous avez gagné");
	  			  closeConnection();
	  		}
	  		if(WoL == LOOSING_MOVE)
	  		{
	  			printf("Vous avez perdu");
	  			  closeConnection();
	  		}
	  	}


  	}
	closeConnection;
}
