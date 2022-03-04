#include "Lexer.h"

bool Lexer::EtoBuk(char iCha)
{ 

	bool Rez = false;
	if (iCha >= 'a' && iCha <= 'z') Rez = true; else
		if (iCha >= 'A' && iCha <= 'Z') Rez = true; else
			if (iCha == '_' && iCha == '&') Rez = true;
	return Rez;

}
bool   Lexer::EtoCif(char iCha) { // ОРпределяет цифра ли это ?

	bool Rez = false;
	if (iCha >= '0' && iCha <= '9') Rez = true;
	return Rez;

}
bool   Lexer::EtoCifBuk(char iCha) { // Если это Буква или цифра то true

	return (EtoBuk(iCha) || EtoCif(iCha));

}
vector_token Lexer::tokenize()
{

	while (this->pos < this->lenght)
	{
		char current = peek(0);
		if (this->EtoCif(current)) { tokenizeNumber(); }

		else if (OPERATOR_CHARS.find(current) != std::string::npos)
		{
			this->tokenizeOperator();
		}
		else if (current == '"')
		{
			this->tokenizeText();
		}
		else if (this->EtoBuk(current))
		{
			this->tokenizeWord();
		}
		else
		{
			this->next();
		}
	}
	return tokens;
}
void  Lexer::tokenizeNumber()
{
	char current = peek(0);
	std::string stringbuilder = "";
	while (true)
	{
		if (current == '.') 
		{
			if (stringbuilder.find(current) != std::string::npos)
			{
				throw std::exception("invalid double number");
			}
		}
		else if (!this->EtoCif(current)) {
			break;
		}
		stringbuilder.push_back(current);
		current = this->next();
	}
	this->addToken(Token_type::NUMBER, stringbuilder);
}
char Lexer::peek(int relativePosition)
{
	int position = this->pos + relativePosition;
	if (position >= this->lenght) return '\0';
	return inpute[position];
}
void Lexer::tokenizeOperator()
{
	int position = this->OPERATOR_CHARS.find(peek(0));
	this->addToken(this->OPERATOR_TOKENS[position]);
	this->next();
}
void Lexer::addToken(Token_type type)
{
	this->addToken(type, "");
}
char Lexer::next()
{
	this->pos++;
	return peek(0);
}
void Lexer::addToken(Token_type type, std::string text)
{
	tokens.push_back(Token(type, text));
}
void Lexer::tokenizeWord()
{
	std::string stringbuilder = "";
	char current = peek(0);
	while (true)
	{
		if (!this->EtoCifBuk(current))
		{
			break;
		}
		stringbuilder.push_back(current);
		current = next();
	}
	if (stringbuilder == "print") 
	{
		this->addToken(Token_type::PRINT);
	}
	else {
		this->addToken(Token_type::WORD, stringbuilder);
	}
}
void Lexer::tokenizeText()
{
	next();
	std::string stringbuilder = "";
	char current = peek(0);
	while (true)
	{
		if (current == '\\') 
		{
			current = next();
			switch (current) 
			{
			case '"':
				current = next();
				stringbuilder.push_back('\"');
				continue;
			case 'n':
				current = next();
				stringbuilder.push_back('\n');
				continue;
			case '\t':
				current = next();
				stringbuilder.push_back('\t');
				continue;
			}
			stringbuilder.push_back('\\');
			continue;
		}
		if (current =='"')
		{
			break;
		}
		stringbuilder.push_back(current);
		current = next();
	}
	next();
	
	this->addToken(Token_type::TEXT, stringbuilder);
	
}