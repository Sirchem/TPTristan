#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct list* create(){
	struct list* newList =malloc(sizeof(struct list));
	newList->next = NULL;
	return newList;
}

void add(char* elt, struct list *l){
	while(l->next != NULL){
		l=l->next;
	}
	l->elt=elt;
	l->next=create();
}

int strcmpp(char* elt1, char* elt2){
	int i=0;
	while(elt1[i]==elt2[i]){
		if((elt1[i]=='\0')&&(elt2[i]=='\0'))
			return 1;
		i++;
	}
	//printf("elt1[%d]: %c and elt2[%d]: %c\n",i,elt1[i],i,elt2[i]);
	return 0;
}

size_t strlen(char* s)
{
	char* op = s;
	while(*s++);
	return (size_t)(s - op - 1);
}

int deleteElt(struct list* l,char* elt){
	if(l==NULL)
		return 1;
	if(l->elt== elt){
		struct list* fList = l;
		l=l->next;
		free(fList);
		return 0;
	}
	while((strcmpp(l->next->elt, elt)) != 1){
		if(l->next==NULL)
			return 1;
		l=l->next;
	}
	struct list* curList = l->next;
	l->next=l->next->next;
	free(curList);
	return 0;
}

void prettyprint(struct list* l){
	//Case where the list is empty or doesn't exist
	//if(l->elt==NULL){
	//	printf("empty list \n");
	//	return;
	//}
	printf("|--");
	while(l->next != NULL){
		printf("%s-",l->elt);
		l=l->next;
	}
	printf("-| \n");
}


void order(struct list* l){
	struct list* temp = l;
	while(temp != NULL && (temp->elt != NULL) && temp->next != NULL && (temp->next->elt != NULL)){
		if((strlen(temp->elt))>(strlen(temp->next->elt))){
			add(temp->elt,l);
			prettyprint(l);
			deleteElt(l,temp->elt);
			prettyprint(l);
			order(l);
		}
		temp=temp->next;
	}
}
