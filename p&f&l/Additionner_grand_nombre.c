#include<stdio.h>
#include<stdlib.h>


typedef struct element element;
struct element
{
	int val;
	//un pointeur sur un element nxt
	struct element *nxt;
};
typedef element* Liste;


Liste empiler(Liste liste,int valeur)
{
	element *nouveauElement = malloc(sizeof(element));
	nouveauElement->val = valeur;
	nouveauElement->nxt  = NULL;


	//temp = liste;
	if (liste == NULL)
	{
		return nouveauElement;
	}
	element *temp = liste;
	while(temp->nxt != NULL){
		temp = temp->nxt;
	}
	temp->nxt = nouveauElement;
	return liste;
}

// depiler dans une pile

Liste depiler(Liste liste)
{
	element *temp1 = liste;
	element *temp2 = liste;
		if(temp2->nxt==NULL){
		liste=NULL;
	}
	while(temp1->nxt != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->nxt;
	}

	temp2->nxt = NULL;
	free(temp1);
	return liste;
}

/*fin de la fonction*/

int  sommet(Liste liste){
	int v=0;
    if(liste==NULL){
	
    	exit(1);
	}else{
			element *temp1 = liste;
			element *temp2 = liste;
			while(temp1->nxt != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->nxt;
			}
			v=temp1->val;
			
			return v;
			}
}

/*  la fonctio sommet de la pile */
void afficherliste(Liste liste)
{
	element *temp = liste;
	while(temp != NULL){
		printf("[ %d ] ",temp->val);
		temp = temp->nxt;

	}
}
/*  Addition de deux liste */

// Ajout debut
Liste ajout(Liste liste,int valeur)
{
	element* nouveauElement = malloc(sizeof(element));
	nouveauElement->val = valeur;
	nouveauElement->nxt  = liste;
	return nouveauElement;

}

Liste addTion(Liste p1,Liste p2){

	Liste Result=NULL;
	
	int val1, val2, retenue = 0,somme=0;
    
	while(p1 != NULL && p2 != NULL){

			val1 = sommet(p1);
			p1=depiler(p1);

			val2 = sommet(p2);
			p2=depiler(p2);

			somme= val1+val2+retenue;
			retenue =0;

			if (somme>9)
			{
				retenue = (int) somme/10;
				somme = somme % 10;
				
				Result= ajout(Result, somme);
			}
			else{

			Result=ajout(Result, somme);
				//replace by empiler()
				//afficher(Result);
			}

	}
	//qui termine le 1er
	if (p1!=NULL)
	{
			while(p1!=NULL){
			val1 = sommet(p1);
			p1=depiler(p1);
			
			somme= val1+retenue;

			if (somme>9)
			{
				retenue = (int) somme/10;
				somme = somme % 10;
				Result=ajout(Result, somme);
			}
			else{
				printf("----------------\n");
				
				Result= ajout(Result, somme);
			}

	}

	}
	if (p2!=NULL)
	{
			while(p2!=NULL){
			val2 = sommet(p2);
			p2=depiler(p2);
			
			somme= val2+retenue;

			if (somme>9)
			{
				retenue = (int) somme/10;
				somme = somme % 10;
				Result=ajout(Result, somme);
			}
			else{
				Result=ajout(Result, somme);
			}
	}
	}



	if (retenue>0)
	{
		Result= ajout(Result, retenue);
	}

	return Result;
}

/* fin de la fonction*/


int main(int argc, char const *argv[])
{

	
	 //liste 1
	 Liste ma_liste1 = NULL;
	
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	ma_liste1 = empiler(ma_liste1,1);
	

	//lste 2
	 Liste ma_liste2 = NULL;	

	ma_liste2 = empiler(ma_liste2,9);
	ma_liste2 = empiler(ma_liste2,2);
	ma_liste2 = empiler(ma_liste2,2);
	ma_liste2 = empiler(ma_liste2,2);
	ma_liste2 = empiler(ma_liste2,2);
	ma_liste2 = empiler(ma_liste2,2);
	ma_liste2 = empiler(ma_liste2,2);

 
 	printf("____________________++++++++++++++++++++++________________________\n");
 	printf("____________________++++++++++++++++++++++________________________\n\n");

 	afficherliste(ma_liste1);
 	printf("\n");
 	afficherliste(ma_liste2);

 	printf("\n");

	Liste Somme_final = NULL;
	Somme_final=addTion(ma_liste1,ma_liste2);
	printf("_______________________________________________________\n");

	afficherliste(Somme_final);
	printf("\n");

	return 0;
}
