#include<stdio.h>
#include<stdlib.h>
typedef enum{false, true}Bool;

typedef struct place place;
typedef place* list;

struct place{	
	int val;
	struct place *suivant;	
};

list newliste(){	
	return NULL;	
}
Bool listvide(list l){
	if(l == NULL)
	{
		return true;
	}
	return false;	
}
int nbreelement(list l){
	
	list tmp = l;
	int longeur=0;
	while(tmp != NULL){
		longeur++;
		tmp=tmp->suivant;
		
	}
	return longeur;
	
}

list ajouterfin(list l, int x){

	list element ;
	element = malloc(sizeof(list));

	if(element == NULL){
		
		printf("eurreur");
		exit(EXIT_FAILURE);
	}
	
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
	list element;
	element = malloc(sizeof(list));
	element->val=x;
	element->suivant=l;
	l=element;
	return l;	
	
}




void afficherlist(list l ){
	list tmp = l; 
	while(tmp != NULL){
		printf("%d \n", (*tmp).val);
		tmp = tmp->suivant;	
	}
}


list fusion(list l1, list l2){
	
	list p1 = l1;
	list p2 = l2;
	list L = l1;
	list current = L;
	current->suivant = l2;
	while(p1 != NULL && p2 != NULL){
		
		p1 = p1->suivant;
		p2 = p2->suivant;
		current->suivant =p1;
		current->suivant = p2;
	}
	return L;
}

main(){
	list l1 = newliste();
	l1 = ajouterfin(l1,4);
	l1 = ajouterfin(l1,5);
	l1 = ajouterfin(l1,6);
	l1 = ajouterfin(l1,7);
		
	list l2 = newliste();
	l2 = ajouterfin(l2,44);
	l2 = ajouterfin(l2,55);
	l2 = ajouterfin(l2,65);
	l2 = ajouterfin(l2,77);



	list l3 = newliste();
	l3 = fusion(l1,l2);
	afficherlist(l3);

//	afficherlist(l1);
//	l1 = ajouterdebut(l1,8);
//	printf("-----------------\n");
//	afficherlist(l1);
//
//	printf("-----------------\n");
//	afficherlist(l2);
	
//	chercher(l1,4);
	
//	l1 = ajouterdebut(l1,9);
//	list l3 = newliste();
//	
//	afficherlist(l3);

	
	return 0;
	

}
