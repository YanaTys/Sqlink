#ifndef __PARSER_H__
#define __PARSER_H__
#include <iostream>
#include <string.h>
#include <fstream>
class tokenizer_t;
class analyzer_t;

using namespace std;

class parser_t
{
	public:
	
	parser_t();
	virtual ~parser_t();
	
	void ParseFile(const string& fileName);
	
	private:
	
	parser_t(const parser_t& _p);
	parser_t& operator=(const parser_t& _p);
	
	ifstream m_file;

	tokenizer_t* m_tokenizer;
	
	analyzer_t* m_analyzer;
};


#endif 