#pragma once
#include <unordered_map>
#include <String>
#include <vector>
#include <list>
#include "Token.h"
#include <iostream>
#include <exception>
#include <algorithm>

using vector_token = std::vector<Token>;
class Lexer
{
private:
	
	std::string	inpute;
	int pos, lenght;
	std::unordered_map<std::string, Token_type> OPERATOR = {
		{"+", Token_type::PLUS},
		{"-", Token_type::MINUS},
		{"*", Token_type::STAR},
		{"/", Token_type::SLASH},
		{"(", Token_type::LPAREN},
		{")", Token_type::RPAREN},
		{"=", Token_type::EQ},
		{"print", Token_type::PRINT},
		{"<", Token_type::LT},
		{">", Token_type::GT},
		{"if", Token_type::IF},
		{"else", Token_type::ELSE},
		{"==", Token_type::DEQ},
		{"<=", Token_type::LTEQ},
		{">=", Token_type::GTEQ},
		{"!=", Token_type::NOEQ},
		{"&", Token_type::AMP},
		{"&&", Token_type::AMPAMP},
		{"|", Token_type::BAR},
		{"||", Token_type::BARBAR},
		{"!", Token_type::NO},
		{"{", Token_type::LBRACE},
		{"}", Token_type::RBRACE},
		{"[",Token_type::LSQUARE_BRACKET },
		{"]",Token_type::RSQUARE_BRACKET },
		{"int", Token_type::INT},
		{"float", Token_type::INT},
		{"double", Token_type::INT},
		{"string", Token_type::STRING},
		{"list", Token_type::LIST},
		{"bool", Token_type::BOOL},
		{"input", Token_type::INPUT},
		{"for", Token_type::FOR},
		{"while", Token_type::WHILE},
		{";", Token_type::COMMAPOINT},
		{",", Token_type::COMMA},
		{"break",Token_type::BREAK},
		{"continue",Token_type::CONTINUE},
		{"do",Token_type::DO},
		{"void",Token_type::VOID},
		{"return",Token_type::RETURN},
		{"list",Token_type::LIST },
		{"ref",Token_type::REFERENCE },
		{"struct", Token_type::STRUCT},
		{".", Token_type::POINT}
		
		};
	
	

	vector_token tokens;
	bool  EtoBuk(char iCha); 
	bool  EtoCif(char iCha);
	bool EtoCifBuk(char iCha);

	void addToken(Token_type type);
	char next();
	char peek(int relativePosition);
	void addToken(Token_type type, std::string text);
	void addToken(Token token);
	void tokenizeNumber();
	void tokenizeWord();
	void tokenizeDoubleOperator();
	void tokenizeOperator();
	void tokenizeText();
	void tokenizeComment();
	void tokenizeMultilineComment();
public:
	Lexer(std::string inpute)
	{
		this->inpute = inpute;
		this->lenght = inpute.size();
		
	}
	vector_token tokenize();
	
	
};

