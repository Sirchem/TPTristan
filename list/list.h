#ifndef LIST_H
# define LIST_H

struct list
{
  char *elt;
  struct list *next;
};

struct list* create();

void add(char* elt, struct list *l);

int strcmpp(char* elt1, char* elt2);

size_t strlen(char* s);

int deleteElt(struct list* l,char* elt);

void prettyprint(struct list* l);

int lengthElt(char* Elt);

void order(struct list* l);

#endif /* !LIST_H */
