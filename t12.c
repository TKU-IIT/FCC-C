//linked list 123
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

struct profile{
	
	char name[16];		//指向此character array
	char city[16];
	int age;
	struct profile *next; 	//指向這個結構
}*first=NULL;

void display(struct profile *);
void disall(struct profile *);	//display all the data
void divdis(struct profile *);	//diversely display all the data
struct profile * findlast(struct profile *);		//idk
void search(struct profile *);	//search and print the data
void delete(struct profile *);	//search the data and delete it
void sortage(struct profile *);	//sort the data by the age
void add(struct profile *);		//add a new data
void readdata(struct profile *);
void quit(struct profile *);

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
		printf("options: 0. quit & save, 1. display all, 2. diversed display, 3. search name, 4. add new data, 5. search & delete\n\n");
		scanf(" %d", &num);
	
		switch(num){
				
			case 0:
				quit(first);
				return 0;
				
			case 1: 
				disall(first);
				break;
				
			case 2:
				divdis(first);
				break;
				
			case 3:
				search(first);
				break;
				
			case 4:
				add(first);
				break;
				
			case 5:
				delete(first);
				break;
		}
	}while(num);
	
}

void quit(struct profile *p){		//quit and save all the data to worddata
	
	struct profile *pre, *cur;
	char buf1[256];
	int fh, bw;
	
	if((fh=open("worddata", O_CREAT | O_TRUNC | O_RDWR,  S_IREAD | S_IWRITE))==-1){
		perror("ERROR!!!!!");
	}
	
	pre=NULL;
	cur=p;
	
	while(cur){
		
		
		memcpy(buf1, cur->name, 15);
		buf1[15]=' ';
		memcpy(buf1+16, cur->city, 15);
		buf1[16+15]=' ';
		sprintf(buf1+16+16, "%04d", cur->age);
		buf1[16+16+4]='\x0A';
		bw=write(fh, buf1, 16+16+4+1);
		
		pre=cur;
		cur=cur->next;
	}
	
	close(fh);
	
	return;
}

void display(struct profile *p){
	
	printf("name: %s\n", p->name); 		//first->name
	printf("city: %s\n", p->city); 		//first->city
	printf("age: %d\n\n", p->age);		//first->age
}

void disall(struct profile *p){		//display all the data
	
	if(p){ 		//if(p)=if(p!=NULL)
		display(p);
		disall(p->next);	
	}
}

void divdis(struct profile *p){		//diversely display all the data
	
	if(p){ 		//if(p) = if(p!=NULL)
		divdis(p->next);
		display(p);
	}
}

struct profile * findlast(struct profile *k){		//idk
	
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

void search(struct profile *p){		//search and print the data
	
	struct profile *cur, *pre;
	char target[16];
	char buf[16];
	int result;
	
	pre=NULL;
	cur=p;
	
	if(p==NULL){
		printf("No data!\n");
		return;
	}
	
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

void delete(struct profile *p){		//search the data and delete it
	
	struct profile *cur, *pre;
	char target[16];
	char buf[16];
	int result;
	
	if(p==NULL){
		printf("No data!\n");
		return;
	}
	
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
	
	pre=NULL;
	cur=p;
	
	result=memcmp(buf, cur->name, 15);
	if(result==0){		//if the first node is the target
		first=cur->next;
		printf("Delete success!\n");
		free(cur);
		return;
	}else{
		while(result!=0){
			if(cur->next){
				pre=cur;
				cur=cur->next;
				result=memcmp(buf, cur->name, 15);
			}else{
				printf("Not found! Delete fail!\n");
				return;
			}
		}
		pre->next=cur->next;
		printf("Delete success!\n");
		free(cur);
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

void add(struct profile *p){		//add a new data
	
	struct profile *cur, *pre, *new;
	
	new=(struct profile *)malloc(sizeof(struct profile));
	
	printf("Input name: ");
	scanf("%s", new->name);
	for(int c=0; c<15; c++){
		if(new->name[c]=='\0'){
			while(c<15){
				new->name[c]=' ';
				c++;
			}
			break;
		}
	}
	new->name[15]='\0';
	
	printf("\nInput city: ");
	scanf("%s", new->city);
	for(int c=0; c<15; c++){
		if(new->city[c]=='\0'){
			while(c<15){
				new->city[c]=' ';
				c++;
			}
			break;
		}
	}
	new->city[16+15]='\0';
	
	printf("\nInput age: ");
	scanf("%d", &(new->age));
	printf("\n");
	
	pre=NULL;
	cur=p;
	
	new->next=cur;
	p=new;
	sortage(p);
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