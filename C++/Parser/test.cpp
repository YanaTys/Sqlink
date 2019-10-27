
#include <iostream>
#include <string.h>
#include <fstream>
#include "tokenizer.h"
#include "analyzer.h"
#include "parser.h"


int main()
{
	parser_t* pars=new parser_t();
    
         pars->ParseFile("testFile.txt");

    
    
    delete pars;

	return 0;
}
