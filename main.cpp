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

#include "ASM/JDASM_CORE.h"

int main(int argc, char** argv)
{
    JDASM jdasm;
    int a;
    if (argc == 1)
    {
        std::cerr << "Assembling terminated\n\n" <<"Please provide a file to assemble" << std::endl;
        return 0;
    }
    if (argc == 2)
    {
        if(strcmp(argv[1], "-o") == false && strcmp(argv[1], "--output") == false && strcmp(argv[1], "--version") == false && strcmp(argv[1], "-v") == false && strcmp(argv[1], "--help") == false && strcmp(argv[1], "-h") == false )
        {
            //jdasm.Assemble(argv[1], "out.exrom");
        }
        else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            std::cout << "JDASM version 1.1.5" << std::endl;
        }
        else if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            std::cout << "JDASM is a simple assembler for the JDASM language which is used in JD1618.\n\n"
                    << "Usage: jdasm [filename] [options]\n"
                    << "Options:\n"
                    << "-o --output : To change the output of the file.\n\n"
                    << "-v --version : To print the version.\n\n"
                    << "-h --help : To print this help.\n\n"
                    << "Example: jdasm test.jdasm\n";
        }
    }
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], "-o") == 0 && strcmp(argv[i], "--output") == 0)
        {
            jdasm.Assemble(argv[1],argv[i + 1]);
            a = i;
        }
        else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0)
        {
            std::cout << "JDASM version 1.1.5" << std::endl;
        }
        else if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            std::cout << "JDASM is a simple assembler for the JDASM language which is used in JD1618.\n\n"
                    << "Usage: jdasm [filename] [options]\n"
                    << "Options:\n"
                    << "-o --output : To change the output of the file.\n\n"
                    << "-v --version : To print the version.\n\n"
                    << "-h --help : To print this help.\n\n"
                    << "Example: jdasm test.jdasm\n";
        }
        else
        {
            if (a + 1 != i)
                jdasm.Assemble(argv[1], "out.exrom");
        }
    }

    return 0;
}