#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct place place;
struct place{
	int val;
	place *suiv;
};
typedef struct file file;
struct file {
	place *debut;
	place *fin;
};
file fileVide(){
	file f;
     f.debut=NULL;
	return f;
}
int estVide(file f){
	if(f.debut==NULL) return 1;
	return 0;
}
file enfiler(file f,int v){
	place *q=malloc(sizeof(place));
	q->val=v;
	q->suiv=NULL;
	if(f.debut==NULL){
		f.debut=q;
		f.fin=q;
	}else{
		(f.fin)->suiv=q;
		f.fin=q;
	}
	return f;
}
int premier(file f){
	if(f.debut==NULL){
		printf("Erreur le file est Vide");
		exit(1);
	}
	
	return f.debut->val;
}
file defiler(file f){
	if(estVide(f)){
		printf("Erreur la file Vide");
		exit(1);
	}else{
		f.debut=(f.debut)->suiv;
		if(f.debut==NULL) f.fin=NULL;
		return f;
	}
}
void afficherfile(file f){
	if(f.debut==NULL){
		printf("la file est vide");
		return;
	} 
	file tp=f;
	printf("Voici les elements de la File:\n");
	while(tp.debut!=NULL){
        printf("%d - ",tp.debut->val);
        tp.debut = tp.debut->suiv;
    }
}
void controleSaisie(char str[], int *n){
    do{
            fflush(stdin);
            printf("%s",str);
        }while(!scanf("%d",n));
}
void main(){
    int n, choix=-1;
    file f;
     do{
        printf("Gestion de File:\n1. Creer une file vide\n2. Enfiler la file\n3. Premier element de la file\n4. Defiler la file\n"
               "5. Afficher la file\n6. Quitter\n");
        controleSaisie("Donnez votre choix:\n",&choix);
        switch(choix){
            case 1:
                f = fileVide();
                printf("la file est cree.\n");
                break;
            case 2:
                printf("Enfilement:\n");
                controleSaisie("Donner l'entier a ajouter :\n",&n);
                f = enfiler(f,n);
                printf("L'entier est ajoute avec succes.\n");
                break;
            case 3:
            	printf("Le premier element de la file est: %d .\n",premier(f));
            	break;
            case 4:
            	f = defiler(f);
            	printf("Defilement:\n");
            	printf("La file est defilee avec succes.\n");
            	break;
            case 5:
            	afficherfile(f);
            	break;
            case 6:
            	system("cls");
            	printf("Au revoir");
            	exit(1);
            	break;
        	default:
        		printf("Veillez choisir un numero de menu!!!.\n");
        }
        printf("\n\nTapez [Entree] pour continuer...");
        getch();
        system("cls");
     }while(choix != 6);
}


