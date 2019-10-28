#include <iostream>
#include <string.h>
#include <fstream>
#include "tokenizer.h"
#include "analyzer.h"
#include "parser.h"

using namespace std;

parser_t::parser_t() : m_tokenizer(new tokenizer_t) ,m_analyzer(new analyzer_t) {}


parser_t::~parser_t()
{
	delete m_tokenizer;
	delete m_analyzer;
}


void parser_t::ParseFile(const string& fileName)
{   
	m_file.open(fileName.c_str());

	if(!m_file.good())
	{
		return;
	}
	
	m_analyzer->Init();
	
	string nextLine;
	size_t lineNum = 1;

	while(1)
	{	nextLine="";
		getline(m_file,nextLine);
		/*cout<<nextLine<<endl;*/

		if(m_file.eof())
		{	/*cout<<"end of file"<<endl;*/
			break;
		}
	
		m_tokenizer->Tokenize(nextLine);
		
		if(0 < m_tokenizer->GetSize())
		{
			m_analyzer->AnalizeLine(*m_tokenizer,lineNum);
		}
		
		++lineNum;
	}
	
	m_analyzer->Finish();
	
	m_file.close();
}