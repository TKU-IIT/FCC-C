#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	FILE *pfile;
	struct profile *pstud;
	char buffer[256];
	char buf2[256];
	
	pfile=fopen("word.txt", "r");
	pstud=(struct profile *)malloc(sizeof(struct profile));

	while(fgets(buffer, 256, pfile)!=0){
		
		memcpy(pstud->name, buffer, 15);
		pstud->name[15]='\0';
		memcpy(pstud->city, buffer+16, 15);
		pstud->name[16+15]='\0';
		memcpy(buf2, buffer+16+16, 4);
		buf2[4]='\0';
		pstud->age=atoi(buf2);
		printf("name: %s\n", pstud->name);
		printf("city: %s\n", pstud->city);
		printf("age: %d\n\n", pstud->age);
	}
	
	fclose(pfile);
	free(pstud);
	return 0;
}