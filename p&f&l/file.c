#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct File File;
struct File{
	int debut;
	int fin;
	int compteur;
	int place[N];
};

File fileVide(){
	File f;
	f.compteur = 0;
	f.debut = 0;
	f.fin = 0;
	return f;
}
int estPlein(File f){
	if(f.compteur==N)
		return 1;
	return 0;
}

File enfiler(File f){
	
}
void main(){
	
}
