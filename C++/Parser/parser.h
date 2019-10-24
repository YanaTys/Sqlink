#ifndef __PARSER_H__
#define __PARSER_H__
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "tokenizer.h"
#include "analyzer.h"

using namespace std;

class parser_t
{
	public:
	
	parser_t();
	virtual ~parser_t();
	
	void ParseFile(const string& fileName);//throws on wrong file
	
	private:
	
	parser_t(const parser_t& _p);
	parser_t& operator=(const parser_t& _p);
	
	ifstream m_file;

	tokenizer_t* m_tokenizer;
	
	analyzer_t* m_analyzer;
};

parser_t::parser_t() : m_tokenizer(new tokenizer_t) ,m_analyzer(new analyzer_t) {}


parser_t::~parser_t()
{
	delete m_tokenizer;
	delete m_analyzer;
}


void parser_t::ParseFile(const string& fileName)
{   int i=1;
	m_file.open(fileName.c_str());

	if(!m_file.good())
	{
		throw i;
	}
	
	m_analyzer->Init();
	
	string nextLine;
	size_t lineNum = 1;

	while(1)
	{
		getline(m_file,nextLine);
		
		if(!m_file.good())
		{
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
#endif 