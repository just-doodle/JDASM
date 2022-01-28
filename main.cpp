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
#include "Include/PVARS.h"

#define JDASM_VERSION "2.4.0"

char* GetEnv(const char* var) 
{
    char *val = std::getenv(var);
    if ( val == nullptr ) 
    {
        return "";
    }
    else 
    {
        return val;
    }
}

int main(int argc, char** argv)
{
    JDASM jdasm;
    int a;

    std::cout << GetEnv("VERBOSE") << std::endl;
    if(strcmp(GetEnv("VERBOSE"), "1") != 0)
    {
        verbose = false;
        std::cout << "Verbose mode is off" << std::endl;
    }
    else
    {
        verbose = true;
        std::cout << "Verbose mode is on" << std::endl;
    }

    if (argc == 1)
    {
        std::cerr << "Assembling terminated\n\n" <<"Please provide a file to assemble" << std::endl;
        return 0;
    }
    else if (strcmp(argv[1], "--version") != 0 && strcmp(argv[1], "--help") != 0 && strcmp(argv[1], "-h") != 0 && strcmp(argv[1], "-o") != 0 && strcmp(argv[1], "--output") != 0 && strcmp(argv[1], "-v") != 0 && strcmp(argv[1], "--verbose") != 0)
    {
        jdasm.Assemble(argv[1], "out.exrom");
    }
    else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
    {
        std::cout << "JDASM version " << JDASM_VERSION << std::endl;
    }
    else if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        std::cout << "JDASM is a simple assembler for the JDASM language which is used in JD1618.\n\n"
                << "Usage: jdasm [options] [filename]\n"
                << "Usage: jdasm [filename]\n"
                << "-o --output [Output Filename] : To change the output of the file.\n\n"
                << "-v --version : To print the version.\n\n"
                << "-h --help : To print this help.\n\n"
                << "To print verbose mode, use the following command: export VERBOSE=1\n"
                << "Example: jdasm test.jdasm\n";
    }
    else if (strcmp(argv[1], "-o") == 0 || strcmp(argv[1], "--output") == 0)
    {
        jdasm.Assemble(argv[3],argv[2]);
    }

    return 0;
}