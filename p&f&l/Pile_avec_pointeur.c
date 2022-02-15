#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct place place;
struct place {
    int val;
    place *prec;
};
typedef place *Pile;
Pile pileVide(){
    return NULL;
}
Pile empiler(Pile p, int e){
    place *q = malloc(sizeof(place));
    q->val = e;
    q->prec = p;
    p = q;
    return p;
}
int estVide(Pile p){
    if(p == NULL)
        return 1;
    return 0;
}
int sommet(Pile p){
    if(p == NULL){
        printf("Erreur la pile est encore vide!!!");
        exit(1);
    }
    return p->val;
}
Pile depiler(Pile p){
    if(estVide(p)){
        printf("Erreur la pile est vide!!!");
        exit(1);
    }
    p = p->prec;
}
void afficherPile(Pile p){
    if(estVide(p)){
        printf("La pile est vide!!!");
        exit(1);
    }
    printf("Voici les elements de la pile:\n");
    Pile temp = p;
    while(temp!=NULL){
        printf("%d - ",temp->val);
        temp = temp->prec;
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
    Pile p;
     do{
        printf("Gestion de Pile:\n1. Creer une pile vide\n2. Empiler la pile\n3. sommet de la pile\n4. Depiler la pile\n"
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
            	printf("Le sommet de la pile est:%d.\n",sommet(p));
            	break;
            case 4:
            	p = depiler(p);
            	printf("Depilement:\n");
            	printf("La pile est depilee avec succes.\n");
            	break;
            case 5:
            	afficherPile(p);
            	break;
            case 6:
            	system("cls");
            	printf("Au revoir");
            	exit(1);
        }
        printf("\n\nTapez [Entree] pour continuer...");
        getch();
        system("cls");
     }while(choix != 6);
}
