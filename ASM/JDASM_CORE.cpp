// Copyright (C) 2021 arun007coder
// 
// This file is part of JDASM.
// 
// JDASM is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// JDASM is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with JDASM.  If not, see <http://www.gnu.org/licenses/>.

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
    std::remove(output);
    std::ifstream istream(filename);
    char EX1[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char EX2[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char EX3[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

    char fn[256] = { 0 };
    
    while (istream >> EX1 >> EX2 >> EX3)
    {
        for (int i = 0; i != 1; i++)
		{
			AssemblerCore(EX1, EX2, EX3, output);
		}
    }
    
}

void  JDASM::AssemblerCore(char EX1[], char EX2[], char EX3[], char* out)
{
    Instructions ins;
    if (verbose)
    {
        std::cout <<  "Got file\n";
        std::cout << EX1 << " " << EX2 << " " << EX3 << "\n";
    }
    std::ofstream OutFile;
    OutFile.open(out, std::ios::out | std::ios::app);

    if (!OutFile) 
    {
        std::cerr << "can't open output file" << std::endl;
    }

    if(EX1[0] == 'M' && EX1[1] == 'O' && EX1[2] == 'V')
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
                OutFile << ins.INS_MV << " " << ins.REG_X << " " << EX3 << "\n";
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
                OutFile << ins.INS_MV << " " << ins.REG_A << " " << EX3 << "\n";
            }
        }
        else if (EX2[0] == 'Q')
        {
            if (EX3[0] == 'X')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Q << " " << ins.REG_X << "\n";
            }
            else if (EX3[0] == 'Y')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Q << " " << ins.REG_Y << "\n";
            }
            else if (EX3[0] == 'A')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Q << " " << ins.REG_A << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << ins.REG_Q << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << ins.REG_Q << " " << EX3 << "\n";
            }
        }
        else if (EX2[0] == 'O' && EX2[1] == 'F')
        {
            if (EX3[0] == 'X')
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << ins.REG_X << "\n";
            }
            else if (EX3[0] == 'Y')
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << ins.REG_Y << "\n";
            }
            else if (EX3[0] == 'A')
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << ins.REG_A << "\n";
            }
            else if (EX3[0] == 'Q')
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << ins.REG_Q << "\n";
            }
            else if (EX3[0] == 'K')
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << ins.REG_K << "\n";
            }
            else
            {
                OutFile << ins.INS_MV << " " << ins.REG_OF << " " << EX3 << "\n";
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
        OutFile << ins.INS_JMP << " " << EX2 << " "<< "00" << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'N' && EX1[2] == 'Z')
    {
        OutFile << ins.INS_JNZ << " " << EX2 << " "<< "00" << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'Z')
    {
        OutFile << ins.INS_JZ << " " << EX2 << " " << "00" << "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'N' && EX1[2] == 'E')
    {
        OutFile << ins.INS_JNE << " " << EX2 << " " << "00"<< "\n";
    }
    else if (EX1[0] == 'J' && EX1[1] == 'E')
    {
        OutFile << ins.INS_JE << " " << EX2 << " " << "00" << "\n";
    }
    else if (EX1[0] == 'D' && EX1[1] == 'E' && EX1[2] == 'C')
    {
        if(EX2[0] == 'X')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_X << " " << "00" << "\n";
        }
        else if(EX2[0] == 'Y')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_Y << " "<< "00" << "\n";
        }
        else if(EX2[0] == 'A')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_A << " "<< "00" << "\n";
        }
        else if(EX2[0] == 'Q')
        {
            OutFile << ins.INS_DEC << " " << ins.REG_Q << " "<< "00" << "\n";
        }
    }
    else if (EX1[0] == 'I' && EX1[1] == 'N' && EX1[2] == 'C')
    {
        if(EX2[0] == 'X')
        {
            OutFile << ins.INS_INC << " " << ins.REG_X << " "<< "00" << "\n";
        }
        else if(EX2[0] == 'Y')
        {
            OutFile << ins.INS_INC << " " << ins.REG_Y << " "<< "00" << "\n";
        }
        else if(EX2[0] == 'A')
        {
            OutFile << ins.INS_INC << " " << ins.REG_A << " "<< "00" << "\n";
        }
        else if(EX2[0] == 'Q')
        {
            OutFile << ins.INS_INC << " " << ins.REG_Q << " "<< "00" << "\n";
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
    else if(EX1[0] == 'C' && EX1[1] == 'M' && EX1[2] == 'P' )
    {
        if(EX2[0] == 'X')
        {
            if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_X << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_X << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_X << " " << ins.REG_Q << "\n";
            }
            else
            {
                OutFile << ins.INS_CMP << " " << ins.REG_X << " " << EX3 << "\n";
            }
        }
        else if(EX2[0] == 'Y')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Y << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Y << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Y << " " << ins.REG_Q << "\n";
            }
            else
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Y << " " << EX3 << "\n";
            }
        }
        else if(EX2[0] == 'A')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_A << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_A << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_A << " " << ins.REG_Q << "\n";
            }
            else
            {
                OutFile << ins.INS_CMP << " " << ins.REG_A << " " << EX3 << "\n";
            }
        }
        else if(EX2[0] == 'Q')
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Q << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Q << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Q << " " << ins.REG_A << "\n";
            }
            else
            {
                OutFile << ins.INS_CMP << " " << ins.REG_Q << " " << EX3 << "\n";
            }
        }
        else
        {
            if(EX3[0] == 'X')
            {
                OutFile << ins.INS_CMP << " " << EX2 << " " << ins.REG_X << "\n";
            }
            else if(EX3[0] == 'Y')
            {
                OutFile << ins.INS_CMP << " " << EX2 << " " << ins.REG_Y << "\n";
            }
            else if(EX3[0] == 'A')
            {
                OutFile << ins.INS_CMP << " " << EX2 << " " << ins.REG_A << "\n";
            }
            else if(EX3[0] == 'Q')
            {
                OutFile << ins.INS_CMP << " " << EX2 << " " << ins.REG_Q << "\n";
            }
        }

    }
    else if(EX1[0] == 'I' && EX1[1] == 'N' && EX1[2] == 'T')
    {
        OutFile << ins.INS_INT << " " << EX2 << " 00" <<  "\n";
    }
    else if(EX1[0] == 'S' && EX1[1] == 'T' && EX1[2] == 'I')
    {
        OutFile << ins.INS_STI << " " << "00 " << "00" <<  "\n";
    }
    else if(EX1[0] == 'C' && EX1[1] == 'L' && EX1[2] == 'I')
    {
        OutFile << ins.INS_CLI << " " << "00 " << "00" <<  "\n";
    }
    else if(EX1[0] == 'H' && EX1[1] == 'L' && EX1[2] == 'T')
    {
        OutFile << ins.INS_HLT << " " << "00 " << "00" <<  "\n";
    }
    else if(EX1[0] == 'N' && EX1[1] == 'O' && EX1[2] == 'P')
    {
        OutFile << ins.INS_NOP << " " << "00 " << "00" <<  "\n";
    }
    else if(EX1[0] == 'S' && EX1[1] == 'D' && EX1[2] == 'E')
    {
        OutFile << ins.INS_SDE << " " << "00 " << "00" <<  "\n";
    }
    else if(EX1[0] == 'N' && EX1[1] == 'D' && EX1[2] == 'E')
    {
        OutFile << ins.INS_NDE << " " << "00 " << "00" <<  "\n";
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