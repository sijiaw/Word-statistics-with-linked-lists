#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef
	struct Node {
		char *word;
		int fre;
 		struct Node *next;
	}Node;

Node *head;

char *read_Word(){
	int size=100;
	char *a=(char*)malloc(size * sizeof(char));
	int i=0;
	int flag=0;
	char c;

	c=getchar();
        while((isalpha(c)==0)&&(c!= EOF)){
		c=getchar();
	}


	if(c==EOF){
		return NULL;
	}
	else{
		while (isalpha(c)||isdigit(c)){
				a[i]=c;
				i++;
				c=getchar();
		}
		a[i]='\0';
		a = (char *)realloc(a, i);
		
		return a;
	}


}


void count(char *newword){
	if(head->next==NULL){
		Node *temp=(Node*)malloc(sizeof(Node));
		temp->word=newword;
		temp->next=head->next;
		temp->fre=1;
		head->next=temp;
		return;
	}

	Node *test=head->next;
	Node *before_test=head;
	while(test!=NULL&&strcmp(newword,test->word)>0){
                before_test=test;
		test=test->next;
		
	}
	if(test!=NULL && strcmp(newword,test->word)==0){
		test->fre=(test->fre)+1;
		return;
	}
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->word=newword;
	temp->fre=1;
	temp->next=test;
	before_test->next=temp;
}

void print(){
	Node* temp=head->next;
	while(temp!=NULL){
		printf("%15s", temp->word);
		printf("  %d\n",temp->fre);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;//empty list
	char *my_word=read_Word();
	while(my_word!=NULL){
		count(my_word);
		my_word=read_Word();
		
	}
	print();
	return 0;
}
