#include<stdio.h>

int main(int argv, char **argc){
	int n, m, K, c;
	double L, N, M;
	
	printf("m=");
	scanf("%d", &m);
	printf("n=");
	scanf("%d", &n);
	printf("K=");
	scanf("%d", &K);
	
	if(m<n){
		M=m;
		N=n;
	}else{
		M=n;
		N=m;
	}
		
	L = (N-M)/K;
	
	if(m<n){
		c = 0;
		while(c<=K){
			printf("%ls", M+c*L);
			printf("\n");
			c = c + 1;
		}
	}else{
		c = K;
		while(c>=0){
			printf("%ls", M+c*L);
			printf("\n");
			c = c + 1;
	}
	return 0;
}