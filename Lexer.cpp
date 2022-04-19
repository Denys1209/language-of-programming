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
		std::string cur = "";
		cur += peek(0);
		cur += peek(1);
		if (this->EtoCif(current)) { tokenizeNumber(); }
		else if (OPERATOR.find(cur) != OPERATOR.end() && peek(2) == ' ')
		{
			this->tokenizeDoubleOperator();
		}
		else if (cur == "//") 
		{
			this->next();
			this->next();
			this->tokenizeComment();
		}
		else if (cur == "/*") 
		{
			this->next();
			this->next();
			this->tokenizeMultilineComment();
		}
		else if (OPERATOR.find(std::string(1,current)) != OPERATOR.end())
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
	char current = this->peek(0);

	addToken(this->OPERATOR[std::string(1, current)]);
	next();
}
void Lexer::tokenizeDoubleOperator()
{
	std::string tok = "";
	tok = peek(0);
	tok += peek(1);
	this->addToken(this->OPERATOR[tok]);
	this->next();
	this->next();
}
void Lexer::tokenizeMultilineComment() 
{
	char current = peek(0);
	while (true)
	{
		if (current == '\0') throw std::exception("Missing close tag");
		if (current == '*' && peek(1) == '/') break;
		current = next();
	}
	next();
	next();
}
void Lexer::tokenizeComment() 
{
	char current = peek(0);
	while (true) 
	{
		if (current == '\n' || current == '\0' || current == '\r') break;
		current = next();
	}
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
void Lexer::addToken(Token token)
{
	tokens.push_back(token);
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
	if (this->OPERATOR.find(stringbuilder) != this->OPERATOR.end())
	{
		this->addToken(this->OPERATOR[stringbuilder]);
	}
	/*else if (this->TYPE_MAP.find(stringbuilder) != this->TYPE_MAP.end())
	{
		this->addToken(this->TYPE_MAP[stringbuilder]);
	}*/
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