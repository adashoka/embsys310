//scratch pad
//##############################################################################################
//0x7FFF_FFFF -> 0111 1111 1111 1111 1111 1111 1111 1111 -> n= , v=0, c=0
//0x8000_0000 -> 1000 0000 0000 0000 0000 0000 0000 0000 -> n=1, v=1, c=0
//0x8000_0001 -> 1000 0000 0000 0000 0000 0000 0000 0001 -> n=1, v=0, c=0
//0xFFFF_FFFF -> 1111 1111 1111 1111 1111 1111 1111 1111 -> n=1, v=0, c=0 (-1, big positive number)
//0x0000_0000 -> 0000 0000 0000 0000 0000 0000 0000 0000 -> n=0, v=0, c=1, z=1
//0x0000_0001 -> 0000 0000 0000 0000 0000 0000 0000 0001 -> n=?, v=0, c=0



//question 1
//int counter
//init : 0x7FFF_FFFF
//++   : 0x8000_0000
//##############################################################################################
1.a: -2147483648
1.b: 0x80000000
1.c: N=1, V=1
	--------------------
	N flag answer
	
	Negative condition flag is set to bit 31 of the result of the 
	last flag-setting instruction.
	
	Result value (counter variable) after 1 increment: 0x80000000. And,
	0x8000_0000 in binary is : 1000_0000_0000_0000_0000_0000_0000_0000
	
	The MSB (bit 32 of counter variable) causes the N bit to be set to 1.
	
	side-note: the general purpose registers are not signed or unsigned. To the hardware
	they are just sequnce of bits.
	
	--------------------
	V flag answer
	
	V bit represents the overflow condition flag. The V bit is set to one because the
	general purpose register transitions from 0x7FFF_FFFF to 0x8000_0000.
	
	If the application is using the counter variable as a signed value, 
	this would represent a overflow condition. The hardware need to a way to keep track of this
	transition (from 0x7FFF_FFFF to 0x80000_0000) and the V bit is way to do that.
	
	--------------------
	side note: The hardware has no concept of Positive or negative numbers. It's just a sequence
	of bits. The:
	
	[1] N flag is exposed to the software so that it can infer that the value that it's dealing with
	is a negative number (in case the variable is treated as a signed number)
	
	[2] V flag is exposed to the software to infer a rollover from the most positive value to the most
	negative value.
	(in case the application is using this variable as a signed variable)
	
	

	
	
//question 2
//int counter
//init : 0xFFFF_FFFF
//++   : 0x0000_0000; ; carry 1
//##############################################################################################
2.a: 0
2.b: N=0, V=0
	--------------------
	N flag answer
	
	Incremeniting 0xFFFF_FFFF by one causes the MSB to be set to zero
	Therefore, N takes on a value of zero. This operation results in a 33rd bit (not seen).
	The Carry flag (C) is set to one to indicate the generation of the 33rd bit.
	
	--------------------
	V flag answer
	
	The V flag is only set if the counter transitions over from 0x7FFF_FFFF to 0x8000_0000.
	--------------------
	side note: The hardware has no concept of Positive or negative numbers. It's just a sequence
	of bits. The:
	
	[1] V flag is exposed to the software to be used to infer a rollover of the most positive value.
	(in case the application is using this variable as a signed variable)
	
	[2] the C flag is exposed to the software to infer a rollover from the most positive value to the zero.
	(in case the application is using this variable as a unsigned variable)

	
	
//question 3
//unsigned int counter
//init : 0x7FFF_FFFF
//++   : 0x8000_0000
//##############################################################################################
3.a: 2147483648
3.b: N=1, V=1; same explanation as 1.c above



//question 4
//unsigned int counter
//init : 0xFFFF_FFFF
//++   : 0x0000_0000; carry 1
//##############################################################################################
4.a: 0
4.b: N=0,V=0; same explanation as 2



//question 5
//##############################################################################################
5.a: global scope
5.b: variable is not visible in locals view
5.c: we can track counter value in three windows:[1] auto window, [2] watch window, [3] memory window
5.d: 0x20000000



//question 6
//##############################################################################################
6.a: the value of the counter is 6
6.b: the counter value changes because the statements: [a] ++(*p_int), and [b] counter++, both
operate (increment by one operation) on 0x20000000 memory location which is the
location of the counter variable.








	
	

