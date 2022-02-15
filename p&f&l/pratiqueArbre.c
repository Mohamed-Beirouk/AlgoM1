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

int racine(Arbre A){
	if(A==NULL){
		printf("Arbre vide");
		exit(0);
	}
	return A->val;
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


int NombreNoeud(Arbre A) {
	
	
	 if(A==NULL){
	 	return 0;
	 }	
	else{
		return 1 + NombreNoeud(A->g) + NombreNoeud(A->d);
	}
}
int NombreFeuille(Arbre A) {

	 if(A==NULL){
	 	return 0;
	 }	
	else{
	
		if((A->g)!=NULL || (A->d)!=NULL){
			return  NombreFeuille(A->g) + NombreFeuille(A->d);	
		}
		
		else{
			return 1 + NombreFeuille(A->g) + NombreFeuille(A->d);		
		}
	}
		
}
Arbre infix(Arbre a){
	if(a!=NULL){
		infix(a->g);
		printf("%d  ",a->val);
		infix(a->d);
	}
}
Arbre prefix(Arbre a){
	if(a!=NULL){
		printf("%d  ",a->val);
		infix(a->g);
		infix(a->d);
	}
}
Arbre postfix(Arbre a){
	if(a!=NULL){
		infix(a->g);
		infix(a->d);
		printf("%d  ",a->val);
	}
}
Arbre afflargeur(Arbre a){
	int n=5,i=0;
	for(i=0;i<n;i++){
		affniveau(a,n);
	}
	
	
}
int affniveau(Arbre a, int n){
	if(a==NULL){
		return 0;
	}
	else{
		if(n==1){
			printf("%d",a->val);
		}
		else{
			n=n-1;
			affniveau(a->g,(n));
			affniveau(a->d,(n));
		}
	}
}


int main(){
	Arbre A = arbreVide();
	
		A=CreerNoeud(5);
		
		A->g=CreerNoeud(20);
		A->d=CreerNoeud(3);
		
		A->g->g=CreerNoeud(55);
		A->d->d=CreerNoeud(17);
		
		A->g->g->d=CreerNoeud(47);
		
		A->d->g=CreerNoeud(25);
		A->d->g->g=CreerNoeud(14);
		A->d->g->d=CreerNoeud(23);
		A->d->g->g->d=CreerNoeud(10);
	
	printf("----nbre noeud-------\n");
	
	printf("%d",NombreNoeud(A));
	
	printf("\n-----nbre feuilles------\n");
	
	printf("%d",NombreFeuille(A));
	printf("\n-----racine------\n");
	
	printf("%d",racine(A));
	printf("\n----- Affichage ---\n");
	printf("\n-----  infix  ------\n");
	printf("%d",infix(A));
	printf("\n-----  prefix  ------\n");
	printf("%d",prefix(A));
	printf("\n-----  postfix  ------\n");
	printf("%d",postfix(A));
	printf("\n--- Affichage par largeur  ------\n");
	printf("%d",afflargeur(A));
	return 0;
}
