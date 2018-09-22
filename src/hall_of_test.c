#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "stack.h"

#define N 50

BEGIN_TEST_GROUP(liblist)

typedef struct Test
{
  int a;
  int b;
}Test;

TEST(libstack) {
  int i;
  Stack * stack = create_Stack();
  
  CHECK( isEmpty_Stack(stack) );
  
  for (i = 0; i < N; i++) {
    push_Stack(&stack, i);
  }

  CHECK( size_Stack(stack) == N);

  i = N;

  while(!isEmpty_Stack(stack)) CHECK(--i == (int)pop_Stack(&stack));

  CHECK( size_Stack(stack) == 0 );

  delete_Stack(stack, NULL);

  stack = create_Stack();

  push_Stack(&stack, 1);
  push_Stack(&stack, 2);
  push_Stack(&stack, 3);
  pop_Stack(&stack);
  pop_Stack(&stack);
  push_Stack(&stack, 4);

  CHECK( (int)pop_Stack(&stack) == 4);
  CHECK( (int)pop_Stack(&stack) == 1);

  push_Stack(&stack, 5);

  CHECK( (int)pop_Stack(&stack) == 5);

  delete_Stack(stack, NULL);
}

TEST(ptr) {
  Stack * stack = create_Stack();
  int i;

  for (i = 0; i < N; i++) {
    push_Stack(&stack, malloc(sizeof(Test)));
  }
  
  delete_Stack(stack, free);
  
}

END_TEST_GROUP(tableau_structure)

int main()
{
  RUN_TEST_GROUP(liblist);
  
  return 0;
}
