
#include <stdio.h>
#include <stdlib.h>



int sarah( int n,int *x){
	
	*x = &n;
		for(*x = 0 ; *x < 6 ; *x=*x+1){
			printf("%d\n", *x);
	}
	return 0; // retourne 0 si le trésor n'est pas dans le labyrinthe 
}
int main(){
	int d = 3;
	int x;
	sarah(d,&x);
	printf("%d\n", x);
	return 0;
}
