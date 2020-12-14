//vector : blocks of 4 bytes one after the other
//use non-standard C-syntax to place at intvec section
//not portable
//Global variable
//make it read only by making it const. RW can't be in ROM
//even though you do a @ ".intvec
//define prototypes, and put them in table
void __iar_program_start(void);
void Unused_Handler(void);

extern int CSTACK$$Limit;
extern void SysTick_Handler();

int const __vector_table[] @ ".intvec" = {
    (int)&CSTACK$$Limit,// Pointer to Top of Stack
    (int)&__iar_program_start,// Pointer to Reset Handler
    (int)&Unused_Handler,
    (int)&Unused_Handler,
    (int)&Unused_Handler,
    (int)&Unused_Handler,
    (int)&Unused_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int)&Unused_Handler,
    (int)&Unused_Handler,
    0,      // Reserved
    (int)&Unused_Handler,
    (int)&SysTick_Handler
};

void Unused_Handler (void)
{
   while(1)
   {  
   }
}

