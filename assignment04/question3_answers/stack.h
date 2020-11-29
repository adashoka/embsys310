#ifndef STACK_H
#define STACK_H

//function to initialize the stack internals
void StackInit(void);

//function to push an element onto the stack
int StackPush(int data);

//function to pop and element off the stack
int StackPop(int* data);

//function that returns 1 if stack is empty
int StackIsEmpty(void);

//funciton that returns 1 if stack if full
int StackIsFull(void);


#endif