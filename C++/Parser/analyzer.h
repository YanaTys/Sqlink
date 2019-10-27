#ifndef __ANALYZER_H_
#define __ANALYZER_H_

#include <set>
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "tokenizer.h"




using namespace std;

class analyzer_t
{
	public:
	
	analyzer_t(){};
	void Init();
	void AnalizeLine(tokenizer_t& t, size_t lineNum);
	void Finish();

	private:
	
	analyzer_t(const analyzer_t& _a);
	const analyzer_t& operator=(const analyzer_t& _a);
	
	static  string m_predefinedTypes[];
	static  string m_keyWords[];
	static  string m_operators[];
	static  string m_predefTokens[];
	
	int m_roundBracCount;/*(*/
    int m_curlyBracCount;/*{*/
    int m_squareBracCount;/*[*/
    int m_plusCount;/*+*/
    int m_minusCount;/*-*/
    bool m_if; /*if*/
	
	set<string> m_varNames;

	static set<string> m_predefinedTypesSet;
	static set<string> m_keyWordsSet;
	static set<string> m_operatorsSet;
	static set<string> m_predefTokensSet;
	
	
	bool m_programStarted;
	
	bool m_predefTypeEncountered;
	
	void AnalyzeToken(const string& token,  size_t lineNum);
	
	bool IsValidVarName(const string& token)const;
	
	bool CheckEnclosure(const string& token, const string& pen, const string& close,  size_t lineNum,int & count);
    bool CheckIf(const string& token, const string& open, const string& close,  size_t lineNum,bool& countIf );
	
	bool CheckOperators(const string& token, size_t lineNum);

	void PrintEnclErr(const char& brace,const int&  countBrace);

};

#endif

