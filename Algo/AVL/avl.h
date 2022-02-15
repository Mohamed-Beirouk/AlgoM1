#ifndef AVL_H_
#define AVL_H_
#define MAX 1000
typedef struct noeud{
    int val;
    int deseq;
    struct noeud * g;
    struct noeud * d;
}noeud;
typedef noeud * AVL;
typedef struct Pile_A{
    int sommet;
    int n;
    AVL * elements[MAX];
}Pile;
AVL RG(AVL av);
AVL RD(AVL av);
AVL RDG(AVL av);
AVL RGD(AVL av);
AVL arbreVide();
int estVide(AVL av);
AVL adjoindre(AVL av, int e);
void prefix(AVL av);
void infixe(AVL av);
void postfixe(AVL av);
void prefix_D(AVL av);
AVL succ(AVL av, Pile *p);
AVL suppABR(AVL av, int e, Pile * p);
AVL suppAVL(AVL av, int e);

// algo de pile 
Pile pileVide();

int estVideP(Pile *p);

Pile empiler(Pile p, AVL *e);

void depiler(Pile *p);

AVL * sommet(Pile *p);

void copier(Pile p, Pile  *q);
int estVideP2(const Pile p) ;
#endif /*AVL_H_*/
