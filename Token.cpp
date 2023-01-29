#include "Token.h"
Token::Token() = default;

Token::Token(Token_type type, std::string  txt)
{
	this->type = type;
	this->text = txt;
}
Token::Token(const Token &temp) :Token(temp.type, temp.text) {};
Token_type Token::getType() const
{
	return this->type;
}
void Token::setType(Token_type type)
{
	this->type = type;
}

std::string Token::getText() const
{
	return this->text;
}
void Token::setText(std::string txt)
{
	this->text = txt;
}
Token Token::operator= (const Token &temp)
{
	if (this == &temp) { return *this; }
	this->text = temp.text;
	this->type = temp.type;
	return *this;
}