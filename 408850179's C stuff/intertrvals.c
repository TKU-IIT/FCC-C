#include<stdio.h>

int main(int argv, char **argc){
	int M, N, counter;
	double L;
	
	printf("Please enter number M:");
	scanf("%d", M);
	printf("Please enter number N:");
	scanf("%d", N);
	
	L = (N-M)/11.0;
	
	counter = 0;
	
	while(counter<=11){
		printf("%lf", M+counter*L);
		printf("\n");
		counter = counter + 1;
	}
	
	return 0;
}
