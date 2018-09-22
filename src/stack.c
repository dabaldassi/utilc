#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack * create_Stack()
{
  Stack * stack = NULL;

  stack = (Stack *) malloc(sizeof(Stack));

  if(stack == NULL) fprintf(stderr, "Failed to create stack\n");
  else
    {
      stack->next  = NULL;
      stack->value = NULL;
      stack->size  = 0;
    }

  return stack;
}

int push_Stack(Stack ** stack, void * value)
{
  Stack * new = NULL;
  
  if(stack && *stack)
    {
      
      new = (Stack *) malloc(sizeof(Stack));
      new->next = *stack;
      new->value = value;
      new->size = (*stack)->size + 1;
      
      *stack = new;

      return 0;
    }

  return 1;
}

void * pop_Stack(Stack ** stack)
{
  void  * value = NULL;
  Stack * del = NULL;

  if(stack && *stack && (*stack)->size != 0)
    {
      del = *stack;
      value = del->value;
      *stack = del->next;

      free(del);
    }

  return value;
}

void delete_Stack(Stack * stack, void (*freeElement)(void *))
{
  Stack * del = NULL;

  while(stack)
    {
      del = stack;
      stack = stack->next;

      if(freeElement) freeElement(del->value);

      free(del);

      del = NULL;
    }
 
}

unsigned int size_Stack(Stack * stack)
{
  if(stack) return stack->size;

  fprintf(stderr, "Stack does not exist\n");

  return 0;
}

int isEmpty_Stack(Stack * stack)
{
  if(stack) return stack->size == 0;

  fprintf(stderr, "Stack does not exist\n");

  return 0;
}
