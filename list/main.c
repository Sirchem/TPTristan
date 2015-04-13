#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	struct list* l =create();
	add("UN",l);
	add("FOUR",l);
	add("THREE",l);
	add("TWO",l);
	add("ONE",l);
	prettyprint(l);
	//printf("ONE and TWO : %d \nTWO and THREE : %d \nTHREE and THREE : %d \n",
	//		strcmpp("ONE","TWO"),strcmpp("TWO","THREE"),strcmpp("THREE","THREE"));
	//deleteElt(l,"ONE");
	//prettyprint(l);
	order(l);
	prettyprint(l);
	//printf("the size of HELLO is: %zu \n", strlen("HELLO"));
	return 0;
}
