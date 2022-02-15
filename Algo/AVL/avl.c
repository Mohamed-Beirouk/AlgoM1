#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
AVL arbreVide() {
	return NULL;
}
int estVide(AVL av) {
	int result = (av == NULL);
	return result;
}
AVL RG(AVL av) {
	if(av !=NULL && av->d !=NULL) {
		AVL a2 = av->d;
		av->d = a2->g;
		a2->g = av;
		av =  a2;
	}
	return av;
}
AVL RD(AVL av){
	if(av !=NULL && av->g !=NULL) {
		AVL a1 = av->g;
		av->g = a1->d;
		a1->d = av;
		av =  a1;
	}
	return av;
}
void prefix(AVL av) {
	if(!estVide(av)) {
		printf("%d ", av->val);
		prefix(av->g);
		prefix(av->d);
	}
}
void infixe(AVL av) {
	if(!estVide(av)) {
	    infixe(av->g);
	    printf(" %d ", av->val);
		infixe(av->d);
	
	}
}
void postfixe(AVL av) {
	if(!estVide(av)) {
	    postfixe(av->g);
		postfixe(av->d);
		printf(" %d ", av->val);
	}
}
void prefix_D(AVL av) {
	if(!estVide(av)) {
		printf("%d ", av->deseq);
		prefix_D(av->g);
		prefix_D(av->d);
	}
}
AVL RDG(AVL av){
	av->d = RD(av->d);
	av = RG(av);
	return av;
}
AVL RGD(AVL av){
	av->g = RG(av->g);
	av = RD(av);
	return av;
}
AVL adjoindre(AVL av, int e) {
    AVL y, a, p, aa, pp;
	/* céér un nouveau noeud avec val =e  */
	y = malloc(sizeof(noeud)); 
	y->val = e; 
	y->deseq =0;
	y->g=NULL;
	y->d=NULL;
	if(estVide(av)){
		return y;
	}
	else{
		// on doit mettre les déséquilibres à  jour
		// même si l'arbre reste AVL, donc a pointe vers av
		a=av; aa=NULL; p=av; pp=NULL;
		/*aa et pp sont les peres de a et p*/
		while(p!=NULL){/*descente mémorisation du dernier noeud dont le déséquilibre est ±1*/
			if(p->deseq !=0){
				a=p;aa=pp;
			}
			pp=p;
			if(e==p->val) return av; // element déja dans l'arbre
			else if(e<=p->val)
				p=p->g;
			else p=p->d;
		}
		/*adjonction*/
		// 1. Ecrire les instructions qui permettent à adjoindre l'élement e ici
		
		/*modification du déséquilibre sur le chemin de A à  Y*/
		p=a;
		while (p != y) {
			if (e <= p->val){
			//2. ecrire les intructions necessaires ici
			}
			else{
				//3. ecrire les intructions necessaires ici
			}
		}
	/*	if(y != NULL){
			free(y);
			y = NULL;
		}*/
		/* réequilbrage*/
		switch (a->deseq){
		case 0:
		case 1:
		case -1: return av;
		case 2 : 
			switch (a->g->deseq){
				case 1: { 
					// 3. Ecrire les instructions necessaires ici
					break;
				}
				case -1: {
					a = RGD(a);
					switch (a->deseq){
					case 1: { /* 4. ecrire ici*/;break;}
					case -1: {/* 5. ecrire ici*/;break;}
					case 0: {/* 6. ecrire ici*/;break;} /*a=y*/
					}
					a->deseq=0;
					break;
				}
			}
			break;
		case -2 :
		switch (a->d->deseq){
						case -1: { 
							// 7. ecrire ici
							break;
						}
						case 1: {
							a = RDG(a);
							switch (a->deseq){
							case 1: {/* 8. ecrire ici*/break;}
							case -1: {/* 9. ecrire ici*/break;}
							case 0: {/* 10. ecrire ici*/break;} /*a=y*/
							}
							a->deseq=0;
							break;
						}
					}
			break;
		}
		if(aa==NULL)
			av=a;
		else if (a->val<=aa->val)
			aa->g=a;
		else aa->d=a;
		}
		return av;
	}

// fonction qui retourne le successeur dans noeud double
AVL succ(AVL av, Pile * p) {
	AVL result = NULL;
	if(!estVide(av)) {
		AVL d = av->d;
		if( !estVide(d)) {
			result = d;
			while(!estVide(d->g)) {
				AVL copyD = d;
				*p = empiler(*p, &copyD);
				d = d->g;
				result = d;
			}
		}
		
		
	}
	return result;
}
AVL supprimerF(AVL pereP, AVL P, AVL A ) {
	if(pereP == NULL) {
		A = NULL;
		P = NULL;
		return NULL;
	} else {
		if(pereP ->g ==P) {
			pereP ->g = NULL;
			// mis Ã  jour desq
			pereP->deseq = pereP->deseq -1;
		} else {
			// mis Ã  jour desq
			pereP->deseq = pereP->deseq + 1;
			pereP ->d = NULL;
		}
		return A;
	}
	
}
AVL supprimerSg(AVL pereP, AVL P, AVL A ) {
	if(pereP == NULL) {
			A = A->g;
			P = NULL;
			return A;
	} else {
			if(pereP ->g == P) {
				pereP ->g = P->g;
				// mis Ã  jour deseq
				pereP->deseq = pereP->deseq -1;
			} else {
				pereP ->d = P->g;
				// mis Ã  jour deseq
				pereP->deseq = pereP->deseq +1;
			}
			P = NULL;
			return A;
		}
}
AVL supprimerSd(AVL pereP, AVL P, AVL A ) {
	if(pereP == NULL) { // suppression de la racine
			A = A->d;
			P = NULL;
			return A;
	} else {
			if(pereP ->g == P) {
				pereP ->g = P->d;
				// mis Ã  jour deseq
				pereP->deseq = pereP->deseq -1;
			} else {
				pereP ->d = P->d;
				// mis Ã  jour deseq
				pereP->deseq = pereP->deseq +1;
			}
			P = NULL;
			
			return A;
		}
}
AVL supprimerD(AVL pereP, AVL P, AVL A,  Pile *pil) {
	AVL successeur = succ(P, pil);
	P->val = successeur->val;
//	AVL Psucc = *sommet(pil);
AVL Psucc = NULL;
	if(pil != NULL && pil->sommet > -1 ){
		Psucc = *(pil->elements[pil->sommet]);
	} 
	
	if(successeur->d == NULL && successeur->g == NULL) {
		if(Psucc->g == successeur) {
			// mis Ã  jour de facteur de dÃ©sequilibre du pere de succ
			Psucc->deseq = Psucc->deseq -1;
			Psucc->g = NULL;
		} else {
			//mis Ã  jour de facteur de dÃ©sequilibre du pere de succ
			Psucc->deseq = Psucc->deseq + 1;
			Psucc->d = NULL;
		}
	} else {
		if(Psucc->g == successeur) {
			// mis Ã  jour de facteur de dÃ©sequilibre du pere de succ
			Psucc->deseq = Psucc->deseq -1;
			Psucc->g = successeur->d;
		} else {
			//mis Ã  jour de facteur de dÃ©sequilibre du pere de succ
			Psucc->deseq = Psucc->deseq + 1;
			Psucc->d = successeur->d;
		}
	}
	return A;
}
AVL suppABR(AVL av, int e, Pile *p) {
	AVL temp = av;
	AVL tempCpy = NULL;
	AVL pere = NULL;
	int found = 0;
	while(temp != NULL && !found){
		if(temp ->val == e) {
			found = 1; // element trouvé
			if(temp->d == NULL && temp->g == NULL) {
				av = supprimerF(pere, temp, av);
			} else if(temp->g != NULL && temp->d == NULL) {
				av = supprimerSg(pere, temp,av ); // simple gauche
			} else if(temp->g == NULL && temp->d != NULL) {
				av = supprimerSd(pere, temp, av); // simple droit
			} else { // double
				tempCpy  = temp;
				*p = empiler(*p, &tempCpy);
			av = supprimerD(pere, temp, av,  p);
			}
		}else if(temp ->val > e) {
			tempCpy  = temp;
			*p = empiler(*p, &tempCpy);
			pere = temp;
			temp = temp->g;
		}else {
			tempCpy  = temp;
			*p = empiler(*p, &tempCpy);
			pere = temp;
			temp = temp->d;
		}
	}
	temp = NULL;
	pere = NULL;
	return av;
}
void reequilibrerD(AVL *A){
	if((*A)->d->deseq == 0) {
			*A = RG(*A);
			(*A)->deseq = +1;
			(*A)->g->deseq = -1;
		}else if((*A)->d->deseq == -1) {
			*A = RG(*A);
			(*A)->deseq = 0;
			(*A)->g->deseq = 0;
		}else{
			if((*A)->d->g->deseq == 0){
				*A = RDG(*A);
				(*A)->deseq = 0;
				(*A)->g->deseq = 0;
				(*A)->d->deseq = 0;
			}else if((*A)->d->g->deseq == -1){
				*A = RDG(*A);
				(*A)->deseq = 0;
				(*A)->g->deseq = +1;
				(*A)->d->deseq = 0;
			}else{
				*A = RDG(*A);
				(*A)->deseq = 0;
				(*A)->g->deseq = 0;
				(*A)->d->deseq = -1;
			}
		}
	
}
void reequilibrerG(AVL *A){
	if((*A)->g->deseq == 0) {
		*A = RD(*A);
		(*A)->deseq = -1;
		(*A)->d->deseq = 1;
	}else if((*A)->g->deseq == 1) {
		*A = RD(*A);
		(*A)->deseq = 0;
		(*A)->d->deseq = 0;
	}else{
		if((*A)->g->d->deseq == 0){
			*A = RGD(*A);
			(*A)->deseq = 0;
			(*A)->g->deseq = 0;
			(*A)->d->deseq = 0;
		}else if((*A)->g->d->deseq == 1){
			*A = RGD(*A);
			(*A)->deseq = 0;
			(*A)->g->deseq = 0;
			(*A)->d->deseq = -1;
		}else{
			*A = RGD(*A);
			(*A)->deseq = 0;
			(*A)->g->deseq = +1;
			(*A)->d->deseq = 0;
		}
	}
}
AVL suppAVL(AVL av, int e) {
	Pile p = pileVide();
	av = suppABR(av, e, &p);
	if(av == NULL) return NULL; // un seul noeud et supprimé
	AVL *a = sommet(&p);
	if(a == NULL) { // c'est la racine qui a eté supprimée
		if(av->deseq >=-1 && av->deseq <=1) return av; // arbre équilibré
		else { // on équilibre la racine avec les algo d'équilibrage
			if(av->deseq == -2) {
					reequilibrerD(&av);
			} else if(av->deseq == 2) {
					reequilibrerG(&av);
			}
			return av;
		}
	}
	// si on est là  c-a-d que ce qui a été supprimé ce n'est pas la racine
	if((*a)->deseq == -2) {
		reequilibrerD(a);
	} else if((*a)->deseq == 2) {
		reequilibrerG(a);
	}
	if(p.n == 1) { // a commenter
		av = *a;
	}
	int flag = ((*a)->deseq != -1 && (*a)->deseq != 1) ? 0 : 1;
	AVL *fils = a;
	depiler(&p);
	a = sommet(&p);
	while(a != NULL &&  !flag) {
		// TODO mettre à  jour les facteurs de A
		if((*a)->g == *fils) {
			(*a)->deseq = (*a)->deseq -1; // valeur supprimé Ã  gauche
		} else {
			(*a)->deseq = (*a)->deseq +1;
		}
   		if((*a)->deseq == -2) {
			reequilibrerD(a);
			flag = ((*a)->deseq != -1 && (*a)->deseq != 1) ? 0 : 1;
			fils = a;
			depiler(&p);
			a = sommet(&p);
		} else if((*a)->deseq == 2) {
			reequilibrerG(a);
			flag = ((*a)->deseq != -1 && (*a)->deseq != 1) ? 0 : 1;
			fils = a;
			depiler(&p);
			a = sommet(&p);
		} else if((*a)->deseq == 0) {
			fils = a;
			depiler(&p);
			a = sommet(&p);
		} else {
			flag = 1;
			
		}
	}
	return av;
}
// implémentation d'algo de piles d'AVL
Pile pileVide() {
	Pile p;
	p.sommet = -1;
	/*
	int i=0;
	for(i=0;i<MAX; i++){
		p.elements[i]= malloc(sizeof(noeud));
		if(p.elements[i] == NULL) exit(0);
	}*/
	p.n = 0;
	return p;
}
int estVideP(Pile *p) {
	if(p->n==0) {
		return 1;
	} else return 0;
}
Pile empiler(Pile p, AVL *e) {
	if(p.n>= MAX) {
		printf("erreur d'empilement : pile remplie");
		exit(0);
	} else {
		p.sommet++;
		p.elements[p.sommet] = e;
		p.n = p.n+1;
		return p;
	}
}
void depiler(Pile *p) {
	if(estVideP(p) == 1) {
		printf("erreur de depilement : pile vide");
		exit(0);
	} else {
		p->sommet--;
		p->n--;
	}
}
AVL *sommet(Pile *p) {
	if(estVideP(p)) {
		return NULL;
	} else {
		AVL  *result = p->elements[p->sommet];
		return result;
	}
}

