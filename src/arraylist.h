#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define ALLOC(O,T,S,M) O = (T *)malloc(sizeof(T)*S);	\
  if(O == NULL) \
    fprintf(stderr, M);
#define ERROR(M) fprintf(stderr, M)

#define SIZE_INIT 16

typedef struct 
{
  void ** array;
  int size;
  int size_max;
}ArrayList;

ArrayList * create_ArrayList();
void delete_AL(ArrayList *l);

#endif /* ARRAYLIST_H */
