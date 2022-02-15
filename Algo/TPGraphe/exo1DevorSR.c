#include <stdio.h>
#include <stdlib.h>
double calculer(int n, int m);
int g(int n){
	if(n==0 ) return 1;
	return n*g(n-1);
}

int main(){
	int i, n=5;
	for(i=1; i<=n; i++){
		printf("%d\n", g(i));
	}
	printf("%lf\n",calculer(2,1) );
	printf("%lf\n",calculer(2,-1) );
	return 0;
}
double calculer(int n, int m){
	if(n==0) return 0;
	int mm = (m < 0 ? -m: m );
	double res = 1.0;
	int i;
	for(i=1; i<=mm; i++){
		res = res*n;
	}
	if(mm != m) return 1.0/res;
	return res;
}

