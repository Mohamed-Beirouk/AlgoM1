#include<stdio.h>
#define N 200
struct Pile{
    int sommet;
    int place[N];
};
typedef struct Pile Pile;
Pile pileVide(){
    Pile p;
    p.sommet = -1;
    return p;
}
Pile empiler(Pile p, int e){
    p.sommet = p.sommet + 1;
    p.place[p.sommet] = e;
    return p;
}
int estVide(Pile p){
    if(p.sommet == -1)
        return 1;
    return 0;
}
int sommet(Pile p){
    return p.place[p.sommet];
}
Pile depiler(Pile p){
    if(estVide(p)){
        printf("La pile est vide !");
        exit(1);
    }
    p.sommet = p.sommet - 1;
    return p;
}
void afficherPile(Pile p){
    int i = 0;
    while(i<=p.sommet){
        printf("%d - ", p.place[i]);
        i++;
    }
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
     }while(choix!=6); 

}
