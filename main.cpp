#include "JDASM_CORE.h"

int main(int argc, char** argv)
{
    JDASM jdasm;
    if (argc == 1)
    {
        std::cout << "Please provide a file to assemble" << std::endl;
        return 0;
    }
    else if(strcmp(argv[2], "--help") == 0)
    {
        std::cout << "JDASM is a simple assembler for the JDASM language which is used in JD1618.\n\n"
                  << "Usage: jdasm [filename] [options]\n"
                  << "Options:\n"
                  << "-o --output : To change the output of the file.\n\n"
                  << "Example: jdasm test.jdasm\n";
    }
    else if (strcmp(argv[2], "--version") == 0)
    {
        std::cout << "JDASM version 1.0.0" << std::endl;
    }
    else if (strcmp(argv[2], "-o") == 0 || strcmp(argv[2], "--output") == 0)
    {
        if(argv[3] == NULL)
        {
            std::cout << "Please provide an output file" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Assembling file: " << argv[1] << std::endl;
            jdasm.Assemble(argv[1], argv[3]);
        }
    }
    else
    {
        std::cout << "Assembling file: " << argv[1] << std::endl;
        jdasm.Assemble(argv[1], "out.exrom");
    }
    return 0;
}