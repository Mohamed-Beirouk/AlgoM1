#ifndef GRAPH_
#define GRAPH_
#define MAXS 100
#define F 0
#define T 1

typedef int boolean;
typedef struct{

 boolean   adj[MAXS][MAXS];
 int sommets[MAXS];
 int N;
}Graphe;

/*
struct Adj
{
int label;
struct Adj *suiv;
};
struct Sommet {
int label;
struct Sommet *suiv;
struct Adj *lsAdj;
};
typedef struct  Sommet *Graphe3;*/
#endif /*GRAPH_*/
