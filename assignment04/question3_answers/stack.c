#include "stack.h"
#include "defines.h"

int my_array[STACK_SIZE];
int* current_p;
int* overflow_p; 
int* bottom_p;

void StackInit(void) {
   //set pointers
   
   //<q> this feels like a bad idea: what happens
   //if the pointer points to some dangerous section in memory (post
   //decrement)? Is it a good idea to even have the pointer point to some
   //other part of the memory?
   overflow_p = (&my_array[0]-1);
   
   bottom_p = &my_array[STACK_SIZE-1];
   
   current_p = &my_array[STACK_SIZE-1];
   //erase array
   for(int i=0;i<STACK_SIZE;i++){
      my_array[i]=0;
   }
}

int StackPush(int data) {
   if(current_p == overflow_p) {
      return 1;
   }
   else {
      *current_p = data;
      current_p--;
      return 0;
      //<q> should return 0 be placed inside the else
      //part, or outside the else part?
   }
}

int StackPop(int* result) {
   //nothing to pop
   if(current_p == bottom_p){
      return 1;
   }
   else {
      *result = *++current_p;
      return 0;
   }
}

int StackIsEmpty(void) {
   if(current_p == bottom_p) {
      return 1;
   }
   else {
      return 0;
   }
}

int StackIsFull(void) {
   if(current_p == overflow_p) {
      return 1;
   }
   else {
      return 0;
   }
}