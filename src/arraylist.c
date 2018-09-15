#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

ArrayList * create_ArrayList()
{
  ArrayList * l = NULL;

  ALLOC(l,ArrayList, 1, "Failed to create ArrayList\n")
    else {
      ALLOC(l->array, void *, SIZE_INIT, "Failed to create ArrayList\n")
	else {
	  l->size_max = SIZE_INIT;
	  l->size = 0;
	}
    }

  return l;
}

void delete_AL(ArrayList *l)
{
  if(l)
    {
      if(l->array)
	{
	  free(l->array);
	  l->array = NULL;
	}
      free(l);
      l = NULL;
    }
}
