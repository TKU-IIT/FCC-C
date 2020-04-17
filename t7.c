//linked list 123
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile{
	
	char name[16];		//指向此character array
	char city[16];
	int age;
	struct profile *next; 	//指向這個結構
};

void display(struct profile *pstud){
	
	printf("name: %s\n", pstud->name); 		//first->name
	printf("city: %s\n", pstud->city); 		//first->city
	printf("age: %d\n\n", pstud->age);		//first->age
}

void disall(struct profile *p){
	
	if(p){ 		//if(p)=if(p!=NULL)
		display(p);
		disall(p->next);	
	}
}
/*
void disall(struct profile *pstud){ 		//ptr隨便設(funtion那一套)
	
	if(pstud==NULL)
		printf("\nNo data!\n");
	else{
		do{
			display(pstud);			//display(first)
			pstud=pstud->next;		//first=first->next
		}while(pstud!=NULL); 		//first!=NULL
	}
}
*/
struct profile * findlast(struct profile *k){
	
	struct profile *p;
	
	if(k==NULL)
		return NULL;
	else{
		do{
			p=k;
			k=k->next;
		}while(k!=NULL);
		return p;
	}
}

void divdis(struct profile *p){
	
	if(p){ 		//if(p)=if(p!=NULL)
		divdis(p->next);
		display(p);
	}
}

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
	struct profile *pstud, *first, *cur;
	char buffer[256];
	char buf2[256];
	int num;
	
	pfile=fopen("word.txt", "r");
	first=NULL;
	
	while(fgets(buffer, 256, pfile)!=0){
		
		pstud=(struct profile *)malloc(sizeof(struct profile));
	
		memcpy(pstud->name, buffer, 15);
		pstud->name[15]='\0';
		memcpy(pstud->city, buffer+16, 15);
		pstud->name[16+15]='\0';
		memcpy(buf2, buffer+16+16, 4);
		buf2[4]='\0';
		pstud->age=atoi(buf2);
		
		pstud->next=NULL;
		if(first==NULL){
			first=pstud;
		}else{
			cur=findlast(first);
			cur->next=pstud;
		}
	}
	
	fclose(pfile);
	
	
	do{
		printf("options: 0. quit, 1. display all, 2. diversed display\n\n");
		scanf(" %d", &num);
	
		switch(num){
				
			case 1: 
				disall(first);
				break;
				
			case 2:
				divdis(first);
				break;
		}
	}while(num!=0);
	
	free(pstud);
	return 0;
}