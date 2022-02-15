#include<stdio.h>
#include<stdlib.h>

typedef struct place place;

struct place{
	int val;
	struct place *prec;
	
};
typedef place *pile;
pile pilevide(){
	return NULL;
}

int pileestvide(pile p){
	if(p == NULL){
		return 0;
	}
	else return 1;
}
pile empiler(pile p, int x){
	
	pile nv = pilevide();
	nv = malloc(sizeof(pile));
	nv->val = x;
	if(pileestvide(p)==0){
		nv->prec=NULL;
		p=nv;
		return p;
	}
	nv->prec = p;
	p=nv;
	return p;
	
	
}
pile depiler(pile p){
	
		if(pileestvide(p)==0){
		printf("eurreur");
		return 0;
		}
		
		p=p->prec;
		return p;
}

void main(){
	
	pile p1 = pilevide();
	p1 = malloc(sizeof(place));
	p1 = empiler(p1, 5);
	p1 = empiler(p1, 6);
	p1 = empiler(p1, 7);
	p1 =depiler(p1);
	
	printf("%d",p1->val);

	
	
	
	
	
	
	
}


