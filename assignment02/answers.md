//scratch pad <br />
//############################################################################################## <br />
//0x7FFF_FFFF -> 0111 1111 1111 1111 1111 1111 1111 1111 -> n= , v=0, c=0 <br />
//0x8000_0000 -> 1000 0000 0000 0000 0000 0000 0000 0000 -> n=1, v=1, c=0 <br />
//0x8000_0001 -> 1000 0000 0000 0000 0000 0000 0000 0001 -> n=1, v=0, c=0 <br />
//0xFFFF_FFFF -> 1111 1111 1111 1111 1111 1111 1111 1111 -> n=1, v=0, c=0 (-1, big positive number) <br />
//0x0000_0000 -> 0000 0000 0000 0000 0000 0000 0000 0000 -> n=0, v=0, c=1, z=1 <br />
//0x0000_0001 -> 0000 0000 0000 0000 0000 0000 0000 0001 -> n=?, v=0, c=0 <br />


//question 1<br />
//int counter<br />
//init : 0x7FFF_FFFF<br />
//++   : 0x8000_0000<br />
//##############################################################################################<br />
1.a: -2147483648<br />
1.b: 0x80000000<br />
1.c: N=1, V=1<br />
N flag answer<br />

Negative condition flag is set to bit 31 of the result of the <br />
last flag-setting instruction.<br />

Result value (counter variable) after 1 increment: 0x80000000. And,<br />
0x8000_0000 in binary is : 1000_0000_0000_0000_0000_0000_0000_0000<br />

The MSB (bit 32 of counter variable) causes the N bit to be set to 1.<br />

side-note: the general purpose registers are not signed or unsigned. To the hardware<br />
they are just sequnce of bits.<br />


V flag answer<br />

V bit represents the overflow condition flag. The V bit is set to one because the<br />
general purpose register transitions from 0x7FFF_FFFF to 0x8000_0000.<br />

If the application is using the counter variable as a signed value, <br />
this would represent a overflow condition. The hardware need to a way to keep track of this<br />
transition (from 0x7FFF_FFFF to 0x80000_0000) and the V bit is way to do that.<br />


side note: The hardware has no concept of Positive or negative numbers. It's just a sequence<br />
of bits. The:<br />

[1] N flag is exposed to the software so that it can infer that the value that it's dealing with<br />
is a negative number (in case the variable is treated as a signed number)<br />

[2] V flag is exposed to the software to infer a rollover from the most positive value to the most<br />
negative value.<br />
(in case the application is using this variable as a signed variable)<br /><br />
	
	

	
	
//question 2<br />
//int counter<br />
//init : 0xFFFF_FFFF<br />
//++   : 0x0000_0000; ; carry 1<br />
//##############################################################################################<br />
2.a: 0<br />
2.b: N=0, V=0<br />
	
N flag answer<br />
	
Incremeniting 0xFFFF_FFFF by one causes the MSB to be set to zero<br />
Therefore, N takes on a value of zero. This operation results in a 33rd bit (not seen).<br />
The Carry flag (C) is set to one to indicate the generation of the 33rd bit.<br /><br />
	
	
V flag answer<br />
The V flag is only set if the counter transitions over from 0x7FFF_FFFF to 0x8000_0000.<br /><br />
	
	
side note: The hardware has no concept of Positive or negative numbers. It's just a sequence<br />
of bits. The:<br />

[1] V flag is exposed to the software to be used to infer a rollover of the most positive value.<br />
(in case the application is using this variable as a signed variable)<br />

[2] the C flag is exposed to the software to infer a rollover from the most positive value to the zero.<br />
(in case the application is using this variable as a unsigned variable)<br />

	
	
//question 3<br />
//unsigned int counter<br />
//init : 0x7FFF_FFFF<br />
//++   : 0x8000_0000<br />
//##############################################################################################<br />
3.a: 2147483648<br />
3.b: N=1, V=1; same explanation as 1.c above<br />



//question 4<br />
//unsigned int counter<br />
//init : 0xFFFF_FFFF<br />
//++   : 0x0000_0000; carry 1<br />
//##############################################################################################<br />
4.a: 0<br />
4.b: N=0,V=0; same explanation as 2<br />



//question 5<br />
//##############################################################################################<br />
5.a: global scope<br />
5.b: variable is not visible in locals view<br />
5.c: we can track counter value in three windows:[1] auto window, [2] watch window, [3] memory window<br />
5.d: 0x20000000<br />



//question 6<br />
//##############################################################################################<br />
6.a: the value of the counter is 6<br />
6.b: the counter value changes because the statements: [a] ++(\*p_int), and [b] counter++, both<br />
operate (increment by one operation) on 0x20000000 memory location which is the location of the<br /> 
counter variable.<br />

//question 7<br />
//##############################################################################################<br />
7.a: 0x20000000<br />
7.b: RAM<br />
7.c: 4<br />








	
	

