#include<stdio.h>
int main(int argc, char**argv){
	double a, b;

	scanf("%lf", &a);
	scanf("%lf", &b);
	
	printf("%lf", a);
	if(a<b){
		printf(" is less than ");
	}else{
		printf(" is greater than ");
	}
	printf("%lf", b);
	return 0;
}