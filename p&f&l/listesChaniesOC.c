#include <stdio.h>
#include <stdlib.h>

//LISTE CHAINEES
int longueurListe = 0;
typedef struct Element Element;

struct Element{ //LES CASES
 	int val;
 	struct Element* next;
};

typedef Element* Liste;

Liste listeVide(){
	return NULL;
} 
Liste construit(Liste l, int val){
	if(l == NULL){//Cree la liste si elle n'existe pas encore
		Liste lst = malloc(sizeof(Liste));
		lst->val = val;
		lst->next = NULL;
		longueurListe++;
		return lst;
	}
	else { //Update the list's head
		Liste lst = malloc(sizeof(Liste));//allocate another Element pointer that will point back to this one
		lst->val = val;
		lst->next = l;
		longueurListe++;
		return lst;
	}
}

void afficher(Liste lst){
	Liste lsttmp = lst;
	while (lsttmp != NULL){
		printf("@ : %p, Val : %d, Next = %p\n", lsttmp, lsttmp->val, lsttmp->next);
		lsttmp = lsttmp->next;
	}
}

Liste supprimerDeListe(Liste lst){
	Liste lstNew = lst->next;
	free(lst);
	longueurListe--;
	return lstNew;
}

void supprimerListe(Liste lst){
	Liste lsttmp = lst;
	while (lsttmp != NULL){ //point lsttmp to 1st element
		lsttmp = lsttmp->next;
		free(lsttmp);
	}
	free(lsttmp);
}

int getLongueurListe(){
	return longueurListe;
}

//*********MAIN
 
void main(){
	//construire des elements
	Liste lst1 = construit(listeVide(), 11);
	Liste lst2 = construit(lst1, 22);
	Liste lst3 = construit(lst2, 33);

	
	Liste test = construit(lst3, 999);
	afficher(test);
	
	printf("La longeur de la liste est : %d \n", getLongueurListe());
	supprimerDeListe(test); //No more accessible by the list
	printf("La longeur de la liste est : %d \n", getLongueurListe());
	printf("**************Apres suppression element tet \n");

	supprimerListe(test); //STILL NOT QUITE DONE
	
	printf("**************Apres suppression de la liste \n");
	afficher(test);
	
	/*AFFICHAGE DES ELEMENTS
	printf("ls1 :%p : val = %d, next = %p\n", lst1, lst1->val, lst1->next);
	printf("ls2 :%p : val = %d, next = %p\n", lst2, lst2->val, lst2->next);
	printf("ls3 :%p : val = %d, next = %p\n", lst3, lst3->val, lst3->next);
	printf("test :%p : val = %d, next = %p\n", test, test->val, test->next);
	
	//Supression des elements
	Liste lst = supprimer(test);
	printf("lst :%p : val = %d, next = %p\n", lst, lst->val, lst->next);
	*/
}
