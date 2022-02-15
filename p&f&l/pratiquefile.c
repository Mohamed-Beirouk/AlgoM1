#include<stdio.h>
#include<stdlib.h>
typedef struct place place;
struct place{
	int val;
	struct place *suivant;
};
typedef struct file file;
struct file{
	place *debut;
	place *fin;
};

file newfile(file f){
	f.debut = NULL;
	f.fin = NULL;
}

int estvide(file f){
	if(f.debut==NULL){
		return 0;
	}
	return 1;
}

int tete(file f){
	
	if(f.debut==NULL){
		printf("file vide, impossible!!");
		exit(1);
	}
	return f.debut->val;
	
}
file enfiler(file f, int x){
	place *q=malloc(sizeof(place));
	q->val=x;
	q->suivant=NULL;
	if(f.debut==NULL){
		f.debut=q;
		f.fin=q;
		
	}
	else{
		f.fin->suivant=q;
		f.fin=q;
		
	}
	return f;
}
file defiler(file f){
	file t =f;
	if(t.debut=NULL){
		printf("file vide, impossible de la defiller");
	}
	else{
		t.debut=(f.debut)->suivant;
	}
	return t;
}
void afficher(file f){
	
	if(f.debut==NULL){
		printf("vide");
	}
	file t =f;
	while(t.debut!=NULL){
		printf(" -%d- ",t.debut->val);
		t.debut=t.debut->suivant;
	}
}

void main(){
	
	file f = newfile(f);
	f=enfiler(f,5);
	f=enfiler(f,6);
	f=enfiler(f,7);
	f=enfiler(f,8);
	
	afficher(f);
	printf("\n------------------\n");
	f = defiler(f);
	afficher(f);
	
	
	
	
	int z=0;
}
