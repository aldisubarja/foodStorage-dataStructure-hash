#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int tableSize = 100;

struct tnode{
	char name[100];
	int price;
	int key;
	struct tnode *next;
};

struct hashPool{
	struct tnode *head;
	struct tnode *tail;
};

struct hashPool hashTable[tableSize];

int generateKey(char *name){
	int result=0;
	for(int i=0;i<strlen(name);i++){
		result+=name[i];
	}
	return result%tableSize;
}

struct tnode *newNode(char *name,int price){
	struct tnode *curr = (struct tnode*) malloc(sizeof(struct tnode));
	strcpy(curr->name,name);
	curr->price=price;
	curr->key=generateKey(name);
	curr->next=NULL;
	return curr;
}

void insert(struct tnode *node){
	if(hashTable[node->key].head==NULL){
		hashTable[node->key].head=hashTable[node->key].tail=node;
	}else{
		hashTable[node->key].tail->next=node;
		hashTable[node->key].tail=node;
	}
}

void print(){
	for(int i=0;i<tableSize;i++){
		printf("%d. ",i);
		struct tnode *curr = hashTable[i].head;
		while(curr!=NULL){
			printf("%s(%d) -> ",curr->name,curr->price);
			curr=curr->next;
		}
		printf("\n");
	}
}

int main(){
	
	int menu;
	
	do{
		for(int i=0;i<30;i++){
			printf("\n");
		}
		printf("Food Storage\n");
		printf("============\n");
		printf("1. Insert\n");
		printf("2. View All\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d",&menu); getchar();
		switch(menu){
			case 1:
				char name[100];
				int price;
				printf("Input Food's Name' >> ");
				scanf("%s",name); getchar();
				printf("Input Food's Price' >> ");
				scanf("%d",&price); getchar();
				insert(newNode(name,price));
				break;
			case 2:
				print();
				getchar();
				break;
			default:
				break;
		}
	}while(menu!=3);
	
	return 0;
}
