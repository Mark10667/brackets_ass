// C-implementation of stack
#include "stack.h"

// function to create a stack of given capacity.
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    //TODO: Your choice here:
	//stack->array = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
	//StackNode* head;
    stack->array = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
    return stack;
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack){
	//TODO
  if(stack->top == stack->capacity-1){
    printf("The stack is full");
    return 1;
  }
  return 0;
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack){
	//TODO
  if(stack->top == -1){
    printf("The stack is empty");
    return 1;
  }
  return 0;
}

// Function to add an item to stack.
void push(Stack* stack, Bracket item){
	if (isFull(stack))
        return;
    //TODO
    stack->top++;
    int current_index = stack->top;
    stack->array[current_index] = item;
    return;
}

// Function to remove an item from stack and return it.
Bracket pop(Stack* stack){
	//TODO
	Bracket top;
  top = stack->array[stack->top];
  stack->top--;
	return top;
}
