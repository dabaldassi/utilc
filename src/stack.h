#ifndef STACK_H
#define STACK_H

typedef struct Stack
{
  unsigned int   size;
  struct Stack * first;
  struct Stack * next;
  void         * value;
}Stack;

Stack        * create_Stack();
int            push_Stack(Stack ** stack, void * value);
void         * pop_Stack(Stack ** stack);
void           delete_Stack(Stack * stack, void (*freeElement)(void *));
unsigned int   size_Stack(Stack * stack);
int            isEmpty_Stack(Stack * stack);

#endif /* STACK_H */
