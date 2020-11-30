/*******************************************************************************
File name       : aqrAsm.s
Description     : Assembly language function for square
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr_div   // myCstr defined outside this file.
    
    PUBLIC divAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : divAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : int sqrAsm(val)
                : Where val is the value to calculate it's square
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/  
  
divAsm
    PUSH {R0,LR}        // save the input argument and return address
    LDR R0,=myCstr_div  // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0,LR}         // Restore R0 and LR
    MOV R1, R0          // R1 = R0
    MOV R2, #2          // R2 = constant value of 2
    SDIV R0, R1, R2     // R0 = R1/R2
    BX LR               // return (with function result in R0)

    END
