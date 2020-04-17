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
	
	FILE *pfile;
	char buffer[16+16+4+4];
	int i;
	
	
	pfile=fopen("word.txt", "w+");
	
	struct profile *pstud;
	
	pstud=(struct profile *)malloc(sizeof(struct profile));

	printf("In main()...\n");
	printf("The address of stud: %p\n\n", pstud);
	
	readdata(pstud);
	sprintf(buffer, "%-16s%-16s%04d\n", (*pstud).name, (*pstud).city, (*pstud).age); 
	fputs((char *)buffer, pfile);	//sprintf can use assigned format
	
	readdata(pstud);
	sprintf(buffer, "%-16s%-16s%04d\n", (*pstud).name, (*pstud).city, (*pstud).age);
	fputs((char *)buffer, pfile);
	
	fclose(pfile);
	free(pstud);
	
	return 0;
}