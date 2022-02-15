#include<stdio.h>
#include<stdlib.h>

typedef struct place place;
struct place{
	char  expression;
	place *suivant;
};
typedef place* element;

void main(){
	
	element a = NULL;
	a = malloc(sizeof(place));
	a->expression='beirouk';
	a->suivant=NULL;
	printf("%c",a->expression);
	
	int z=0;
}





