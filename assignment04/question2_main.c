
//funciton prototypes
int func1_three(int a,int b,int c);
int func1_four(int a,int b,int c,int d);
int func1_five(int a,int b,int c,int d,int e);
int func1_six(int a,int b,int c,int d,int e,int f);

//function definition
int func1_three(int a,int b,int c) {
   volatile int total;
   total = a + b + c;
   return (total);
}

int func1_four(int a,int b,int c,int d) {
   volatile int total;
   total = a + b + c + d;
   return (total);
}

int func1_five(int a,int b,int c, int d, int e) {
   volatile int total;
   total = a + b + c + d + e;
   return (total);
}

int func1_six(int a,int b,int c, int d, int e, int f) {
   volatile int total;
   total = a + b + c + d + e + f;
   return (total);
}

void delay (void)
{
   volatile int counter=0;
}


int main()
{
   int counter=0;
   int my_output;
   counter++;
   counter++;
   counter++;
   counter++;
   my_output = func1_six(1,2,3,4,5,6);
   counter++;
   counter++;
   return 0;
}
