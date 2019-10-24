#ifndef __TOKENIZER_H_
#define __TOKENIZER_H_


#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "analyzer.h"

using namespace std;

class tokenizer_t
{
	public:
	
	tokenizer_t(): m_tokensDelimiters("()[]{};<>=+-*&"),m_blankDelimiters(" \n\t\v\f\r"),m_emptyStr("") {};
	~tokenizer_t() {};
	void Tokenize(const string& _str);

	size_t GetSize() const {return m_tokens.size();};
	
	/*const string& GetNextToken(); */

	private:
	
	tokenizer_t (const tokenizer_t& _t);
	tokenizer_t& operator=(const tokenizer_t& _t);

	const string m_tokensDelimiters;
	const string m_blankDelimiters;
	const string m_emptyStr;
	vector<string> m_tokens;

	vector<string>::iterator m_nextToken;	
};


void tokenizer_t::Tokenize(const string& str)
{
	size_t pos, next, len = str.length();
	
	m_tokens.clear();
	
	for(pos = 0, next = 0; next <= len ; ++next)
	{
		if(m_blankDelimiters.find(str[next]) != string::npos)
		{
			if(next > pos)
			{
				m_tokens.push_back(string(str,pos,next-pos));
			}
			pos = next+1;
			
		}
		else if(m_tokensDelimiters.find(str[next]) != string::npos)
		{
			if(next > pos)
			{
				m_tokens.push_back(string(str,pos,next-pos));
			}
			
			m_tokens.push_back(str.substr(str[next],1));
			pos = next+1;
		}
	}
	
	 m_nextToken = m_tokens.begin();
}


#endif