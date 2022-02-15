#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int main(int argc, char **argv){
	
	
	AVL a = arbreVide();
//	AVL b = arbreVide();
//	AVL c = arbreVide();
//	AVL d = arbreVide();
	a = adjoindre(a,6);
	a = adjoindre(a,2);
	a = adjoindre(a,11);
	a = adjoindre(a,8);
	a = adjoindre(a,9);
	a = adjoindre(a,11);
	a = adjoindre(a,3);
	a = adjoindre(a,4);



printf("\n------------- affichage préfixe : ------------------\n");
	prefix(a);
	printf("\n------------- deséquilibre en prefixe : ------------------\n");
	prefix_D(a);
printf("\n------------- affichage en infixe  ------------------\n");
infixe(a);
printf("\n------------- affichage en postefixe ------------------\n");
postfixe(a);
a = suppAVL(a,6);
//a = suppAVL(a,3);
//a = suppAVL(a,4);

printf("\n------------- affichage en postefixe après suppression de 6------------------\n");
postfixe(a);
//a = suppAVL(a,3);
//printf("\n------------- affichage en postefixe après suppression de 3------------------\n");
//postfixe(a);
	return 0;
}
