#include "clientAPI.h"
#include "labyrinthAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern int debug;

void clearscr(void) {
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) ||                 \
    (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#else
#error "OS not supported."
#endif
}

int main() {
  // initialisation du Labyrinthe
  int sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem;
  int *monLab =  monLab = malloc(sizeof(int));
  connectToServer("172.105.76.204", 1234, "Espion1");
  waitForLabyrinth("TRAINING RANDOM start=0 timeout=1000 display=debug", (int*)monLab, &sizeX, &sizeY);
  int turn = getLabyrinth(&lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
  int taille = sizeX*sizeY;
   monLab = realloc(monLab, sizeX*sizeY*sizeof(int));
   
  // mon tour de jouer
  t_return_code WoL = NORMAL_MOVE;
  t_move *moveME;
  moveME = malloc(sizeof(t_move));
  const char *commentaires = "merci lucas";
  commentaires = malloc(sizeof(char) * 101);

  // tour de l'adversaire
  t_move *moveYOU;
  moveYOU = malloc(sizeof(t_move));
  while (WoL == NORMAL_MOVE) {
    clearscr();
    printLabyrinth();

    // Tour de l'adversaire
    if (turn) {
      WoL = getMove(moveYOU);
      printf("Notation : 0 -> ligne gauche\n 1 -> ligne droite\n 2 -> colonne "
             "haut\n 3 -> colonne bas\n");
      printf("L'adversaire a cet endroit %d\n", moveYOU->insert);
      printf("La tuile de la ligne/colonne: %d a été déplacé\n",
             moveYOU->number);
      printf("La tuile a été placé dans le sens %d\n", moveYOU->rotation);
      printf("Les coordonnées du précedent déplacement sont : %d et %d\n",
             moveYOU->x, moveYOU->y);
    }
    // Tour du joueur
    else {
      // informations sur la partie en cours
      if (tileItem > 0) {
        printf("* La tuile présente le trésor numéro : %d\n", tileItem);
      } else {
        printf("* Il n'y a pas de trésor sur la prochaine tuile\n");
      }
      if (tileN > 0)
        printf("- Il y a un mur direction Nord\n");
      if (tileE > 0)
        printf("- Il y a un mur direction Est\n");
      if (tileS > 0)
        printf("- Il y a un mur direction Sud\n");
      if (tileW > 0)
        printf("- Il y a un mur direction Ouest\n");
      if (debug > 1)
        printf("valeur de lab %d \n", lab);

      // Paramètrage de sendMove();
      // TODO: Tester si le paramètre est bon !
      printf(
          "Insérer la tuile \n 0 -> ligne gauche \n 1 -> ligne droite \n 2 -> "
          "colonne haut \n 3 -> colonne bas\n> ");
      scanf("%u", &moveME->insert);
      printf("Entrez un nombre impaire qui indique le numéro de la ligne ou "
             "de la colonne où on insère la tuile\n> ");
      scanf("%d", &moveME->number);
      while(moveME->number%2 == 0 ){
      printf("Entrez un chiffre impair \n> ");
             scanf("%d", &moveME->number);
      }
      
      printf("Indiquez le nombre de rotation de quart de tour pour insérer la "
             "tuile (entre 0 et 3)\n> ");
      scanf("%d", &moveME->rotation);
      
      //Déplacements 
      
      	
      printf("Entrez la colonne ou vous voulez déplacer votre pion (nombre "
             "entre 1 et %d)\n> ",
             sizeX);
      scanf("%d", &moveME->x);
      moveME->x -= 1;
      printf("Entrez la ligne ou vous voulez déplacer votre pion (nombre " "entre 1 et %d)\n> ",  sizeY);
      scanf("%d", &moveME->y);
      moveME->y -= 1;
      
      
      //Fin de la partie
      WoL = sendMove(moveME);
      printf("le prochain trésor à trouver est le numéro %d\n",
             moveME->nextItem);
      // Commentaires
       srand(time(NULL));
  	int r = ( rand()%10);
	      if (r == 1) {
		      	if( r == 0)  commentaires = "Début";
		 	if(r == 1) commentaires = "Essaye encore";
		    	if(r == 2) commentaires = "Hahahah";
		 	if(r == 3) commentaires = "Ce n'est qu'un jeu après tout";
		      	if(r == 4) commentaires = "Ne t'inquiètes pas, tout va bien se passer";
		      	if(r == 5) commentaires = "Hihihi";
				sendComment(commentaires);
		}
	} //Fin boucle else
	    turn = (!turn);
	  
} //Fin boucle while
  
  	   //Conditions de sortie
  if (WoL == WINNING_MOVE){
  	if ( turn == 1) {
  		printf("le bot a gagné\n");
  	}
  	else {
  		printf("Vous avez gagné\n");
  	}
  }
  if(WoL == LOOSING_MOVE){
  	if ( turn == 0) {
  		printf("le bot a perdu\n");
  	}
  	else {
  		printf("Vous avez perdu \n");
    }
  }
   free(moveME);
   free(moveYOU);
   closeConnection();
  return 0;
}
