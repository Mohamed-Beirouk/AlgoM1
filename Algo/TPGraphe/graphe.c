#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "myqueue.h"
#include "pile.h"
// Début des  prototypes des fonctions 

void addLabel(Graphe *g, int x, int label);
void initialiser(Graphe *g, int ordre);
void afficher(Graphe g);
void ajouterArc(Graphe *g, int orig, int dest);
void supprimerArc(Graphe *g, int orig, int dest);
boolean estSucc(Graphe g, int x, int y);
boolean estPred(Graphe g, int x, int y);
int degreeInt(Graphe g, int x);
int degreeExt(Graphe g, int x);
int degree(Graphe g, int x);
void afficherDegrees(Graphe g);
void parocursProfS(Graphe g, int x, int visited[]);
void parocursProfG(Graphe g);
void parocursNivS(Graphe g, int s, int visited[]);
void parocursNivG(Graphe g);
boolean ExistUnChemin(Graphe g, int x, int y);
boolean ExistUnCheminBis(Graphe g, int x, int y, int visited[]);
boolean ExistUnCheminBisG(Graphe g, int x, int y);
//void chemin(Graphe g, int x, int y);
int *chemin(Graphe g, int x, int y);

// calcul du chemin le plus cours
int *Dijkstra(Graphe g, int x);
// Fin des  prototypes des fonctions 
// prototypes pour gérer une file
MyQueue fileVide();
void Enfiler(struct MyQueue *MQ, int E);
void Defiler(MyQueue *MQ);
int EstVide(MyQueue MQ );
int premierElement(MyQueue MQ);
// Fin prototypes pour gérer une file

// prototypes pour gérer une pile
Pile PileVide();
void Empiler(Pile *P, int E);
void Depiler(Pile *P);
int EstVideP(Pile P );
int Sommet(Pile P);
// Fin prototypes pour gérer une pile


void initialiser(Graphe *g, int ordre) {
	if (g == NULL) {
		printf("le graphe ne doit pas etre NULL !!");
		exit(EXIT_FAILURE);
	}
	if (ordre >=1 && ordre <= MAXS) {
		int i, j;
		g ->N = ordre;
		for (i=0; i < ordre; i++) {
			g->sommets[i] = -1; // une valeur non uilis�
			for (j=0; j < ordre; j++) {
				g->adj[i][j] = F;
			}
		}
	} else {
		printf("ordre du graphe doit être entre 1 et %d", MAXS);
		exit(EXIT_FAILURE);
	}

}
void addLabel(Graphe *g, int x, int label) {
	g->sommets[x-1] = label;
}
void afficher(Graphe g) {
	int i, j;
	for (i=0; i < g.N; i++) {
		for (j=0; j < g.N; j++) {
			printf("%d ", g.adj[i][j]);
		}
		printf("\n");
	}
}

void ajouterArc(Graphe *g, int orig, int dest) {
	if (g != NULL) {
		if ((orig > g->N) || (orig < 1)) {
			printf("le sommet %d n''existe pas", orig);
			exit(EXIT_FAILURE);
		}
		if ((dest > g->N) || (dest < 1)) {
			printf("le sommet %d n''existe pas", dest);
			exit(EXIT_FAILURE);
		}
		g->adj[orig-1][dest-1] = T;
	} else {
		printf("le graphe ne doit pas etre NULL !!");
		exit(EXIT_FAILURE);
	}
}
void supprimerArc(Graphe *g, int orig, int dest) {
	if (g != NULL) {
		if ((orig > g->N) || (orig < 1)) {
			printf("le sommet %d n''existe pas", orig);
			exit(EXIT_FAILURE);
		}
		if ((dest > g->N) || (dest < 1)) {
			printf("le sommet %d n''existe pas", dest);
			exit(EXIT_FAILURE);
		}
		g->adj[orig-1][dest-1] = F;
	} else {
		printf("le graphe ne doit pas être NULL !!");
		exit(EXIT_FAILURE);
	}
}
boolean estSucc(Graphe g, int x, int y) {
	if ((x > g.N) || (x < 1)) {
		printf("le sommet %d n''existe pas", x);
		exit(EXIT_FAILURE);
	}
	if ((y > g.N) || (y < 1)) {
		printf("le sommet %d n''existe pas", y);
		exit(EXIT_FAILURE);
	}
	return (g.adj[x-1][y-1]);
}
boolean estPred(Graphe g, int x, int y) {
	return (estSucc(g, y, x));
}
int degreeInt(Graphe g, int x) {
	if ((x > g.N) || (x < 1)) {
		printf("le sommet %d n''existe pas", x);
		exit(EXIT_FAILURE);
	}
	int i, d = 0;
	for (i =0; i< g.N; i++) {
		d += g.adj[i][x-1];
	}
	return d;
}
int degreeExt(Graphe g, int x) {
	if ((x > g.N) || (x < 1)) {
		printf("le sommet %d n''existe pas", x);
		exit(EXIT_FAILURE);
	}
	int i, d = 0;
	for (i =0; i< g.N; i++) {
		d += g.adj[x-1][i];
	}
	return d;
}
int degree(Graphe g, int x) {
	if ((x > g.N) || (x < 1)) {
			printf("le sommet %d n''existe pas", x);
			exit(EXIT_FAILURE);
		}
		int i, d = 0;
		for (i =0; i< g.N; i++) {
			d += g.adj[x-1][i] + g.adj[i][x-1];
		}
		return d;
}
void afficherDegrees(Graphe g) {
	printf("-----------------------------------\n");
	printf("| Sommet  | Deg I | Deg Ext | Deg |\n");
	printf("-----------------------------------\n");
	int i;
	for (i = 0; i< g.N; i++) {
		printf("| %6d  | %3d   | %4d    | %3d | \n", (i+1), degreeInt(g, i+1), degreeExt(
				g, i+1), degree(g, i+1));
	}
	printf("-----------------------------------\n");

}
void parocursProfS(Graphe g, int x, int visited[]) {
	visited[x-1] = T;
	printf("%d ",x);
	int j;
	for(j=0; j < g.N; j++) {
		if( g.adj[x-1][j] && !visited[j]){
			parocursProfS(g,j+1,visited);
		}
	}
}
void parocursProfG(Graphe g) {
	int visited[g.N];
	//visited =  malloc(g.N * sizeof *visited);
	int i;
	printf(" ****** debut du parcours du graphe en profondeur ******* \n ");
	for(i = 0; i< g.N; i++) {
		visited[i] = F;
	}
	int j;
	for(j=0; j < g.N; j++) {
		if(!visited[j]){
			parocursProfS(g,j+1,visited);
		}
	}
	printf("\n ");
}
void parocursNivS(Graphe g, int s, int visited []){
	// créer une file vide
	if(s>=1 && s<= g.N){
		MyQueue MQ = fileVide();
		//afficher le sommet
		//enfiler S dans la file
		Enfiler(&MQ,s);
		visited[s-1] = T;
		while(!EstVide(MQ)){
			int e = premierElement(MQ);
			Defiler(&MQ);
			printf("%d ",e);
			int j;
			for(j=0; j< g.N; j++){
				if(!visited[j] && estSucc(g, e,j+1)){
					visited[j] = T;
					Enfiler(&MQ,j+1);
				}
			}
		}
	}
	
}
void parocursNivG(Graphe g) {
	int visited[g.N];
	//visited =  malloc(g.N * sizeof *visited);
	int i;
	printf(" ****** debut du parcours du graphe en largeur ******* \n ");
	for(i = 0; i< g.N; i++) {
		visited[i] = F;
	}
	int j;
	for(j=0; j < g.N; j++) {
		if(!visited[j]){
			parocursNivS(g,j+1,visited);
		}
	}
	printf("\n ");
}
boolean ExistUnChemin(Graphe g, int x, int y) {
	int visited[g.N];
	int i;
	for(i = 0; i< g.N; i++) {
			visited[i] = F;
	}
	if(x == y) {
		return T;
	}
	parocursProfS(g, x, visited);
	return(visited[y-1]);
}
// autre version de l'algo existUnChemin
boolean ExistUnCheminBis(Graphe g, int x, int y, int visited[]) {
	visited[x-1] = T;
	//printf("%d ",x);
	if (x==y){
		return T;
	}
	int j = 0;
	while(j< g.N){
		if( g.adj[x-1][j] && !visited[j]){
			if(y == j+1){
				return T;
			} else{
				ExistUnCheminBis(g,j+1,y,visited);
			}
		}
		j++;
	}
	return F;
}
boolean ExistUnCheminBisG(Graphe g, int x, int y) {
	int visited[g.N];
	int i;
	for(i=0; i< g.N; i++){
		visited[i] = F;
	}
	return ExistUnCheminBis(g, x, y, visited);
}
// Cet algorithme renvoi un chemin entre x et y s'il en exite un
int * chemin(Graphe g, int x, int y){
	if(x==1 && y ==3){
		printf("Ici un probleme : \n");
	}
	int *result = malloc(g.N*sizeof(int));
	int i;
	for(i = 0; i< g.N; i++) {
		result[i] = -1;
	}
	if(x == y) {
		result[g.N -1] = x;
		 printf("%d\n",x);
		return result;
	}
	if(estSucc(g, x,y)) {
		result[g.N -2] = x;
		result[g.N -1] = y;
		 printf("%d -> %d\n",x,y);
		return result;
	}
	int visited[g.N];
	Pile P = PileVide();
	Pile P2 = PileVide();
	for(i = 0; i< g.N; i++) {
		visited[i] = F;
	}
	Empiler(&P, x);
	boolean found = F;
	 visited[x-1] = T;
	while(!EstVideP(P) && !found) {
		int e = Sommet(P);
		Depiler(&P);
		if(!visited[e-1]) {
			visited[e-1] = T;
			Empiler(&P2,e);
		    if(y == e){
		    	found = T;
		    }
		}
		int j;
		for(j= g.N -1; j >= 0 && !found; j--){
		  if(g.adj[e-1][j] && !visited[j]){
			  Empiler(&P,j+1);
		  }
		}
	}
	if(found){
		int counter = g.N;
		int dernSomm = -1;
		while(!EstVideP(P2) && !estSucc(g,x,Sommet(P2))) {
			if(estSucc(g,Sommet(P2),dernSomm) || dernSomm == -1){
			result[--counter] = Sommet(P2);
			}
			dernSomm = Sommet(P2);
			Depiler(&P2);
		}
		result[--counter] = Sommet(P2);
		result[--counter] = x;
		// afficher le chemin
		int j;
        for(j = counter; j< g.N-1; j++) {
        	printf("%d ->",result[j]);
        }
        printf("%d\n",result[j]);
	}else{
		 printf("pas de chemin entre %d et %d\n",x,y);
	}
	return result;
}

// plus court avec l'algorithme Dijkstra
// cette implémentation n'est pas optimale
// on peut améliorer l'algorithme 
int *Dijkstra(Graphe g, int x) {
	if ((x > g.N) || (x < 1)) {
		printf("le sommet %d n''existe pas", x);
		exit(EXIT_FAILURE);
	}
	int *distances = malloc((g.N-1)*sizeof(int));
	boolean *marked = malloc((g.N-1)*sizeof(int));
	int index=0;
	int i;
	// initialiser Marked avec faux
	for(i=0; i<g.N-1; i++) {
		marked[i] = F;
	}
	// initialser les distances
	for(i=0; i<g.N; i++) {
		if(i != x-1) {
			if(estSucc(g,x,i+1)){
				distances[index++]= g.adj[x-1][i];
			} else{
				distances[index++]= INT_MAX; // plus infini
			}
		}
	}
	// debut des iterrations de l'algorithme pour choisir le sommet le plus proche de x
	// et mettre à jour les distances
	int j;
	for( i = 0; i< g.N - 1; i++) { // on fera N-1 iterrations (N l'ordre du graphe)
		// quel est le sommet qui n'a pas été parcouru dont la distance est minimale
		int dist = INT_MAX;
		int position = -1; // position  dans le tableau des distances
		int sommet = -1; // numéro du sommet dans le graphe
		index = 0; // réinitialiser la varible index à 0
		for (j= 0; j< g.N; j++) {
			if(j != x-1) {
				if(!marked[index] && distances[index] < dist){
					dist = distances[index];
					position = index;
					sommet = j;
				}
				index++;
			}
		}
		// le sommet de distance minimal est à l'indice position,
		// on la marque comme parcouru 
		
		if (position !=-1){
			marked[position] = T;
			
			// on mets à jour les distances
			index = 0; // réintialisation du compteur index
			for( j = 0; j< g.N; j++) {
				if(j != x-1) {
					if( j != sommet){
						if(estSucc(g, sommet+1, j+1)) {
							if(distances[index] > distances[position] + g.adj[sommet][j]){
								distances[index] =  distances[position] + g.adj[sommet][j];
							}
						}
					}
					index++;
				}
				
			}
		}
		
		
	}
	return distances;
}
//Cette partie implémente une file des éléments de type Entier
// Manupilation d'une file
MyQueue fileVide(){
	MyQueue f;
	f.debut = NULL;
	f.fin = NULL;
	return f;
}
int EstVide(MyQueue MQ) {
	if (MQ.debut == NULL){
		return 1;
	} else{
		return 0;
	}
}
void Enfiler(MyQueue *MQ, int E){
	Liste *Q = (Liste *)malloc(sizeof(Liste));
	Q->val  = E;
	Q->suiv = NULL;
	if (MQ ->debut == NULL){
		MQ->debut = Q;
		MQ->fin = Q;
	}else {
		MQ->fin->suiv = Q;
		MQ->fin = Q;
	}
}
void Defiler(MyQueue *MQ) {
	if((MQ !=NULL) && !EstVide(*MQ)){
		MQ->debut = (MQ->debut)->suiv;
		if(MQ->debut == NULL) {
			MQ->fin = NULL;
		}
	}
}
int premierElement(MyQueue MQ) {
	if(!EstVide(MQ)){
		return MQ.debut->val;
	}
	// return -1 si cette valeur n'est pas utilsée
	return -1;
}

// Debut d'implémentation des opérations d'une pile
Pile PileVide() {
	return NULL;
}
void Empiler(Pile *P, int E) {
	Place * Q = malloc(sizeof(Place));
	Q->val = E;
	Q->prec = *P;
	*P = Q;
	//printf("*P = %u", *P);
}
void Depiler(Pile *P) {
	if(P != NULL && *P != NULL){
		*P = (*P)->prec;
	} else {
		printf("erreur pile est vide");
	}
}
int EstVideP(Pile P ) {
	return (P == NULL);
}
int Sommet(Pile P) {
	if(P !=NULL) {
		return P->val;
	}else {
		printf("erreur pile est vide fonction sommet");
		return -1; // si cette valeur n'est pas defini
	}
}
int main(int argc, char **argv) {
		FILE* fichier = NULL;
	fichier = fopen("test.txt", "r+");

    if (fichier != NULL)
    {
        
    	fputc('1', fichier);
    	fputs("\nVoila un graphe dans un fichier?\n", fichier);
    	fprintf(fichier, "nombre de sommets est de %d\n", 5);
    	fprintf(fichier, "matrice d'adjacence: \n");
        fprintf(fichier, "%d %d %d %d %d\n",0, 1, 1, 0, 1);
    	fprintf(fichier, "%d %d %d %d %d\n",0, 0, 1, 1, 0);
    	fprintf(fichier, "%d %d %d %d %d\n",1, 1, 0, 1, 1);
    	fprintf(fichier, "%d %d %d %d %d\n",0, 1, 1, 0, 0);
    	fprintf(fichier, "%d %d %d %d %d\n",1, 0, 1, 1, 0);
    	
    	// Lecture
    	// int fgetc(FILE* pointeurDeFichier);
    	//on ferme le fichier
    	fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
	// fin utilisation fichier
	Graphe g;
	//printf("%d", g[0].label);
	initialiser(&g, 9);
	ajouterArc(&g, 1, 2);
	ajouterArc(&g, 1, 4);
	ajouterArc(&g, 1, 5);
	
	ajouterArc(&g, 2, 3);
	ajouterArc(&g, 4, 9);
	ajouterArc(&g, 6, 7);
	ajouterArc(&g, 7, 4);
	ajouterArc(&g, 7, 9);
	ajouterArc(&g, 8, 4);
	ajouterArc(&g, 8, 5);
	
	//ajouterArc(&g, 11, 12);
	
	afficher(g);
	// afficher le pracour en profondeur
	parocursProfG(g);
	// afficher le pracour en largeur
	parocursNivG(g);
	afficherDegrees(g);
	int i, j;
	/* A faire apr�s 
	for( i = 1; i <= g.N; i++) {
		for( j = 1; j <= g.N; j++) {
				printf("(%d,%d)\n",i,j);
			chemin(g,i,j);
		}
	}
	*/
	printf("************* Appel de l'algorithme Dijkstra\n****************");
	int * dist = Dijkstra(g,1);
	printf("************* resultats de l'algorithme Dijkstra\n****************");
	for(i= 0; i< g.N-1; i++) {
		printf("%d ", dist[i]);
	}
	printf("\n");
	return 0;
}

