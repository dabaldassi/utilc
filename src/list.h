#ifndef DEF_LIST
#define DEF_LIST

#include "linkedlist.h"
#include "arraylist.h"

typedef enum {LL, AL}Type;


#ifndef ALLOC
#define ALLOC(O,T,S,M) O = (T *)malloc(sizeof(T)*S);	\
  if(O == NULL) \
    fprintf(stderr, M);
#endif
#define ERROR(M) fprintf(stderr, M)

#define CREATE_LIST(L) {                                                      NULL, \
                                                                              NULL, \
      (void * (*)())                                                          create_##L, \
      (int  (*)(void *, int, void *))                                         add_##L, \
      (int (*)(void *))                                                       size_##L, \
      (void * (*)(void *, int))                                               getValue_##L, \
      (void * (*)(void *, int, void (*)(void *)))                             delElement_##L, \
      (int (*)(void *, int, void *,void (*)(void *)))                         set_##L, \
      (void (*)(void *, void (*)(void *)))                                    delete_##L,	\
      (void * (*)(void *, void *, int (*)(void *, void *), void (*)(void *))) delByElement_##L, \
      (void *(*)(void *, void *, int (*)(void *, void *)))                    contains_##L,\
                                                                              NULL, \
      (void (*)(void *))                                                      initIterator_##L, \
      (void *(*)(void *))                                                     nextIterator_##L, \
      (void (*)(void *, void * (*)(void *)))                                  map_##L, \
      (void (*)(void *, void * (*)(void *), int (*)(void *)))                 map_if_##L}
  

#define addFront_List(L,V) add_List(L,0,V)
#define addBack_List(L,V) add_List(L,size_List(L), V)


typedef struct
{
  void * list;
  void * next;
  
  void * (* create)();
  int    (* add)(void *, int, void *);
  int    (* size)(void *);
  void * (* get)(void *, int);
  void * (* delElement)(void *, int, void (*)(void *));
  int    (* set)(void *, int, void *, void (*)(void *));
  void   (* del)(void *, void (*)(void *));
  void * (* delByElement)(void *, void *, int (*)(void *, void *), void (*)(void *));
  void * (* contains)(void *, void *, int (*)(void *, void *));
  void   (* freeElement)(void *);
  void   (* initIte)(void *);
  void * (* nextIte)(void *);
  void   (* map)(void *, void * (*)(void *));
  void   (* mapif)(void *, void * (*)(void *), int (*)(void *));
}List;


List * create_List(Type type);
void   init_List(List * l);
int    add_List(List * l, int ind, void *value);
int    size_List(List *l);
void * getValue_List(List *l, int ind);
void * delElement_List(List * l, int ind);
void   delete_List(List *l);
int    set_List(List *l, int ind, void * value);
void * contains_List(List *l, void *elt, int (*egal)(void *, void *));
void * delByElement_List(List * l, void * value, int (*eq)(void *, void *));
void   setFreeElement(List * l, void (*freeElement)(void *));
void   initIterator_List(List * l);
void * nextIterator_List(List * l);
void   map_List(List *l, void * (*fn)(void *));
void   map_if_List(List *l, void * (*fn)(void *), int (*eq)(void *));

#endif
