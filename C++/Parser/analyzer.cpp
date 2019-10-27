#include <iterator>
#include <iostream>
#include <string.h>
#include <fstream>
#include <set>
#include <algorithm>
#include "tokenizer.h"
#include "parser.h"
#include "analyzer.h"

using namespace std;

string analyzer_t::m_predefinedTypes[] =
	{"char", "short", "int", "long", "float", "double", "void"};
string analyzer_t::m_keyWords[] =
	{"if", "else", "for" , "while", "class", 
		"private", "public", "protected", "main", "const", "virtual"};
string analyzer_t::m_operators[] =
	{"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};
string analyzer_t::m_predefTokens[] =
	{"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"};

#define NUMOFELEM(ARR) (sizeof(ARR)/sizeof((ARR)[0]))

set<string> analyzer_t::m_predefinedTypesSet
	(m_predefinedTypes, m_predefinedTypes + NUMOFELEM(m_predefinedTypes));
set<string> analyzer_t::m_keyWordsSet
	(m_keyWords, m_keyWords + NUMOFELEM(m_keyWords));
set<string> analyzer_t::m_operatorsSet
	(m_operators, m_operators + NUMOFELEM(m_operators));
set<string> analyzer_t::m_predefTokensSet
	(m_predefTokens, m_predefTokens + NUMOFELEM(m_predefTokens));


void analyzer_t::Init()
{
	m_programStarted = false;
	m_predefTypeEncountered = false;

     m_roundBracCount=0;
     m_curlyBracCount=0;
     m_squareBracCount=0;
     
     m_plusCount=0;
     m_minusCount=0;
     m_if=false;
}

void analyzer_t::PrintEnclErr(const char& brace, const int&  countBrace)
{
	if(countBrace > 0)
	{
		cout<<"error - "<<brace<<" '"<<countBrace<<"' not closed"<<endl;
	}
}

void analyzer_t::Finish()
{
	 /*m_if=false;*/
	 PrintEnclErr('(',m_roundBracCount);
     PrintEnclErr('{',m_curlyBracCount);
     PrintEnclErr('[',m_squareBracCount);	
}


bool analyzer_t::IsValidVarName(const string& token) const
{
	return (isalpha(token[0]) || token[0] == '_');
}

void analyzer_t::AnalizeLine(tokenizer_t& t, size_t lineNum)
{
	
	vector<string>::iterator m_nextToken;

    m_nextToken = t.getTokensVector().begin();
	
	while (m_nextToken!=t.getTokensVector().end())
	{
		AnalyzeToken(*m_nextToken,lineNum);
		m_nextToken++;
	}
}

bool analyzer_t::CheckEnclosure(const string& token, const string& open, const string& close,  size_t lineNum,int& count )
{
	if(close == token)
	{        if(m_predefTypeEncountered)
              {       cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                        m_predefTypeEncountered=false;
              }

            if(count>0){
                count--;
            }
            else
		    {
			    cout<<"line "<<lineNum<<": error - "<<close<<" without "<<open<<"\n"<<endl;
		    }	 
		    return true;
	}
	if(open == token)
	{
		count++;
		return true;
	}
	return false;	
} 
bool analyzer_t::CheckIf(const string& token, const string& open, const string& close,  size_t lineNum,bool& count )
{
    if(token =="else"&&count==false)
    {
       cout<<"line "<<lineNum<<": error - "<<close<<" without "<<open<<"\n"<<endl;
       if(m_predefTypeEncountered)
              {       cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                        m_predefTypeEncountered=false;
              }

       return true; 
    }
    else  if(token =="if")
     {   count=true;
        if(m_predefTypeEncountered)
              {       cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                        m_predefTypeEncountered=false;
              }

        return true;
    }
    else if(token =="else"&&count==true)
    { 
        if(m_predefTypeEncountered)
              {       cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                        m_predefTypeEncountered=false;
              }

        return true;
    }
    return false;
}

bool analyzer_t::CheckOperators(const string& token, size_t lineNum)
{
            if (token=="+")
            {   if(m_predefTypeEncountered)
                 {    cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                        m_predefTypeEncountered=false;
                 }
                if(m_plusCount==2)
               {   
                    cout<<"line "<<lineNum<<": error - no operator +++"<<endl;
                    m_plusCount==0;
                    
                    return true;
               }
               else 
               {    m_plusCount++;
                    m_minusCount=0;
                    return true;
               }
            }
             else if (token=="-")
             {   if(m_predefTypeEncountered)
                 {    cout<<"line "<<lineNum<<": error - illegal variable name"<<endl;
                         m_predefTypeEncountered=false;
                 }
                 if(m_minusCount==2)
               {
               cout<<"line "<<lineNum<<": error - no operator ----"<<endl;
               m_minusCount==0;
               return true;}
                else 
                {    m_minusCount++;
                     m_plusCount=0;
                     return true;
                }
            }
            m_minusCount=0;
            m_plusCount=0;
            return false;
			
		}



void analyzer_t::AnalyzeToken(const string& token,  size_t lineNum)
{
	
	if(!m_programStarted)
	{
		if(token != "main")
		{
			cout<<"line "<<lineNum<<": error - the program doesn't start with 'main'\n"<<endl;
		}
		m_programStarted = true;
	}
	if (CheckOperators(token,lineNum))
	{
		return;
	}
	
	if (CheckEnclosure(token,"(",")",lineNum,m_roundBracCount) ||
		CheckEnclosure(token,"[","]",lineNum,m_squareBracCount) ||
		CheckEnclosure(token,"{","}",lineNum,m_curlyBracCount) ||
		CheckIf(token,"if","else",lineNum,m_if))
	{
		return;
	}
	
	if (m_predefinedTypesSet.find(token) != m_predefinedTypesSet.end())
	{
		if(m_predefTypeEncountered)
		{   
			cout<<"line "<<lineNum<<": error - multiple type declaration\n"<<endl;
			m_predefTypeEncountered = false;
		}else
		{
			m_predefTypeEncountered = true;
		}
		return;
	}
	
	if(m_predefTypeEncountered)
	{
		if (m_keyWordsSet.find(token) != m_keyWordsSet.end() ||
			m_operatorsSet.find(token) != m_operatorsSet.end() ||
			m_predefTokensSet.find(token) != m_predefTokensSet.end())
		{
			cout<<"line "<<lineNum<<": error - illegal variable name\n"<<endl;
		}else
		{
			if(m_varNames.find(token) != m_varNames.end())
			{
				cout<<"line "<<lineNum<<": error - variable '"<<token<<"' already declared\n"<<endl;			
			}else
			{
				if(IsValidVarName(token))
				{
					m_varNames.insert(token);
				}else
				{
					cout<<"line "<<lineNum<<": error - illegal variable name\n"<<endl;
				}
			}
		}
		m_predefTypeEncountered = false;
	}else
	{
		if (!(m_keyWordsSet.find(token) != m_keyWordsSet.end() ||
			m_operatorsSet.find(token) != m_operatorsSet.end() ||
			m_predefTokensSet.find(token) != m_predefTokensSet.end()) &&
			IsValidVarName(token) &&
			m_varNames.find(token) == m_varNames.end())
		{
			cout<<"line "<<lineNum<<": error - "<<token<<" is not declared\n"<<endl;
		}
	}
}