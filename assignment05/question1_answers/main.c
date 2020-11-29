void swap_pointer(int** x_p, int** y_p);

void swap_pointer(int** x_p, int** y_p) {
   int* temp;
   temp = *x_p;
   *x_p = *y_p;
   *y_p = temp;
}

int main()
{
   int x = 15;
   int y = 10;
   int* x_p;
   int* y_p;

   x_p = &x;
   y_p = &y;
   swap_pointer(&x_p,&y_p);
   return 0;
}
