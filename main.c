#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int taille_liste = 0;
typedef struct place place;
struct place{
	int val;
	struct place* suiv;
};
typedef struct place* liste;

liste listeVide(){
	return NULL;
}

liste cons(liste l, int e){
    taille_liste++;
	place *p = malloc(sizeof(place));
	p->val = e;
	p->suiv = l;
	l=p;
	return p;
}
liste ajoutFin(liste l, int e){
    taille_liste++;
    liste p = malloc(sizeof(liste));
    p->val = e;
    p->suiv = NULL;
    if(l == listeVide()){
        return p;
    }
    liste temp = l;
    while(temp->suiv != NULL){
        temp = temp->suiv;
    }
    temp->suiv = p;
    return l;
}
liste ajoutApresPosition(liste l, int e, int pos){
    taille_liste++;
    liste p = malloc(sizeof(liste));
    p->val = e;
    p->suiv = NULL;
    if(l == listeVide()){
        return p;
    }
    liste temp = l;
    int i =1;
    while(temp->suiv != NULL && i<pos){
        temp = temp->suiv;
        i++;
    }
    if(temp==NULL){
        printf("La position est superieure à la taille de la liste\n");
        exit(0);
    }else{
        p->suiv = temp->suiv;
        temp->suiv = p;
    }

    return l;
}

liste fusion(liste l1,liste l2){
	if(l1==listeVide()){
		return l2;
	}
	if(l2==listeVide()){
		return l1;
	}
	liste l3=l1;
	liste temp=l3;
	int pos=1;
	while(l1 != NULL && l2!=NULL){
		if(pos==1){
			l1=l1->suiv;
			temp->suiv=l2;
			temp=l2;
			pos=2;
		}else{
			l2=l2->suiv;
			temp->suiv=l1;
			temp=l1;
			pos=1;
		}

	}
	return l3;
}

void afficherListe(liste l){
	if(l==listeVide())
		return;
	liste temp=l;
	while(temp!=NULL){
		printf("%d - ", temp->val);
		temp=temp->suiv;
	}
}
int main(int argc, char *argv[]) {
	liste L, L2=NULL;
	int choix=0, E, i;
	do{
        printf("#Liste chaine:\n----------\n1. Creer une liset vide\n2. Ajouter un entier au debut de la liste\n"
        "3. Ajouter un entier a la fin de la liste\n4. Afficher la taille de la liste\n5. Afficher la liste\n"
        "6. Ajouter  un entier apres une position\n7. Fusionner deux listes\n8.Quitter le programme");
        printf("\n\nEntrer votre choix:\n");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                L = listeVide();
                printf("La liste est creee");
                break;
            case 2:
                printf("Donner l'element a ajouter:\n");
                scanf("%d",&E);
                L = cons(L, E);
                break;
            case 3:
                printf("Donner l'element a ajouter:\n");
                scanf("%d",&E);
                L = ajoutFin(L, E);
                break;
            case 4:
                printf("La taille de la liste est: %d",taille_liste);
                break;
            case 5:
                printf("Voici les elements de la liste:\n");
                afficherListe(L);
                break;
            case 6:
                printf("Donner l'element a ajouter:\n");
                scanf("%d",&E);
                printf("Donner la position d'ajout:\n");
                scanf("%d",&i);
                L = ajoutApresPosition(L,E,i);
                break;
            case 7:
                printf("Donner nombre d'element de liste a fusionner:\n");
                scanf("%d",&E);
                int e;
                for(i=1;i<=E;i++){
                    printf("Donner l'element No:%d\n",i);
                    scanf("%d",&e);
                    L2 = ajoutFin(L2,e);
                }
                L2=fusion(L,L2);
                break;
            case 8:
                exit(1);
        }
        getch();
        system("cls");
	}while(choix!=0);

	return 0;
}

