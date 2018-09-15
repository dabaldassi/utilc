#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

static ElementLL * getElement_LL(LinkedList *l, int ind)
{
  ElementLL * elt = l->first; /* La liste doit exister */
  int i = 0;

  if(ind<0)
    ind = l->size + ind;

  if(ind >= 0)
    {
      while(elt && i<ind)
	{
	  elt = elt->next;
	  ++i;
	}
    }

  return elt;
}

LinkedList * create_LL()
{
  LinkedList * l = NULL;
  ALLOC(l,LinkedList,1,"Failed to create LinkedList\n")
  else {
    l->first = NULL;	 
    l->size = 0;
    l->next = NULL;
  }

  return l;
}

void delete_LL(LinkedList * l, void (* freeElement)(void *))
{
  ElementLL * elt = NULL, *del = NULL;

  if(l == NULL)
    fprintf(stderr, "Delete failed : List does not exist \n");
  else {
    elt = l->first;

    while(elt)
      {
	del = elt;
	elt = elt->next;

	if(freeElement != NULL) /* free the value */
	  freeElement(del->value);
	
	free(del); /* free the cell */
 	del = NULL;
      }

    free(l); /* free the list */
    l = NULL;
  }
}


void delByElement_LL(LinkedList * l, void * value, int (* eq)(void *, void *), void (* freeElement)(void *))
{
  ElementLL * elt = NULL, *del = NULL;

  if(l == NULL)
    ERROR("Can't delete element, list does not exist");
  else {
    elt = l->first;

    if(elt)
      {
	if(eq(elt->value, value))
	  {
	    del = elt;
	    l->first = elt->next;
	    l->size -= 1;

	    if(freeElement)
	      freeElement(del->value);
	 
	    free(del);
	  }
	else {
	  while(elt->next && !eq(value, elt->next->value))
	    elt = elt->next;

	  if(elt->next)
	    {
	      del = elt->next;
	      elt->next = elt->next->next;
	      l->size -= 1;

	      if(freeElement)
		freeElement(del->value);
	      
	      free(del);
	    }
	}	
      }
  }

}

void * contains_LL(LinkedList * l, void * elt, int (*egal)(void *, void *))
{
  ElementLL * cour = NULL;
  void * value = NULL;
  if(l == NULL)
    ERROR("Function contains failed : list doesn't exist");
  else {
    cour = l->first;
    while(cour && !egal(elt, cour->value))
      {
	cour = cour->next;
      }
    value = ((cour)?cour->value:NULL);
  }

  return value;
}

int size_LL(LinkedList * l)
{
  int t = 0;
  if(l == NULL)
    fprintf(stderr, "List doesn't exist, it can't have a size \n");
  else {
    t = l->size;
  }
  return t;
}

void * getValue_LL(LinkedList *l, int ind)
{
  ElementLL * elt = NULL;
  void * value = NULL;

  if (l == NULL) {
    fprintf(stderr, "List doesn't exist, you can't get a value");
  }
  else {
    
    elt = getElement_LL(l,ind);

    if(elt == NULL)
      fprintf(stderr, "List out of range \n");
    else
      value = elt->value;
  }

  return value;
}

int add_LL(LinkedList * l, int ind, void * value)
{
  ElementLL * new = NULL;
  ElementLL * elt = NULL;
  int ret = 1; /* return value */
  int i;

  if(l == NULL)
    {
      fprintf(stderr, "Add failed :  list doesn't exist \n");
    }
  else {

    new = (ElementLL *) malloc(sizeof(ElementLL));

    if(new == NULL)
      {
	fprintf(stderr, "Failed to create new element \n");
      }
    else {
      new->value = value;

      elt = l->first;

      if(elt == NULL || ind == 0)
	{
	  new->next = l->first;
	  l->first = new;
	  --ret;
	  ++(l->size);
	}

      else
	{
	  i = 0;
	  while(elt->next != NULL &&  i < ind-1)
	    {
	      elt = elt->next;
	      i++;
	    }

	  new->next = elt->next;
	  elt->next = new;
	  ++(l->size);
	  --ret;
	}
    }
  }
  

  return ret;
      
}

void delElement_LL(LinkedList * l, int ind, void (* freeElement)(void *))
{
  ElementLL * elt = NULL, *del = NULL;
  
  if(l == NULL)
    {
      fprintf(stderr, "List doesn't exist, you can't delete an element \n");
    }
  else if(l->size > 0)
    {
      if(ind == 0)
	{
	  del = l->first;
	  l->first = del->next;

	  if(freeElement)
	    freeElement(del->value);
	  
	  free(del);
	  del = NULL;
	  l->size -= 1;
	}
      else
	{
	  elt = getElement_LL(l, ind-1);

	  if(elt != NULL && elt->next != NULL)
	    {
	      del = elt->next;
	      elt->next = del->next;

	      if(freeElement)
		freeElement(del->value);
	      
	      free(del);
	      del = NULL;
	      l->size -= 1;
	    }
	}
    }  
}


int set_LL(LinkedList * l, int ind, void * value)
{
  int ret = 1;
  if(l)
    {
      getElement_LL(l,ind)->value = value;
      --ret;
    }
  else {
    ERROR("Can't set value !\n");
  }

  return ret;
}

void initIterator_LL(LinkedList * l)
{
  l->next = l->first;
}

void * nextIterator_LL(LinkedList * l)
{
  void * e = NULL;

  if(l->next)
    {
      e = l->next->value;
      l->next = l->next->next;
    }

  return e;
}
