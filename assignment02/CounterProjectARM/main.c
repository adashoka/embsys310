int counter=0x0;

int main ()
{
   int *p_int = (int *)0x20000000;
   ++(*p_int);
   ++(*p_int);
   ++(*p_int);
   counter++;
   return 0;
}