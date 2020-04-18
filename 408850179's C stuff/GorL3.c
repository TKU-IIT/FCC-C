#include<stdio.h>
int main(int argc, char**argv){
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("%d", a);
	if(a<b){
		printf(" is less than ");
	}else{
		printf(" is greater than ");
	}
	printf("%d", b);
	return 0;
}