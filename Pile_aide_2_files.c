#include<stdio.h>
#include"file_avec_pointeur.h"
typedef struct Pile_2files pile2f;
struct Pile_2files{
	file a;
	file b;
};
typedef pile2f *Pile;
Pile pileVide(){
	Pile p;
	p->a = fileVide();
	p->b = fileVide();
    return p;
}
int pileEstVide(Pile p){
     if((estVide(p->a)) && (estVide(p->b))){
     	return 1;
	 }
	 return 0;
}
Pile empiler(Pile p, int e){
    if(pileEstVide(p)){
        p->a = enfiler(p->a, e);
    }else{
        p->b = enfiler(p->b, e);
    }
    return p;
}

Pile depiler(Pile p){
    if(pileEstVide(p)){
        printf("Erreur la pile est vide!!!");
        exit(1);
    }
    if(estVide(p->b)){
        p->a = defiler(p->a);
        while(!estVide(p->a)){
            p->b = enfiler(p->b, p->a.debut->val);
            p->a = defiler(p->a);
        }
    }else{
        p->b = defiler(p->b);
        while(!estVide(p->b)){
            p->a = enfiler(p->a, p->b.debut->val);
            p->b = defiler(p->b);
        }
    }
    return p;
}
/*
int sommet(Pile p){
    if(pileEstVide(p)){
        printf("Erreur la pile est encore vide!!!");
        exit(1);
    }
    return p->val;
}
*/

void afficherPile(Pile p){
	int b = pileEstVide(p);
	printf("%d\n",b);
    if(pileEstVide(p)){
        printf("La pile est vide!!!");
        exit(1);
    }
    printf("Voici les elements de la pile:\n");
    if(!estVide(p->a)){
    	afficherfile(p->a);
	}else{
		afficherfile(p->b);
	}
}
void main(){
    int n, choix=-1;
    Pile p;
     do{
        printf("Gestion de File:\n1. Creer une pile vide\n2. Empiler la pile\n3. Premier element de la pile\n4. Depiler la pile\n"
               "5. Afficher la pile\n6. Quitter\n");
        controleSaisie("Donnez votre choix:\n",&choix);
        switch(choix){
            case 1:
                p = pileVide();
                printf("la pile est cree.\n");
                break;
            case 2:
                printf("Empilement:\n");
                controleSaisie("Donner l'entier a ajouter :\n",&n);
                p = empiler(p,n);
                printf("L'entier est ajoute avec succes.\n");
                break;
            case 3:
            	printf("Le premier element de la pile est Noo");
            	break;
            case 4:
            	p = depiler(p);
            	printf("Defilement:\n");
            	printf("La pile est defilee avec succes.\n");
            	break;
            case 5:
            	afficherPile(p);
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
