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
	
	struct profile stud;
	
	printf("In main()...\n");
	printf("The address of stud: %p\n\n", &stud);
	
	readdata(&stud);
	
	printf("\nname: %s", stud.name);
	printf("\ncity: %s", stud.city);
	printf("\nage: %d\n", stud.age);
	
	return 0;
}