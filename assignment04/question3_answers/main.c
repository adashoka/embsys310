//header file
#include "defines.h"
#include "stack.h"
#include <assert.h>

int main()
{
   int result;
   
   
   
   //testcase 1: fill up stack, pop stack without overflow
   //check Last In First Out data flow
   //############################################################
   //Arrange
   StackInit();
   //Act
   for(int i = 0; i<STACK_SIZE;i++) {
      StackPush(i+1);
   }
   //Assert
   for(int i = 0; i<STACK_SIZE;i++) {
      StackPop(&result);
      assert((STACK_SIZE-i) == result);
   }
   
   
   
   //testcase 2: is empty test under initialization
   //############################################################
   //Arrange
   StackInit();
   //Act
   //Assert
   assert(1 == StackIsEmpty());
   
   
   
   //testcase 3: is empty test after poping all elements
   //############################################################
   //Arrange
   StackInit();
   //Act
   for(int i = 0; i<STACK_SIZE;i++) {
      StackPush(i+1); 
   }
   for(int i = 0; i<STACK_SIZE;i++) {
      StackPop(&result);
   }
   //Assert
   assert(1 == StackIsEmpty()); 
   
   
   
   //testcase 4: is full test under initialization
   //############################################################
   //Arrange
   StackInit();
   //Act
   //Assert
   assert(0 == StackIsFull());
   
   
   
   //testcase 5: is full test after filling up the stack
   //############################################################
   //Arrange
   StackInit();
   //Act
   for(int i = 0; i<STACK_SIZE;i++) {
      StackPush(i+1); 
   }
   //Assert
   assert(1 == StackIsFull());
   
   
   
   //testcase 6: full test
   //didn't feel like spending much time on this test
   //############################################################
   //Arrange
   StackInit();
   
   //Act and Assert for StackPush
   //replace 1 with constrained random number
   for(int i = 0; i<(STACK_SIZE+1);i++) {
      if(!StackIsFull()) {
         assert(0 == StackIsFull());
         StackPush(i+1);
      }
      else {
         assert(1 == StackIsFull());
      }
   }
   
   //didn't feel like spending much time on the StackPop test
   
   return 0;
}
