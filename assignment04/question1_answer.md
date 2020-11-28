1.a		: The compiler produces a store instruction (STR) to the bit band alias region to set a specific bit in the RCC register
1.b		: The compiler produced the following instructions:
			- LDR to load the contents of the RCC register into a temporary register (say R1)
			- ORRS.W to perform a bitwise OR operation for entire 32 bits (.W) and store it in temporary register (say R1)
			- STR operation to write the results in R1 to the RCC register (address stored in another temp register; say R0)