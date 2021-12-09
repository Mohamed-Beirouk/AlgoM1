#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud Noeud;
struct Noeud {
	int val;
	Noeud *g;
	Noeud *d;
};
typedef Noeud* Arbre;

Arbre arbreVide(){
	return NULL;
}

Noeud racine(Arbre A){
	if(A==NULL){
		printf("Arbre vide");
		exit(0);
	}
	return *A;
}

Arbre cons(Arbre g, Arbre d, int val){
	Arbre A = malloc(sizeof(Arbre));
	A->val = val;
	A->g = g;
	A->d = d;
	return A;
}

Arbre CreerNoeud(int e){
	Arbre b = malloc(sizeof(Arbre));
	b->val = e;
	b->g = NULL;
	b->d = NULL;
	return b;
}

void infix(Arbre A){
	
}

void main(){
	int t[]={20,40,10,50,30};
	Arbre A = arbreVide();
	int i=0;
	while(i<5){
		A = creerNoeud(t[i]);
		A->g = creerNoeud(t[(2*(i+1))]);
		A->d = creerNoeud(t[(2*(i+1) + 1)]);
		i = 2*(i+1) + 2;
	}
}
