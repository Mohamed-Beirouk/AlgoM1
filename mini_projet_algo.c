#include <stdio.h>
#include <stdlib.h>




///////////////LISTE SIMPLEMENT CHAINEES////////////////////////
typedef struct place Place;//alias

struct place{
	int val;
	struct place *suiv; //struct Place * : un pointeur de type complexe(structure)
};

typedef Place * Liste; //struct place * Liste;



//LES METHODES DE MANIPULATIONS DE LISTE

//retourne une liste vide
Liste listeVide(){
	return NULL;
}

//affiche les informations d'une liste
void afficherListe(Liste l ){
	Liste tmp = l; // tmp : se deplace dans la Liste l, entre tous les #ts places
	while(tmp != NULL){
		printf("%d \n", (*tmp).val);
		tmp = tmp->suiv;	//(*tmp).val => tmp->val
	}
}


//ajoute un element a la tete d'une liste
Liste construit(Liste lst, int val){
	Liste l = malloc(sizeof(Liste));  
	l->val = val;
	l->suiv = lst;
	return l; // return the newest list
}


//retourne la tete d'une liste(struct place : Place)
Place tete(Liste lst){
	if(lst != NULL){		
		return (*lst); 
	}
	else {
		printf("La list est vie");
		exit(1);
	}
}

//retourne la valeur d'une place
int contenu(Place p){
	return p.val;
	//retourne le contenu d'une case
}	


//retourne une liste prive de la tete de la liste d'entre
Liste fin(Liste l){
	if (l == NULL){
		printf("Erreur\n");
		exit(1);
	}
	else if (l->suiv == NULL){
		return NULL;
	}
	else		
		return l->suiv;		
}


//Insere un element a la position i
Liste insererAlaPositionI(Liste lst, int position, int val){
	//entrees algo : list :1, 2, 3, 4, 5    => pos [1, 6] 
// rang >=1
	int i = 1; 
	Liste tmp = lst;

	if (position == 1){
		Liste newList = malloc(sizeof(Liste));
		newList->val = val;
		newList->suiv = lst;
		return newList;
	}

	//Parcours jusqu'a la postion juste avant le rang
	while((i < position-1) && (tmp->suiv != NULL)){
		//Tant que je suis pas arriere au rang et la liste n'est pas fini
		i++;
		tmp = tmp->suiv;
	}


	if(i == position-1 ){ // donc on est arrive au rang i
		Liste newLst = malloc(sizeof(Place));
		newLst->val = val;
		newLst->suiv = tmp->suiv;
		tmp->suiv = newLst;
		return lst;

		//Return the original list, comme les modifications sont faites
	}
}

//AJOUTER UN ELEMENT A LA FIN DE LA LISTE 
Liste ajoutFin(Liste lst, int val){
	Liste tmp = lst;

	while(tmp->suiv != NULL){
		tmp = tmp->suiv;
	}

	Liste newList = malloc(sizeof(Liste));
	newList->val = val;
	newList->suiv  = NULL;
	tmp->suiv = newList;

	return lst;
}

//Retourne la longueur de la liste 
int longueurListe(Liste lst){
		int i = 0;
		Liste tmp = lst;

		while(tmp != NULL){
			i++;
			tmp = tmp->suiv;
		}
		return i;
	}


//Supprimer a la position I

void listSimpleChaine(){
	int choix = 1;
	int val = 0;
	int position = 0;
	int lenList = 0;
	Liste lst = NULL;
	Place teteLst;
	
	do{
		printf("_____MENU DE MANIPULATIONS DES LISTES CHAINEESS:\n");
		printf("Faites votre choix : \n");

		printf(" -> 1 :Pour l'initialisation de la liste. \n");
		printf(" -> 2 :pour ajouter un element a la liste. \n");
		printf(" -> 3 :pour afficher la liste. \n");
		printf(" -> 4 :pour voir la tete de la liste.\n");
		printf(" -> 5 :pour voir le contenu du dernier element ajouté: \n");
		printf(" -> 6 :Pour accéder à la fin de la liste(suppression du dernier élément).\n");
		printf(" -> 7 :pour ajouter à la qeue de la liste. \n");
		printf(" -> 8 :pour ajouter à une position choisie de la liste.\n");
		printf(" -> 9 :pour savoir la longueur de la liste.\n");
		printf("\n--> 0 :Pour Quitter.\n");

		scanf("%d", &choix);

		switch (choix){	
			case 1 : 
				printf("________\n\tcreer une nouvelle liste:\n");
				printf("Donner un entier : \n");
				scanf("%d", &val);
				lst = construit(listeVide(), val);
				printf("\n");
				break;

			
			case 2 : 
				printf("________\n\tAjout d'un élément à la liste :\n");
				printf("Donner un entier à ajouter à la liste :\n");
				scanf("%d", &val);
				lst = construit(lst, val);
				printf("\n");
				break;
			case 3 : 
				printf("________\n\tAffichage de la liste :\n");
				afficherListe(lst);
				printf("_____________\n");
				break;
			case 4 : 
				teteLst = tete(lst);
				printf("________\nLa tête de la liste :\n");
				printf("Tete (val = %d, @suiv = %p).\n", teteLst.val, teteLst.suiv);
				printf("_____________\n");
				break;
			case 5 : 
				teteLst = tete(lst);
				printf("________\nLe contenu du dernier élément ajouté :\n");
				printf("Tete : %d.\n", contenu(teteLst));
				printf("_____________\n");
				break;
			case 6 : 
				printf("________\n\tAccès à la fin de la liste(exclure la tete) :\n");
				if (lst != NULL){
					lst = fin(lst);
				}
				printf("_____________\n");
				break;

			case 7 : 
				printf("________\n\tAjout à la queu de la liste :\n");
				printf("Donner un entier :\n");
				scanf("%d", &val);
				lst = ajoutFin(lst, val);
				printf("\n");
				break;
			case 8 : 
				printf("________\n\tAjout à la position I de la liste :\n");
				printf("Donner un entier, puis donner sa position(>0 et <= taille de la liste) :\n");
				scanf("%d%d", &val, &position);

				lenList = longueurListe(lst);
				if (position > 0 && (position <=  lenList+ 1)){
					lst = insererAlaPositionI(lst, position, val);
				}
				printf("\n");
				break;
			case 9 : 
				printf("________\n\tLa longueur de la liste :\n");

				lenList = longueurListe(lst);
				printf("Longueur de la liste : %d\n", lenList);
				printf("\n");
				break;
			case 0 : exit(0);

			default : printf("Mauvais choix, veillez ressayer.");
		}

	} while (choix != 0);
}
///////////////////////LSC//////////////////////


///////////////LISTE DOUBLEMENT CHAINEES////////////////////////

typedef struct Placedc Placedc;
typedef Placedc* Listedc;

struct  Placedc
{
	int val;
	Listedc suiv;
	Listedc prec;
};

struct  Managedc
{
	int val;
	Listedc head;
	Listedc tail;
	int longueurListe;
};

typedef struct Managedc Managedc;

//MANAGEMENT METHODES
//#1 retourne une Listedc vide
Listedc listeVidedc(){
	return NULL;
}

//#2 CONSTRUIRE UNE Listedc
Listedc construitdc(Listedc lst, int val){
	Listedc tmp = malloc(sizeof(Listedc));
	tmp->val = val;
	tmp->prec = lst;
	tmp->suiv = NULL;
	return tmp;
}

//#3 AFFICHER UNE Listedc
void afficherListedc(Listedc l ){
	Listedc tmp = l; // tmp : se dePlacedc dans la Listedc l, entre tous les #ts Placedcs
	while(tmp != NULL){
		printf("%d \n", (*tmp).val);
		tmp = tmp->prec;	//(*tmp).val => tmp->val
	}
}

//#4retourne la tetedc d'une Listedc(struct Placedc : Placedc)
Placedc tetedc(Listedc lst){
	if(lst != NULL){		
		return (*lst); 
	}
	else {
		printf("La list est vie");
		exit(1);
	}
}

//#5 retourne la valeur d'une Placedc
int contenudc(Placedc p){
	return p.val;
	//retourne le contenudc d'une case
}

//#6 retourne une Listedc prive de la tetedc de la Listedc d'entre
Listedc finListedc(Listedc l){
	if (l == NULL){
		printf("Erreur\n");
		exit(1);
	}
	else if (l->prec == NULL){
		return NULL;
	}
	else{
		Listedc tmp = l->prec;
		tmp->suiv = NULL;
		return tmp;	
	} 
		
}

//#7 RETOURNE LA TAILLE DE LA Listedc
int calculerTailledc(Listedc lst){
	int taille = 0;
	Listedc tmp = lst;

	while(tmp != NULL){
		taille++;
		tmp = tmp->prec;
	}
	return taille;
}

//#8 AJOUTER UN ELEMENT A LA FIN DE LA Listedc 
Listedc ajoutFindc(Listedc lst, int val){
	Listedc tmp = lst;

	while(tmp->prec != NULL){
		tmp = tmp->prec;
	}

	Listedc newList = malloc(sizeof(Listedc));
	newList->val = val;
	newList->prec  = NULL;
	newList->suiv  = tmp;
	tmp->prec = newList;

	return lst;
}

//#9 Insere un element a la position i
Listedc insererAlaPositionIdc(Listedc lst, int position, int val){
	Listedc tmp = lst;
	Listedc tmpSuiv = lst;
	int i =1;

	if (position ==1 )
	{
		Listedc newL = malloc(sizeof(Listedc));
		newL->val = val;
		newL->prec=lst;
		newL->suiv = NULL;
		return newL;
	}

	while(tmp != NULL && i < position){
		tmpSuiv =tmp; //use tmpSuiv to store tmp's suiv since, tmp's suiv value will become NULL after each iteration
		tmp = tmp->prec;
		i++;
	}

	if(i == position && tmp != NULL){
		Listedc newL = malloc(sizeof(Listedc));
		newL->val = val;
		newL->prec=tmp;
		newL->suiv = tmpSuiv;
		tmpSuiv->prec = newL;
		tmpSuiv = newL;
		return lst;
	}
	//else
	printf("Erreur: mauvaise position...");
	//exit(1);

	return lst;
}

//LDC MAIN METHOD
void listeDoublementChainees(){

	int choix = 1;
	int val = 0;
	int position = 0;
	int lenList = 0;
	Listedc lst = NULL;
	Placedc teteLst;
	
	do{
		printf("_____MENU DE MANIPULATIONS DES LISTES DOUBLEMENT CHAINEES:\n");
		printf("Faites votre choix : \n");

		printf(" -> 1 :Pour l'initialisation de la liste. \n");
		printf(" -> 2 :pour ajouter un element a la liste. \n");
		printf(" -> 3 :pour afficher la liste. \n");
		printf(" -> 4 :pour voir la tete de la liste.\n");
		printf(" -> 5 :pour voir le contenu du dernier element ajouté: \n");
		printf(" -> 6 :Pour accéder à la fin de la liste(suppression du dernier élément).\n");
		printf(" -> 7 :pour ajouter à la queue de la liste. \n");
		printf(" -> 8 :pour ajouter à une position choisie de la liste.\n");
		printf(" -> 9 :pour savoir la longueur de la liste.\n");
		printf("\n--> 0 :Pour Quitter.\n");

		scanf("%d", &choix);

		switch (choix){	
			case 1 : 
				printf("________\n\tcreer une nouvelle liste:\n");
				printf("Donner un entier : \n");
				scanf("%d", &val);
				lst = construitdc(listeVidedc(), val);
				printf("\n");
				break;

			
			case 2 : 
				printf("________\n\tAjout d'un élément à la liste :\n");
				printf("Donner un entier à ajouter à la liste :\n");
				scanf("%d", &val);
				lst = construitdc(lst, val);
				printf("\n");
				break;
			case 3 : 
				printf("\n\n________\n\tAffichage de la liste :\n");
				afficherListedc(lst);
				printf("_____________\n\n\n");
				break;
			case 4 : 
				teteLst = tetedc(lst);
				printf("________\n\tLa tête de la liste :\n");
				printf("Tete (val = %d, @prec = %p, @suiv = %p).\n", teteLst.val, teteLst.prec,teteLst.suiv);
				printf("_____________\n");
				break;
			case 5 : 
				teteLst = tetedc(lst);
				printf("________\n\tLe contenu du dernier élément ajouté :\n");
				printf("Tete : %d.\n", contenudc(teteLst));
				printf("_____________\n");
				break;
			case 6 : 
				printf("________\n\tAccès à la fin de la liste(exclure la tete) :\n");
				if (lst != NULL){
					lst = finListedc(lst);
				}
				printf("_____________\n");
				break;

			case 7 : 
				printf("________\n\tAjout à la queue de la liste :\n");
				printf("Donner un entier :\n");
				scanf("%d", &val);
				lst = ajoutFindc(lst, val);
				printf("\n");
				break;
			case 8 : 
				printf("________\n\tAjout à la position I de la liste :\n");
				printf("Donner un entier, puis donner sa position :\n");
				scanf("%d%d", &val, &position);

				lenList = calculerTailledc(lst);
				if (position > 0 && (position <=  lenList+ 1)){
					lst = insererAlaPositionIdc(lst, position, val);
				}
				printf("\n");
				break;
			case 9 : 
				printf("________\n\tLa longueur de la liste :\n");

				lenList = calculerTailledc(lst);
				printf("Longueur de la liste : %d\n", lenList);
				printf("\n");
				break;
			case 0 : exit(0);

			default : printf("Mauvais choix, veillez ressayer.");
		}

	} while (choix != 0);
}
////////////////////////  LDC   ///////////////////////////




///////////////////////LISTE CIRCULARE///////////////////////////////////////
typedef struct Placec Placec;
typedef Placec* Listec;

struct Placec {
 	int val; 
 	Listec suiv;
 };

struct  Managec
{
	Listec head;
	Listec tail;
	int len;
};

typedef struct Managec Managec;

//ManagecMENT METHODES

//#1 retourne une Listec vide
Listec ListeVidec(Managec* Managec){
	Managec->head = NULL;
	Managec->tail = NULL;
	Managec->len = 0;
	return NULL;
}

//#2 ajoute un element a la tete d'une Listec
Listec construitc(Listec lst, int val, Managec * Managec){
	Listec newL = malloc(sizeof(Listec)); 
	newL->val = val;
	newL->suiv = lst;
	
	if (lst == NULL)		
		Managec->head = Managec->tail = newL;
	else{
		Managec->head = newL;
		Managec->tail->suiv = newL;
	}
	
	Managec->len ++;
	return newL;
}

//#3 AFFICHER UNE Listec
void afficherListec(Listec lst, Managec* Managec){
	Listec tmp = lst;
	int len = Managec->len;
	
	while(len >0){//(tmp != lst){//(tmp != NULL){//
		printf("%d \n", (*tmp).val);
		tmp = tmp->suiv;
		len --;
	}
}


//#4retourne la tete d'une Listec(struct Placec : Placec)
Placec tetec(Listec lst){
	if(lst != NULL){		
		return (*lst); 
	}
	else {
		printf("La list est vide");
		//exit(1);
	}
}

//#5 retourne la valeur d'une Placec
int contenuc(Placec p){
	return p.val;
	//retourne le contenuc d'une case
}

//#6 retourne une Listec prive de la tete de la Listec d'entre
Listec finListec(Listec lst, Managec *Managec){
	if (lst == NULL){
		printf("Erreur\nLa Listec est vide.");
		//exit(1);
	}
	else{
		Listec l = lst->suiv;
		Managec->head = l;
		Managec->tail->suiv = Managec->head;
		Managec->len --;
		return l;	
	} 
		
}

//#7 RETOURNE LA TAILLE DE LA Listec
int calculerTaillec(Managec* Managec){
	return Managec->len;
}

//#8 AJOUTER UN ELEMENT A LA FIN DE LA Listec 
Listec ajoutFinc(Listec lst, int val, Managec* Managec){
	if(lst != NULL){
		Listec newL = malloc(sizeof(Listec));
		newL->val = val;
		newL->suiv = Managec->head;

		Managec->tail->suiv = newL;
		Managec->tail = newL;
		Managec->len++;
	}
	else{
		lst = construitc(lst, val, Managec);
	}

	return lst;
}

//#9 Insere un element a la position i
Listec insererAlaPositionIc(Listec lst, int position, int val, Managec* Managec){

	//CHECK POSITION VALIDITY
	if(position <1 || position > Managec->len){	
		printf("Erreur: mauvaise position...");
		return lst;
	}

	Listec tmp = lst;
	int i =1;
	Listec newL = malloc(sizeof(Listec));
	newL->val = val;

	//If the postion is the first one
	if (position == 1 ) //1 er position
	{
		newL->suiv = lst;
		Managec->head = newL;
		Managec->tail->suiv = newL;
		Managec->len++;
		return newL;
	}

	else {//if(position > 1 && position < Managec->len){

		//point to the postion just before the position to insert into
		while(tmp->suiv != Managec->tail && i < position-1){
			tmp = tmp->suiv;
			i++;
		}
		if(i == position-1){
			newL->suiv = tmp->suiv;
			tmp->suiv = newL;
			Managec->len++;
			return lst;
		}
	}
}

//LC'S MAIN
void listeCirculaire(){
	int choix = 1;
	int val = 0;
	int position = 0;
	int lenList = 0;
	Managec Managec;
	Listec lst = ListeVidec(&Managec);
	Placec teteLst;
	
	do{
		printf("_____MENU DE MANIPULATIONS DES ListecS CIRCULAIRES CHAINEES:\n");
		printf("Faites votre choix : \n");

		printf(" -> 1 :Pour l'initialisation de la Liste. \n");
		printf(" -> 2 :pour ajouter un element a la Liste. \n");
		printf(" -> 3 :pour afficher la Liste. \n");
		printf(" -> 4 :pour voir la tete de la Liste.\n");
		printf(" -> 5 :pour voir le contenu du dernier element ajouté: \n");
		printf(" -> 6 :Pour accéder à la fin de la Liste(suppression du dernier élément).\n");
		printf(" -> 7 :pour ajouter à la queue de la Liste. \n");
		printf(" -> 8 :pour ajouter à une position choisie de la Liste.\n");
		printf(" -> 9 :pour savoir la longueur de la Liste.\n");
		printf("\n--> 0 :Pour Quitter.\n");

		scanf("%d", &choix);
		//USE A TAB OF CHARS SO THAT YOU CAN CONTROL THE INPUT. IF CONFIRMS U CONVERT IT TO INT
		//input should be 1 char only, if chars[1] !='\0' : erreur
		//48 to 57

		switch (choix){	
			case 1 : 
				printf("______________________________\nInitialiser la Liste :\n");
				printf("______________________________|\n");
				printf("Donner un entier : \n");
				scanf("%d", &val);
				lst = construitc(ListeVidec(&Managec), val, &Managec);
				printf("\n");
				break;

			
			case 2 : 
				printf("________\n\tAjout d'un élément à la Liste :\n");
				printf("Donner un entier à ajouter à la Liste :\n");
				scanf("%d", &val);
				lst = construitc(lst, val, &Managec);
				printf("\n");
				break;
			case 3 : 
				printf("\n\n________\n\tAffichage de la Liste :\n");
				afficherListec(lst, &Managec);
				printf("_____________\n\n\n");
				break;
			case 4 : 
				teteLst = tetec(lst);
				printf("________\n\tLa tête de la Liste :\n");
				printf("Tete (val = %d, @suiv = %p).\n", teteLst.val, teteLst.suiv);
				printf("_____________\n");
				break;
			case 5 : 
				teteLst = tetec(lst);
				printf("________\n\tLe contenuc du dernier élément ajouté :\n");
				printf("Tete : %d.\n", contenuc(teteLst));
				printf("_____________\n");
				break;
			case 6 : 
				printf("________\n\tAccès à la fin de la Listec(exclure la tete) :\n");
				lst = finListec(lst, &Managec);
				printf("\n");
				break;

			case 7 : 
				printf("________\n\tAjout à la queue de la Liste :\n");
				printf("Donner un entier :\n");
				scanf("%d", &val);
				lst = ajoutFinc(lst, val, &Managec);
				printf("\n");
				break;
			case 8 : //STILL DOESN'T WORK
				printf("________\n\tAjout à la position I de la Liste :\n");
				printf("Donner un entier, puis donner sa position :\n");
				scanf("%d%d", &val, &position);

				
				lst = insererAlaPositionIc(lst, position, val, &Managec);

				printf("\n");
				break;
			case 9 : 
				printf("________\n\tLa longueur de la Liste :\n");

				lenList = calculerTaillec(&Managec);
				printf("Longueur de la Liste : %d\n", lenList);
				printf("\n");
				break;
			case 0 : exit(0);

			default : printf("Mauvais choix, veillez ressayer.\n");
		}

	} while (choix != 0);
}

//////////////////////////L C ////////////////////////////////////


//////////////////M A///////////////////////////////////////////
////////////////// I N//////////////////////////////////////////

//PROGRAM'S MAIN METHOD
int main(int argc, char const *argv[])
{
	int choixp;
	

	do{
		printf("\n\t____________________________________________________");
		printf("\n\tCHOISIR UNE STRUCTURE OU ENTRER 0 POUR TERMINER\n");
		printf("\t____________________________________________________");

		printf("\n1-LISTE SIMPLEMENT CHANEES\n");
		printf("\n2-LISTE DOUBLEMENT CHANEES\n");
		printf("\n3-LISTE CIRCULAIRE SIMPLEMENT CHANEES\n");
		printf("\n4-MANIPULATIONS DES GRANDS NOMBRES\n");
		printf("\n0-Quitter\n");
		scanf("%d", &choixp);

		switch (choixp){	
			case 1 : 
			printf("\nLISTE SIMPLEMENT CHANEES\n");
				listSimpleChaine();
				break;
			case 2 : 
			printf("\nLISTE DOUBLEMENT CHANEES\n");
				listeDoublementChainees();
				break;

			case 3 : 
			printf("\nLISTE CIRCULAIRE SIMPLEMENT CHANEES\n");
				listeCirculaire();
				break;

			case 4 : 
			printf("\nMANIPULATIONS DES GRANDS NOMBRES\n");
				printf("SUPER DUPPER GRAND NOMBRE\n");
				//GRAND NOMBRE
				break;

			default : 
			printf("\nMAUVAIS CHOIX, RESSAYER.\n");
				//GRAND NOMBRE
				break;

			case 0 : exit(0);
		}
	}while(choixp != 0);

	return 0;
}