#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

#include "list.h"

/*

List * create_List(Type type)
{
  List * l = NULL;
  void * (* create[])() = {(void *)create_LinkedList, (void *)create_ArrayList};

  ALLOC(l,List,1,"Failed to create list \n")
  else {
    l->list = create[type]();
    l->type = type;
  }

  

  return l;
}


int add_List(List * l, int ind, void *value)
{
  int ret = 1;
  int (* add[])(void *, int, void *) = {add_LL};

  if(l)
    {
      ret = add[l->type](l->list, ind, value);
    }
  else {
    ERROR("List doesn't exist !\n");
  }

  return ret;
}

int size_List(List *l)
{
  int t = 0;
  int (* size[])(void *) = {size_LL};

  if(l)
    {
      t = size[l->type](l->list);
    }
  else {
    ERROR("List doesn't exist, it can't have a size\n");
  }

  return t;
}

void * getValue_List(List *l, int ind)
{
  void * value = NULL;
  void *(* getValue[])(void *, int) = {getValue_LL};

  if(l)
    {
      value = getValue[l->type](l->list, ind);
    }
  else {
    ERROR("List does't exist, you can't get a value\n");
  }

  return value;
}

void * delElement_List(List * l, int ind)
{
  void * ret = NULL;
  void * (* delElement[])(void *, int) = {delElement_LL};

  if(l){
    ret = delElement[l->type](l->list, ind);
  }
  else {
    ERROR("Can't delete element !\n");
  }

  return ret;
}

void delete_List(List *l)
{
  void (* del[])(void *) = {delete_LL, delete_AL};
  if(l)
    {
      if(l->list)
	{
	  del[l->type](l->list);
	}
      free(l);
      l = NULL;
    }
	   
}

int set_List(List *l, int ind, void * value)
{
  int ret = 1;
  int (* set[])(void *, int, void *) = {set_LL};
  
  if(l)
    {
      ret = set[l->type](l->list, ind, value);
    }
  else {
    ERROR("Can't set value !\n");
  }

  return ret;
  }

void * contains_List(List *l, void *elt, int (*egal)(void *, void *))
{
  void * ret = NULL;
  void * (* contains[])(void *, void *, int (*)(void *,void *)) = {contains_LL};
  
  if(l)
    {
      ret = contains[l->type](l->list, elt, egal);
    }
  else {
    ERROR("Can't search value !\n");
  }

  return ret;
}



void delByElement_List(List * l, void * value)
{
  void (* del[])(void *, void *) = {delByElement_LL};

  if(l)
    {
      del[l->type](l->list, value);
    }
  else {
    ERROR("Can't delete, list does not exist !\n");
  }
}
*/
/* int main() */
/* { */
/*   List * l = create_List(LINKED_LIST); */
/*   int x = 25; */
/*   char c = 'c'; */
/*   double r = 1.25; */
/*   int deux = 2; */
/*   int b = 5; */

/*   //LinkedList * l = lst->list; */
/*   /\*addBack_List(l,&x); */
/*   addBack_List(l,&c); */

/*   printf("%d\n", size_List(l)); */
/*   printf("%d\n", *((int *)getValue_List(l,0))); */
/*   printf("%c\n", *((char *)(getValue_List(l,1)))); */

/*   addFront_List(l,&r); */

/*   printf("%f %d\n" ,*(double *)getValue_List(l,0), size_List(l)); */

/*   add_List(l,2,&deux); */

/*   printf("%d\n" ,*(int *)getValue_List(l,2)); */

  
/*   delElement_List(l, 3); */
/*   addBack_List(l,&b); */
/*   printf("%d\n", *(int *)getValue_List(l,3)); */

/*   set_List(l,3, &deux); */
/*   printf("%d\n", *(int *)getValue_List(l,3));*\/ */
/*   //printf("%d\n", *(char *)getValue_List(l,1)); */

/*   addFront_List(l,&deux); */
/*   addFront_List(l, &x); */
/*   addFront_List(l,&b); */
/*   int bob = 425; */
/*   //printf("%d\n", *(int *)getValue_List(l,1)); */
/*   printf("%d\n",NULL == contains_List(l, &bob, eq)); */
  
/*   delete_List(l); */
/*   return 0; */


  
/* } */

/*
void initIterator_List(List * l)
{
  l->next = l->list->first;
}

void * nextIterator_List(List * l)
{
  void * elt = l->next->value;

*/

void initIterator_List(List * l)
{
  l->initIte(l->list);
}

void * nextIterator_List(List * l)
{
  return l->nextIte(l->list);
}

List * create_List(Type type)
{
  List * l = (List *) malloc(sizeof(List));
  List lTab[] = {CREATE_LIST(LL)};

  *l = lTab[type];
  l->list = l->create();

  return l;
}

int add_List(List * l, int ind, void * value)
{
  return l->add(l->list, ind, value);
}

int size_List(List * l)
{
  return l->size(l->list);
}

void * getValue_List(List * l, int ind)
{
  return l->get(l->list, ind);
}

int set_List(List * l, int ind, void * value)
{
  return l->set(l->list, ind, value);
}

void delete_List(List * l)
{
  l->del(l->list, l->freeElement);
  free(l);
}

void * delByElement_List(List *l, void * value, int (*eq)(void *, void *))
{
  return l->delByElement(l->list, value, eq, l->freeElement);
}

void * contains_List(List * l, void * elt, int (*equal)(void *, void *))
{
  return l->contains(l->list, elt, equal);
}

void * delElement_List(List * l, int ind)
{
  return l->delElement(l->list, ind, l->freeElement);
}

void init_List(List * l)
{
  l->list = l->create();
}

void setFreeElement(List * l, void (*freeElement)(void *))
{
  l->freeElement = freeElement;
}



/*
int main(int argc, char *argv[])
{
  List l;
  int a = 2, b = 3;
  l = CREATE_LIST(LL);
  l.list = l.create();
  l.add(l.list, 0, a);
  l.add(l.list, 1, b);
  a = 1;
  l.set(l.list, 0, 8);
  printf("%d\n", 8 == (int)l.contains(l.list, 8, eq));

  
  l.del(l.list);
  
  return 0;
}
*/
