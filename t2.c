#include <stdio.h>
#include <stdlib.h>

struct profile{
	
	char name[16];
	char city[16];
	int age;
};

 
void readdata(struct profile *p){
	
	printf("In readdata()...\n");
	printf("The address that pointer p pointed at: %p\n\n", p);
	
	printf("Input your name: ");
	scanf(" %s", p->name);
	
	printf("Input the city you lived: ");
	scanf(" %s", p->city);
	
	printf("Input your age: ");
	scanf(" %d", &(p->age));
}

int main(){
	
	struct profile *pstud;

	pstud=(struct profile *)malloc(sizeof(struct profile));

	printf("In main()...\n");
	printf("The address of stud: %p\n\n", pstud);
	
	readdata(pstud);
	
	printf("\nname: %s", pstud->name);
	printf("\ncity: %s", pstud->city);
	printf("\nage: %d\n", pstud->age);
	
	free(pstud);
	return 0;
}