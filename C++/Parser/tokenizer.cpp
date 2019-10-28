
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "tokenizer.h"
#include "analyzer.h"
#include "parser.h"

using namespace std;

string tokenizer_t::m_tokensDelimiters = "()[]{};<>=+-*&";


void tokenizer_t::Tokenize(string& str)
{
	size_t pos, next, len = str.length();
	
	m_tokens.clear();
	
	for(pos = 0, next = 0; next < len ; ++next)
	{
		if(isspace(str[next]))
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
			
			m_tokens.push_back(str.substr(next,1));
			pos = next+1;
		}
		
	}
	if(pos<next)
			m_tokens.push_back(string(str,pos,next-pos));
	m_nextToken=m_tokens.begin();

}

