#include<stdio.h>
#include<stdlib.h>
typedef enum{false, true}Bool;

typedef struct place place;

struct place{
	int val;
	struct place *suivant;
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

	place *element = malloc(sizeof(place));
	element->val=x;
	element->suivant=l;
	return element;

}

void afficherlist(list l ){
	list tmp = l;
	while(tmp != NULL){
		printf("%d \n", (*tmp).val);
		tmp = tmp->suivant;
	}
}

list oneOfEachOne(list a, list b)
{
  list result = NULL;

  if (a == NULL)
     return(b);
  else if (b == NULL)
     return(a);

    result = a ;
    result->suivant = oneOfEachOne(b,a->suivant);

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

main(){

	list l1 = newliste();
	l1 = ajouterfin(l1,1);
	l1 = ajouterfin(l1,11);
	l1 = ajouterfin(l1,3);
	l1 = ajouterfin(l1,9);
	afficherlist(l1);
	
	
	printf("--------------------\n");
	//list l2 = malloc(sizeof(list));
	list l2 = newliste();
	l2 = ajouterfin(l2,2);
	l2 = ajouterfin(l2,4);
	l2 = ajouterfin(l2,7);
	l2 = ajouterfin(l2,8);
    afficherlist(l2);
    printf("\n--------------------\n");

	//    l=fusion(l1,l2);
  	//    afficherlist(l);
    printf("\n--------------------\n");


    list listC = newliste();
    listC = oneOfEachOne(l1,l2);
	afficherlist(listC);

    

	return 0;
}

