#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

ArrayList * create_AL()
{
  ArrayList * l = NULL;

  ALLOC(l,ArrayList, 1, "Failed to create ArrayList\n")
    else {
      ALLOC(l->array, void *, SIZE_INIT_AL, "Failed to create ArrayList\n")
	else {
	  l->size_max = SIZE_INIT_AL;
	  l->size = 0;
	}
    }

  return l;
}

void delete_AL(ArrayList *l, void (* freeElement)(void *))
{
  int i;
  
  if(l)
    {
      if(l->array)
	{
	  if(freeElement)
	    {
	      for(i = 0; i < l->size; i++)
		freeElement(l->array[i]);
	    }
	  
	  free(l->array);
	  l->array = NULL;
	}
      free(l);
      l = NULL;
    }
}

void moveRight(ArrayList * l, int ind)
{
  int i;

  for(i = l->size; i > ind; i--)
    l->array[i] = l->array[i - 1];
  
}

void moveLeft(ArrayList * l, int ind, void (* freeElement)(void *))
{
  int i;

  if(freeElement) freeElement(l->array[ind]);

  for(i = ind; i < l->size; i++)
    l->array[i] = l->array[i+1];
    
}

int add_AL(ArrayList * l, int ind, void * value)
{
  int ret = 0;
  
  if(ind < 0) ind += l->size;
  else if(ind > l->size) ind = l->size;

  if(ind < 0 || ind > l->size) ret = 1;
  else
    {
      if(l->size == l->size_max)
	{
	  l->size_max <<= 1;

	  l->array = (void **)realloc(l->array, sizeof(void *)*l->size_max);
	}

      moveRight(l, ind);

      l->size++;

      l->array[ind] = value;
    }
  
  return ret;
}
  
void delElement_AL(ArrayList * l, int ind, void (* freeElement)(void *))
{
  if(ind < 0)
    ind += l->size;

  if(ind < 0 || ind >= l->size)
    ERROR("Can't delete element from array list\n");
  else
    {
      moveLeft(l, ind, freeElement);
      l->size--;
    }
}

void * getValue_AL(ArrayList * l, int ind)
{
  void * ret = NULL;
  
  if(ind < 0) ind += l->size;

  if(ind >= 0 && ind < l->size)
    {
      ret = l->array[ind];
    }
  else
    ERROR("Arraylist out of range\n");

  return ret;
}

int size_AL(ArrayList * l)
{
  return l->size;
}

int set_AL(ArrayList * l, int ind, void * value, void (*freeElement)(void *))
{
  int ret = 0;
  
  if(ind < 0) ind += l->size;

  if(ind <= 0 || ind >= l->size) ret = 1;
  else
    {
      if(freeElement) freeElement(l->array[ind]);
      l->array[ind] = value;
    }

  return ret;
}

void * contains_AL(ArrayList * l, void * elt, int (*egal)(void *, void *))
{
  int    i;
  void * ret = NULL;

  for (i = 0; i < l->size && ret == NULL; i++)
    {
      if(egal(elt, l->array[i]))
	ret = l->array[i];
    }

  return ret;
}

void delByElement_AL(ArrayList * l, void * value, int (*eq)(void *, void *), void (* freeElement)(void *))
{
  int i = 0;

  while(i < l->size)
    {
      if(eq(value, l->array[i]))
	{
	  moveLeft(l, i, freeElement);
	  l->size--;
	}
      else ++i;
    }
}

void initIterator_AL(ArrayList * l)
{
  l->next = 0;
}
 
void * nextIterator_AL(ArrayList * l)
{
  return ((l->next >= l->size)?NULL:l->array[l->next++]);
}

void map_AL(ArrayList * l, void * (*fn)(void *))
{
  int i;

  for (i = 0; i < l->size; i++)
    {
      l->array[i] = fn(l->array[i]);
    }
}
void map_if_AL(ArrayList * l, void *(*fn)(void *), int (*eq)(void *))
{
  int i;

  for (i = 0; i < l->size; i++)
    if(eq(l->array[i]))
      l->array[i] = fn(l->array[i]);
}
