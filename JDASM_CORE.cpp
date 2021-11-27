#include "JDASM_CORE.h"

JDASM::JDASM()
{
}

JDASM::~JDASM()
{
}

void JDASM::Assemble(char* filename, char* output)
{
    std::cout << "Assembling file: " << filename << std::endl;
    std::cout << output << " " << "-o" << " " << output << std::endl;
    std::ifstream istream(filename);
    char EX1[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char EX2[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char EX3[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

    char fn[256] = { 0 };
    
    while (istream >> EX1 >> EX2 >> EX3)
    {
        std::cout << "FST: " << EX1 << " SCE: " << EX2 << " TRD: " << EX3 << "\n";
        for (int i = 0; i != 1; i++)
		{
			AssemblerCore(EX1, EX2, EX3, output);
		}
    }
    
}

void  JDASM::AssemblerCore(char EX1[], char EX2[], char EX3[], char* out)
{
    Instructions ins;
    std::cout <<  "Got file\n";
    std::cout << EX1 << " " << EX2 << " " << EX3 << "\n";
    std::ofstream OutFile;
    OutFile.open(out, std::ios::out | std::ios::app);

    if (!OutFile) 
    {
        std::cerr << "can't open output file" << std::endl;
    }

    if(EX1[0] == 'm' && EX1[1] == 'o' && EX1[2] == 'v')
    {
        if (EX2[0] == 'X')
        {

            if (EX3[0] == 'Y')
            {
                OutFile << ins.INS_MV << " " << ins.REG_X << " " << ins.REG_Y << "\n";
            }
            else if (EX3[0] == 'A')
            {
                OutFile << ins.INS_MV << " " << ins.REG_X << " " << ins.REG_A << "\n";
            }
            else if (EX3[0] == 'Q')
            {
                OutFile << ins.INS_MV << " " << ins.REG_X << " " << ins.REG_Q << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << ins.REG_X << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << EX3 << " " << ins.REG_X << "\n";
            }
        }
        else if (EX2[0] == 'Y')
        {
            if (EX3[0] == 'X')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Y << " " << ins.REG_X << "\n";
            }
            else if (EX3[0] == 'A')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Y << " " << ins.REG_A << "\n";
            }
            else if (EX3[0] == 'Q')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Y << " " << ins.REG_Q << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Y << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << ins.REG_Y << " " << EX3 << "\n";
            }
        }
        else if (EX2[0] == 'A')
        {
            if (EX3[0] == 'X')
            {
                OutFile << ins.INS_MV << " " << ins.REG_A << " " << ins.REG_X << "\n";
            }
            else if (EX3[0] == 'Y')
            {
                OutFile << ins.INS_MV << " " << ins.REG_A << " " << ins.REG_Y << "\n";
            }
            else if (EX3[0] == 'Q')
            {
                OutFile << ins.INS_MV << " " << ins.REG_A << " " << ins.REG_Q << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << ins.REG_A << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << EX3 << " " << ins.REG_A << "\n";
            }
        }
        else
        {
            if (EX3[0] == 'X')
            {
                OutFile << ins.INS_MV << " " << EX2 << " " << ins.REG_X << "\n";
            }
            else if (EX3[0] == 'Y')
            {
                OutFile << ins.INS_MV << " " << EX2 << " " << ins.REG_Y << "\n";
            }
            else if (EX3[0] == 'Q')
            {
                OutFile << ins.INS_MV << " " << EX2 << " " << ins.REG_Q << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << EX2 << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << EX2 << " " << EX3 << "\n";
            }
        }
    }
    else if(EX1[0] == 'J' && EX1[1] == 'M' && EX1[2] == 'P')
    {
        OutFile << ins.INS_JMP << " " << EX2 << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'N' && EX1[2] == 'Z')
    {
        OutFile << ins.INS_JNZ << " " << EX2 << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'Z')
    {
        OutFile << ins.INS_JZ << " " << EX2 << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'N' && EX1[2] == 'E')
    {
        OutFile << ins.INS_JNE << " " << EX2 << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'E')
    {
        OutFile << ins.INS_JE << " " << EX2 << "\n";
    }
    else if (EX1[0] == 'D' && EX1[1] == 'E' && EX1[2] == 'C')
    {
        if(EX2[0] == 'X')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_X << "\n";
        }
        else if(EX2[0] == 'Y')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_Y << "\n";
        }
        else if(EX2[0] == 'A')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_A << "\n";
        }
        else if(EX2[0] == 'Q')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_Q << "\n";
        }
    }
    else if (EX1[0] == 'I' && EX1[1] == 'N' && EX1[2] == 'C')
    {
        if(EX2[0] == 'X')
        {
            OutFile << ins.INS_INC << " " << ins.REG_X << "\n";
        }
        else if(EX2[0] == 'Y')
        {
            OutFile << ins.INS_INC << " " << ins.REG_Y << "\n";
        }
        else if(EX2[0] == 'A')
        {
            OutFile << ins.INS_INC << " " << ins.REG_A << "\n";
        }
        else if(EX2[0] == 'Q')
        {
            OutFile << ins.INS_INC << " " << ins.REG_Q << "\n";
        }
    }
    else if (EX1[0] == 'A' && EX1[1] == 'D' && EX1[2] == 'D')
    {
        if(EX2[0] == 'X')
        {
            if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Y << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_A << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Q << " " << ins.REG_X << "\n";
            }
        }
        else if(EX2[0] == 'Y')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_X << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_A << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Q << " " << ins.REG_Y << "\n";
            }
        }
        else if(EX2[0] == 'A')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_X << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Y << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Q << " " << ins.REG_A << "\n";
            }
        }
        else if(EX2[0] == 'Q')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_X << " " << ins.REG_Q << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_Y << " " << ins.REG_Q << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_ADD << " " << ins.REG_A << " " << ins.REG_Q << "\n";
            }
        }
    }
    else if (EX1[0] == 'S' && EX1[1] == 'U' && EX1[2] == 'B')
    {
        if(EX2[0] == 'X')
        {
            if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Y << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_A << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Q << " " << ins.REG_X << "\n";
            }
        }
        else if(EX2[0] == 'Y')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_X << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_A << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Q << " " << ins.REG_Y << "\n";
            }
        }
        else if(EX2[0] == 'A')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_X << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Y << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Q << " " << ins.REG_A << "\n";
            }
        }
        else if(EX2[0] == 'Q')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_X << " " << ins.REG_Q << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_Y << " " << ins.REG_Q << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_SUB << " " << ins.REG_A << " " << ins.REG_Q << "\n";
            }
        }
    }
    else if (EX1[0] == 'M' && EX1[1] == 'E' && EX1[2] == 'M')
    {
        OutFile << ins.INS_MEM << " " << EX2 << " " << EX3 <<"\n";
    }
    else
    {
        OutFile << EX1 << " " << EX2 << " " << EX3 << "\n";
    }
    OutFile.close();
}