#include <stdio.h>


int IsBigEndian(void);
int IsLittleEndian(void);


int IsBigEndian(void) {
   char mychar;
   int myint;
   myint = 0x41424244;
   mychar = *((char*)(&(myint)));
   if(mychar == 0x41) {
      return 1;
   }
   return 0;
}

int IsLittleEndian(void) {
   char mychar;
   int myint;
   myint = 0x41424244;
   mychar = *((char*)(&(myint)));
   if(mychar == 0x44) {
      return 1;
   }
   return 0;
}

int main()
{
   if(IsBigEndian()){
      printf("Big Endian");
   }
   
   if(IsLittleEndian()){
      printf("Little Endian");
   }

   return 0;
}
