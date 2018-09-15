#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define ALLOC(O,T,S,M) O = (T *)malloc(sizeof(T)*S);	\
  if(O == NULL) \
    fprintf(stderr, M);
#define ERROR(M) fprintf(stderr, M)

#define addFront_LL(L,V) add_LL(L,0,V)
#define addBack_LL(L,V) add_LL(L,size_LL(L),V)

/**
 *\brief An element of a linked list
*/

typedef struct ElementLL
{
  void * value;
  struct ElementLL *next;
} ElementLL;

/**
 *\brief Define the type LinkedList
 */

typedef struct LinkedList
{
  ElementLL * first;
  ElementLL * next;
  int         size;
} LinkedList;


/**
 *\fn LinkedList * create_LinkedList();
 *\brief Create a linked list
 *\return null if an error occured, the list else
 */
LinkedList * create_LL();

void delByElement_LL(LinkedList * l, void * value, int (*eq)(void *, void *), void (* freeElement)(void *));
void delete_LL(LinkedList * l, void (* freeElement)(void *));

int    size_LL(LinkedList * l);
void * getValue_LL(LinkedList *l, int ind);
int    add_LL(LinkedList * l, int ind, void * value);
void   delElement_LL(LinkedList * l, int ind, void (* freeElement)(void *));
int    set_LL(LinkedList * l, int ind, void * value);
void * contains_LL(LinkedList * l, void * elt, int (*egal)(void *, void *));
void * nextIterator_LL(LinkedList * l);
void   initIterator_LL(LinkedList * l);

#endif /* LINKEDLIST_H */
