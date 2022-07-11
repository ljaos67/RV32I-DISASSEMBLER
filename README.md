# RV32I-DISASSEMBLER
Loading instructions into a simulated memory of sufficient size and then decode each 32-bit instruction one-at-a-time starting from address zero and continue through to the end of the simulated memory. Purpose is to demonstrate fluency in C++ and understanding of RV32I ISA.
1 Problem Description
Disassemble an executable binary file by loading it into a simulated memory of suficient size and
then decode each 32-bit instruction one-at-a-time starting from address zero and continue through
to the end of the simulated memory.
2 Files You Must Write
You will write a C++ program suitable for execution on hopper.cs.niu.edu (or turing.cs.niu.edu.)
Your source files MUST be named exactly as shown below or they will fail to compile and you will
receive zero points for this assignment.
Create a directory named a4 and place within it a copy of all the the source files from Assignment
3 plus the rv32i_decode files defined below.
main.cpp Your main() and usage() function definitions will go here.
hex.h The declarations of your hex formatting functions will go here.
hex.cpp The definitions of your hex formatting functions will go here.
memory.h The definition of your memory class will go here.
memory.cpp The memory class member function definitions will go here.
rv32i decode.h The definition of a class named rv32i_decode will go here.
rv32i decode.cpp The definitions of any member functions of class rv32i_decode will go here.
