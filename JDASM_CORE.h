#ifndef __JDASM_CORE_H
#define __JDASM_CORE_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdint>
#include <string.h>

struct Instructions
{

    // Move Instruction starts from 30
    char* INS_MV = "30"; // CC 4 3 byte

    // Jump instructions starts from 40
    char* INS_JMP = "40"; // Jump to a memory location CC 3 2 byte
    char* INS_JZ = "41"; // Jump to a memory location if the zero flag is set 
    char* INS_JNZ = "42"; // Jump to a memory location if the zero flag is not set
    char* INS_JE = "43";	// Jump to a memory location if the equal flag is set
    char* INS_JNE = "44"; // Jump to a memory location if the equal flag is not set

    // Arthematic instruction starts from 50
    char* INS_DEC = "50"; // To decrement a certain register CC 3 2 byte
    char* INS_INC = "51"; // To increment a certain register CC 3 2 byte
    char* INS_ADD = "52"; // To add a value from a register to another CC 4 3 byte
    char* INS_SUB = "53"; // To sub a value from a register to another CC 4 3 byte
    char* INS_CMP = "54"; // To compare a value from a register to another CC 3 3 byte

    // 60 is used by the program loader for changing memory location when writing to memory
    // Interrupt based instructions starts from 61
    char* INS_INT = "61"; // To use interrupts in the cpu
    char* INS_CLI = "62"; // To clear interrupt flag
    char* INS_STI = "63"; // To set interrupt flag

    // Miscellaneous instructions
    char* INS_NOP = "64"; // No Opcodes
    char* INS_HLT = "65"; // Halts the processor
    // Debugging mode is used for debugging purposes. In this mode the instructions and it's opcode along with the register data and program counter [memory address] will be printed on to the console
    char* INS_SDE = "67"; // Starts debugging
    char* INS_NDE = "66"; // Stops debugging

    char* REG_A = "01"; // Register A
    char* REG_X = "02"; // Register X
    char* REG_Y = "03"; // Register Y
    char* REG_Q = "04"; // Register Q
    char* REG_K = "05"; // Register K

    char* INS_MEM = "60";
};


class JDASM
{
public:
    JDASM();
    ~JDASM();

    void Assemble(char* Filename, char* output);
    void AssemblerCore(char EX1[], char EX2[], char EX3[], char* out);
    void Dissaemble(char Filename[256]);
    void DissasmblerCore(char EX1[], char EX2[], char EX3[]);
};

#endif