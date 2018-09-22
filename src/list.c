#include <stdio.h>
#include <stdlib.h>

#include "list.h"

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
  List lTab[] = {CREATE_LIST(LL), CREATE_LIST(AL)};

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
  return l->set(l->list, ind, value, l->freeElement);
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

void map_List(List *l, void * (*fn)(void *))
{
  l->map(l->list, fn);
}

void map_if_List(List *l, void * (*fn)(void *), int (*eq)(void *))
{
  l->mapif(l->list, fn, eq);
}
