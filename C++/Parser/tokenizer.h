#ifndef __TOKENIZER_H_
#define __TOKENIZER_H_


#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "parser.h"
using namespace std;

class tokenizer_t
{
	public:
	
	tokenizer_t(){};
	~tokenizer_t() {};
	void Tokenize( string& str);

	size_t GetSize()const {return m_tokens.size();};
	vector<string>& getTokensVector() {return m_tokens;};
	static string& getTokensDelimiters(){return m_tokensDelimiters;};
	static void setTokensDelimiters(const string& tokensDelimiters){ m_tokensDelimiters=tokensDelimiters;};
	

	private:
	
	tokenizer_t (const tokenizer_t& _t);
	tokenizer_t& operator=(const tokenizer_t& _t);

	static string m_tokensDelimiters;
	/*const string m_emptyStr;*/
	vector<string> m_tokens;

	vector<string>::iterator m_nextToken;	
};

#endif