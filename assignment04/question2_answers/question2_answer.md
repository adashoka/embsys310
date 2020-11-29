2.a: 

case 1: 5 arguments

the calling function (main), passes argument to the called function (func1_five) using: 
[1] R0-R3, and 
[2] Stack: one of the variable is stored in the stack. The processor, once in the called function, 
retrieves the variable from stack using [SP #offset] instruction when it is needed

case 1: 6 arguments

the calling function (main), passes argument to the called function (func1_six) using: 
[1] R0-R3, and 
[2] Stack: two variables are stored to stack. The processor, once in the called function, 
retrieves the variable from stack  -- using [SP #offset] instruction -- into one of the general purpose
registers before using it

2.b: The compiler before calling the called function (with more than 4 arguments), generated assembly code
to store the extra variables (variables count that exceeds 4) into the stack.

2.c: The compiler once inside the called function, generated extra code to retreive the extra variables (ones that exceed 4 variable count)
from the stack into the general purpose registers

2.d: The compiler pushed a bunch of general purpose registers into the stack. It happened:

[1] once in the calling(main) function before calling the called function (func1_five),

[2] once in the called function (func1_five) right at the start

The processor probably did this to preserve the value of the variables before doing a jump to called function.
I couldn't understand the why certain registers were pushed into the stack -- on the surface it looked it wouldn't have
made any difference had the processor not pushed those general porpose registers.