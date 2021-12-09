#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
typedef struct HashTable HashTable;
struct HashTable{
	char nom[256];
	HashTable *suiv;
};
typedef HashTable *hash;
HashTable *TableHash[N];
void Initialiser(){
	int i;
	for(i=0;i<N;i++)
		TableHash[i]=NULL;
}
hash hashVide(){
	return NULL;
}
int asci2(char str[]){
	int s =0,i=0;
	while(i<strlen(str)){
		s = s + str[i];
		i++;
	}
	return s;
}
hash ajouter(char nom[]){
	hash n1, n2;
	int ascii, pos, existe=0;
	n1 = malloc(sizeof(hash));
	strcpy(n1->nom,nom);
	n1->suiv=NULL;
	ascii = asci2(nom);
	pos = ascii % N;
	if(TableHash[pos]==NULL){
		TableHash[pos] = n1;
	}else{
		for(n2=TableHash[pos];n2->suiv!=NULL;n2=n2->suiv){
			if(!strcmp(n1->nom,n2->nom)){
				existe = 1;
				printf("Cette personne existe deja");
				exit(1);
				break;
			}
		}
		if(!strcmp(n1->nom,n2->nom)){
			printf("Cette personne existe deja");
				exit(1);
		}
		if(!existe){
			n2->suiv = n1;
		}	
	}
	return TableHash[pos];
}

hash rechercher(char nom[]){
	int ascii, pos, existe=0;
	ascii = asci2(nom);
	pos = ascii % N;
	hash n2;
	for(n2=TableHash[pos];n2!=NULL;n2=n2->suiv){
		if(!strcmp(n2->nom,nom)){
			existe= 1;
			return TableHash[pos];
		}
	}
	if(!existe){
		printf("Cette personne n'existe pas");
		exit(1);
	}
}
void afficher(){
	int i=0;
	hash h;
	while(i<N){
		h = TableHash[i];
		if(h!=NULL){
			if(h->suiv==NULL){
				printf("TableHash[%d] = [%s]\n",i,h->nom);
			}else{
				printf("TableHash[%d] = ",i);
				for(;h!=NULL;h=h->suiv){
					printf("[%s] ",h->nom);
				}
				printf("\n");
			}
		}
		i++;
	}
}
void main(){
	hash h;
	h = ajouter("Cheibette");
	h = ajouter("Sidi");
	h = ajouter("Abdi");
	h = ajouter("begin");
	h = ajouter("for");
	h = ajouter("cd");
	h = ajouter("cn");
//	afficher();
rechercher("Sidi");
}

