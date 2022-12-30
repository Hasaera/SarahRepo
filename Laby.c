#include "clientAPI.h"
#include "labyrinthAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZEX 9
#define SIZEY 10
#define MIN(x, y) (x < y ? x : y)

typedef struct{
	int x;
	int y;
}t_point;

typedef struct {
	int N,S,W,E;
	int Item;
	t_point pos;
	int val;
}t_tuile;


int remplir_lab(int* lab, int X, int Y ,t_tuile Labyrinthe[SIZEX][SIZEY]){ //remplit le tab de tuiles 

	int i = 0;
	int j = 0;
	
	for(i = 0 ; i < SIZEX ; i++) {
		for(j = 0 ; j < SIZEY ; j++){
				Labyrinthe[i][j].N = lab[j];
				Labyrinthe[i][j].S = lab[j];
				Labyrinthe[i][j].W = lab[j];
				Labyrinthe[i][j].E = lab[j];
				Labyrinthe[i][j].Item = lab[j];
				Labyrinthe[i][j].pos.x = i;
		}		Labyrinthe[i][j].pos.x = j;
	}
	return 0;
 }
 
int whereWalls(t_tuile Labyrinthe[SIZEX][SIZEY], int x, int y , t_point tresor){ //indique la case accessiblela plus proche du trésor  
 	// TODO revoir les coordonnées vérifiées
 
 	int m = 0 ;
 	int d = 0;
	  if (x + 1 < SIZEX){
	    if (Labyrinthe[x+1][y].W == 0)
	      	d = distance(tresor, Labyrinthe[x+1][y].pos);
	     m = MIN(m,d); //EST
	     }
	  if (x > 0){
	    if (Labyrinthe[x-1][y].E == 0)
	      d = distance(tresor, Labyrinthe[x-1][y].pos);
	      m = MIN(m,d);} //WEST
	  if (y > 0){
	    if (Labyrinthe[x][y-1].S == 0)
	      d = distance(tresor, Labyrinthe[x][y-1].pos);
	      m = MIN(m,d); }  //NORD
	  if (y + 1 < SIZEY){
	    if (Labyrinthe[x][y+1].N > 0)
	      d = distance(tresor, Labyrinthe[x][y+1].pos);
	     m = MIN(m,d);}  //SUD
	      
	  return m;
 
 }
 
 //fonction qui parcourt le tableau de tuiles et indique sur quelle tuile se trouve le trésor 
int find(t_tuile Labyrinthe[SIZEX][SIZEY], int numTresor, t_point *cell){
	
	for(int i = 0 ; i < SIZEX ; i++) {
		for(int j = 0 ; j < SIZEY ; j++){
			if(Labyrinthe[i][j].Item == numTresor){
				cell->x = i;
				cell->y = j;
				return 1; // le trésor est dans le lab
			}
		}
	}
	return 0; // retourne 0 si le trésor n'est pas dans le labyrinthe 
}

int move(t_point position, t_move moveME){ //met à jour les déplacements à envoyer 
	moveME.x = position.x;
	moveME.y = position.y;
	moveME.rotation = 0; 
	return 0;
}

t_point deplacement(t_tuile Labyrinthe[SIZEX][SIZEY], t_point tresor, t_point position){ // où faut-il aller ? 
	int r = 0;
	t_point coord;
	r = whereWalls(Labyrinthe,position.x,position.y, tresor); // il faudra appeler (les) voisins plusieurs fois (ahaha)
	
	// Si toutes les possibilités ont été explorées -- les cases accessibles ont une val >0
		while(Labyrinthe[tresor.x][tresor.y].Item == 0){
			for(int i = position.x ; i < SIZEX ; i++) {
				for(int j = position.y ; j < SIZEY ; j++){
					if(whereWalls(Labyrinthe,i,j,tresor) < r ){
						r = whereWalls(Labyrinthe,position.x,position.y, tresor);
						Labyrinthe[position.x][position.y].val = r +1;
						coord.x = i;
						coord.y = j;
					}
				}
			}
		}
		return coord;
}

int distance(t_point cell, t_point position){ //renvoie la distance entre 2 points
	
	if( cell.x == position.x) 
		if(cell.y < position.y)
			return abs(position.y - cell.y);
	if( cell.y == position.y) 
		if(cell.x < position.x)
			return abs(position.x - cell.x);
	return (sqrt(position.x-cell.x)*(position.x-cell.x) + (position.y-cell.y)*(position.y-cell.y));
}

int main() {
  // initialisation du Labyrinthe
  int sizeX, sizeY, lab, tileN, tileE, tileS, tileW, tileItem;
  int *monLab =  monLab = malloc(sizeof(int));
  connectToServer("172.105.76.204", 1234, "hello");
  waitForLabyrinth("TRAINING RANDOM start=0 timeout=1000 display=debug", (int*)monLab, &sizeX, &sizeY);
  int turn = getLabyrinth(&lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
  int taille = sizeX*sizeY;
   monLab = realloc(monLab, sizeX*sizeY*sizeof(int));
   
    clearscr();
    printLabyrinth();

}
    
    
    
    
    
    
