#ifndef MYQUEUE_
#define MYQUEUE_

typedef struct Liste Liste;
struct Liste{
Liste *suiv;
int val;
};

struct MyQueue{
 Liste *debut;
 Liste *fin;
};
typedef struct MyQueue MyQueue;
#endif /*MYQUEUE_*/
