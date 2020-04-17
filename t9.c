//linked list 123
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile{
	
	char name[16];		//指向此character array
	char city[16];
	int age;
	struct profile *next; 	//指向這個結構
}*first=NULL;

void display(struct profile *p){
	
	printf("name: %s\n", p->name); 		//first->name
	printf("city: %s\n", p->city); 		//first->city
	printf("age: %d\n\n", p->age);		//first->age
}

void disall(struct profile *p){
	
	if(p){ 		//if(p)=if(p!=NULL)
		display(p);
		disall(p->next);	
	}
}

void divdis(struct profile *p){
	
	if(p){ 		//if(p) = if(p!=NULL)
		divdis(p->next);
		display(p);
	}
}

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

void search(struct profile *p){
	
	struct profile *cur, *pre;
	char target[16];
	char buf[16];
	int result;
	
	pre=NULL;
	cur=p;
	
	printf("Input the name: ");
	scanf("%s", target);
	for(int c=0; c<15; c++){
		if(target[c]=='\0'){
			while(c<15){
				buf[c]=' ';
				c++;
			}
			break;
		}else{
			buf[c]=target[c];
		}
	}
	printf("\n");
	
	while(cur->next){
		result=strcmp(buf, cur->name);
		
		if(result==0){
			display(cur);
			return;
		}else{
			if(cur->next){
				pre=cur;
				cur=cur->next;
			}else{
				printf("Not found\n");
				return;
			}
		}
	}
	
	result=memcmp(buf, cur->name, 15);
	if(result==0){
		display(cur);
		return;
	}else{
		printf("Not found\n");
		return;
	}
}

void sortage(struct profile *p){ 	//sort the data by the age
	
	struct profile *cur, *pre;
	
	if(first==NULL){
		p->next=NULL;
		first=p;
		return;
	}else{
		pre=first;
		cur=first;
		while(pre){
			if(pre->age > p->age){
				p->next=pre;
				if(pre==first){
					first=p;
					return;
				}else{
					cur->next=p;
					return;
				}
			}else{
				if(pre==cur){
					pre=pre->next;
				}else{
					pre=pre->next;
					cur=cur->next;
				}
			}
		}
		
		if(pre==NULL){
			cur->next=p;
			p->next=NULL;
			return;
		}
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
	struct profile *pstud;
	char buffer[256];
	char buf2[256];
	int num;
	
	pfile=fopen("word.txt", "r");
	
	while(fgets(buffer, 256, pfile)!=0){
		
		pstud=(struct profile *)malloc(sizeof(struct profile));
	
		memcpy(pstud->name, buffer, 15);
		pstud->name[15]='\0';
		memcpy(pstud->city, buffer+16, 15);
		pstud->name[16+15]='\0';
		memcpy(buf2, buffer+16+16, 4);
		buf2[4]='\0';
		pstud->age=atoi(buf2);
		
		sortage(pstud);
	}
	
	fclose(pfile);
	
	
	do{
		printf("options: 0. quit, 1. display all, 2. diversed display, 3. search name\n\n");
		scanf(" %d", &num);
	
		switch(num){
				
			case 1: 
				disall(first);
				break;
				
			case 2:
				divdis(first);
				break;
				
			case 3:
				search(first);
				break;
		}
	}while(num!=0);
	
	free(pstud);
	return 0;
}