#pragma once
#include <String>
#include <vector>
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
	const std::string OPERATOR_CHARS = "+-*/()=";
	const Token_type OPERATOR_TOKENS[8] = { 
		Token_type::PLUS, Token_type::MINUS,
		Token_type::STAR, Token_type::SLASH,
		Token_type::LPAREN, Token_type::RPAREN,
		 Token_type::EQ,Token_type::WORD };
	vector_token tokens;
	bool  EtoBuk(char iCha); 
	bool  EtoCif(char iCha);
	bool EtoCifBuk(char iCha);
public:
	Lexer(std::string inpute)
	{
		this->inpute = inpute;
		this->lenght = inpute.size();
		
	}
	vector_token tokenize();
	void addToken(Token_type type);

	char next();
	char peek(int relativePosition);
	
	void addToken(Token_type type, std::string text);
	void tokenizeNumber();
	void tokenizeWord();

	void tokenizeOperator();
	
};

