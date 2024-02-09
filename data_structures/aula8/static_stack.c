#include <stdio.h>
#define MAX 50

#define true 1
#define false 0
typedef int bool;

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct {
  REGISTER data[MAX];
  int top;
} STACK;

void init_stack(STACK* stack) { stack->top = -1; }

int size_stack(STACK* stack) { return stack->top + 1; }

void print_stack(STACK* stack) {
  for (int i = stack->top; i > 0; i--) {
    printf("|%i|\n", stack->data[i].key);
  }
}

bool push(STACK* stack, REGISTER reg) {
  if (stack->top >= MAX - 1) return false;
  stack->top++;
  stack->data[stack->top] = reg;
  return true;
}

bool pop(STACK* stack, REGISTER* reg) {
  if (stack->top == -1) return false;
  *reg = stack->data[stack->top];
  stack->top--;
  return true;
}

void reboot_stack(STACK* stack) { stack->top = -1; }

int main(int argc, char const* argv[]) { return 0; }