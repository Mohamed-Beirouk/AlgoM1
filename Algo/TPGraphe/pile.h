#ifndef PILE_
#define PILE_

typedef struct Place Place;
struct Place{
Place *prec;
int val;
};
typedef struct Place *Pile;

#endif /*PILE_*/
