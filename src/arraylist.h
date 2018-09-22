#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define ALLOC(O,T,S,M) O = (T *)malloc(sizeof(T)*S);	\
  if(O == NULL) \
    fprintf(stderr, M);
#define ERROR(M) fprintf(stderr, M)

#define SIZE_INIT_AL 16

typedef struct 
{
  void ** array;
  int     size;
  int     size_max;
  int     next;
}ArrayList;

ArrayList * create_AL();

void delByElement_AL(ArrayList * l, void * value, int (*eq)(void *, void *), void (* freeElement)(void *));
void delete_AL(ArrayList * l, void (* freeElement)(void *));

int    size_AL(ArrayList * l);
void * getValue_AL(ArrayList *l, int ind);
int    add_AL(ArrayList * l, int ind, void * value);
void   delElement_AL(ArrayList * l, int ind, void (* freeElement)(void *));
int    set_AL(ArrayList * l, int ind, void * value, void (*freeElement)(void *));
void * contains_AL(ArrayList * l, void * elt, int (*egal)(void *, void *));
void * nextIterator_AL(ArrayList * l);
void   initIterator_AL(ArrayList * l);
void   map_AL(ArrayList * l, void * (*fn)(void *));
void   map_if_AL(ArrayList * l, void * (*fn)(void *), int (*eq)(void *));


#endif /* ARRAYLIST_H */
