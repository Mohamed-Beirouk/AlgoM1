#include<stdio.h>
#include<stdlib.h>

typedef enum{false, true}Bool;

typedef struct place place;

struct place{
	int val;
	struct place * suivant;
};

typedef place*list;

int nbreelement(list l){

	list tmp = l;
	int longeur=0;
	while(tmp != NULL){
		longeur++;
		tmp=tmp->suivant;

	}
	return longeur;

}
Bool listvide(list l){
	if(l == NULL)
	{
		return true;
	}
	return false;	
}
list newliste(){	
	return NULL;	
}

list ajouterfin(list l, int x){

	list element ;
	element = malloc(sizeof(list));

	element->val = x;
	element->suivant = NULL;

	if(listvide(l)){
		return element;
	}
	list temp;
	temp =l;
	while(temp->suivant != NULL){
		temp=temp->suivant;
	}
	temp->suivant = element;

	return l;
}

list ajouterapresi(list l, int x, int i){
	if(i>nbreelement(l)){
		printf("\nimpossible, car lindice donner [%d] depasse la longeur du liste [%d] ", i, nbreelement(l));
	}
	
	list tmp = l;
	int j;
	for(j=0;j<i;j++){
		tmp=tmp->suivant;
	}
	list element = malloc(sizeof(list));
		element->val = x;

		element->suivant = tmp->suivant;
		tmp->suivant = element;

	return l;
}



list ajouterdebut(list l, int x){

	place *element = malloc(sizeof(place));
	element->val=x;
	element->suivant=l;
	return element;

}

void afficherlist(list l ){
	list tmp = l;
	while(tmp != NULL){
		printf("%d \n", tmp->val);
		tmp = tmp->suivant;
	}
}

list fusion(list a, list b)
{
  list result = NULL;

  if (a == NULL)
     return(b);
  else if (b == NULL)
     return(a);

    result = a ;
    result->suivant = fusion(b,a->suivant);

  return(result);
}

list fusion_avec_tri(list la,list lo)
{
list temp1=la;
list temp2=lo;
if(temp1==NULL)
{
return temp2;
}
else if(temp2==NULL)
{
return temp1;
}
else if ((temp1->val) <= (temp2->val))
{
temp1->suivant = fusion_avec_tri(temp1->suivant,temp2);
return(temp1);
}
else
{
temp2->suivant = fusion_avec_tri(temp1,temp2->suivant);
return(temp2);
}
}
list supprimer(list l){
	
	l=l->suivant;
}

main()
{
	int choix;
	list l1 = NULL;


		
	do{
	
		printf("\n\t____________________________________________________");
		printf("\n\tCHOISIR UN CHOIX  OU ENTRER 0 POUR TERMINER\n");
		printf("\t____________________________________________________\n");

		int x;
		int z;
		printf("1 : affichage \n");
		printf("2 : ajout au debut \n");
		printf("3 : ajout fin \n");
		printf("4 : quitter \n");
		scanf("%d",&choix);
		
		switch (choix){	
		case 1 : 
			printf("\nAffichage : \n");
				afficherlist(l1);
				break;
		case 2 : 
			printf("\nAjouter debut : \n");
			do{
				printf("donner un nombre : ");
				scanf("%d",&x);
				l1 = ajouterdebut(l1,x);
		
			}while(x!=0);
			
			break;

		case 3 : 
			printf("\najouter fin : \n");
					printf("\nAjouter fin : \n");
						do{
							printf("donner un nombre : ");
							scanf("%d",&x);
							l1 = ajouterfin(l1,x);
						}while(x!=0);
			
				break;

		

		case 0 : exit(0);
		}
		
	
	}while (choix != 4);
	
	
return 0;
	
	
	
	
	
	
	
	
	
	
	
//	list l1 = newliste();
//	l1 = ajouterfin(l1,1);
//	l1 = ajouterfin(l1,11);
//	l1 = ajouterfin(l1,3);
//	l1 = ajouterfin(l1,9);
//	afficherlist(l1);
//		
//	printf("--------------------\n");
//	list l2 = malloc(sizeof(list));
//	l2 = newliste();
//	l2 = ajouterfin(l2,2);
//	l2 = ajouterfin(l2,4);
//	l2 = ajouterfin(l2,7);
//	l2 = ajouterfin(l2,8);
//    afficherlist(l2);
//    printf("\n--------------------\n");
//
//    printf("\n--------------------\n");
//
//    list listC = newliste();
//    listC = fusion(l1,l2);
//	afficherlist(listC);

}


