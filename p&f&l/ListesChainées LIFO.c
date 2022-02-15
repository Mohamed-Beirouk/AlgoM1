#include <stdio.h>
#include <stdlib.h>	


typedef struct place Place;//"stuct place" alias : place

struct place{
	int val;
	struct place *suivant; //struct Place * : un pointeur de type complexe, structure
};

//struct place * Liste;
typedef Place * Liste;
/* 
	Liste : alias de "struct Place*
	Liste = struct place *
	Lors de la compilation, tous les aleas sont remplaces
*/

int main(){
	Liste lst = construit(NULL, 10);
	lst = contruit(lst, 15);
	lst = contruit(lst, 20);
	
	afficherListe(lst);
		
	return 0;
}

Liste listeVide(){

	return NULL;
	//1 liste vide;C'est une var qui a comme valeur null
}

Place tete(Liste l){
	if(l != NULL){		
		//if the list's elements point to valid addresses
		return (*l);
	}
	else {
		printf("La list est vie");
		exit(1);
	/* On aura une exception, donc on appelle la fonct exit(1) : sortir et signaler une erreur	
		//exit(0) // exit sans erreur
		On sort du program et ne pas essayer d'acceder a un pointeur nulle. 
	*/
	}
	
	int contenu(Place p){
		return p.val;
		//retourne le contenu d'une case
	}	
	
	Liste construit(Liste l, int val){
		Place *p = malloc(sizeof(Place));  
		/*allocation manuelle de memoire(a la size de struct place)
			si non a chaque appel de la fonction l'OS donnera la meme adresse initial, qui sera libre, a p: pas de deplacement de p donc
		*/
		
		p->val = val;
		p->suivant = l;
		return p;

/*Our 1st version	
		if(l==listVide()){
					//Place p;
					
			//p.val = val;
			//p.suiv = NULL;

			l = p;
			//* Si la liste est vide, l'entree pointe vers null
		}
		else {
			p->val = val;
			p->suivant = l;
			l= p;
		}
		
		return l;
*/
	}
	
	void afficherList(Liste l ){
		Liste tmp = l; // tmp : se deplace dans la Liste l
		while(tmp != NULL){
			printf("%d ", (*tmp).val);
							//(*tmp).val =equivalent a= tmp->val
		}
	}
}























