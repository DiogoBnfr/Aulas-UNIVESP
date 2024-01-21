#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE;

#define false 0
#define true 1
typedef int bool;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct aux {
  REGISTER reg;
  struct aux* next;
} ELEMENT;

typedef struct {
  ELEMENT* top;
} STACK;

void init_stack(STACK* stack) { stack->top = NULL; }

int size_stack(STACK* stack) {
  ELEMENT* addr = stack->top;
  int size = 0;
  while (addr != NULL) {
    size++;
    addr = addr->next;
  }
  return size;
}

bool empty_stack(STACK* stack) {
  if (stack->top == NULL) return true;
  return false;
}

void print_stack(STACK* stack) {
  ELEMENT* element = stack->top;
  while (element != NULL) {
    printf("|%i|\n", element->reg.key);
    element = element->next;
  }
}

bool push(STACK* stack, REGISTER reg) {
  ELEMENT* new = (ELEMENT*)malloc(sizeof(ELEMENT));
  new->reg = reg;
  new->next = stack->top;
  stack->top = new;
  return true;
}

bool pop(STACK* stack, REGISTER* reg) {
  if (stack->top == NULL) return false;
  *reg = stack->top->reg;
  ELEMENT* garbage = stack->top;
  stack->top = stack->top->next;
  free(garbage);
  return true;
}

void reboot_stack(STACK* stack) {
  ELEMENT* garbage;
  ELEMENT* addr = stack->top;
  while (addr != NULL) {
    garbage = addr;
    addr = addr->next;
    free(garbage);
  }
  stack->top = NULL;
}

int main(int argc, char const* argv[]) { return 0; }
