#include<stdio.h>
int main(int argc, char**argv){
	int a, b;
	
	a = 1050;
	b = 200;
	
	if(a<b){
		printf("%d", a);
		printf(" is less than ");
		printf("%d", b);
	}else{
		printf("%d", a);
		printf(" is greater than ");
		printf("%d", b);
	}
	return 0;
}