#pragma once
#include <string>
//#include "Veriables.h"
#include "Token_Types.h"
class Token
{
private:
	Token_type type;
	std::string text;
public:
	Token() = default;
	
	Token(Token_type type, std::string  txt)
	{
		this->type = type;
		this->text = txt;
	}
	Token(const Token &temp):Token(temp.type, temp.text){}
	Token_type getType() const
	{
		return this->type;
	}
	void setType(Token_type type)
	{
		this->type = type;
	}

	std::string getText() const 
	{
		return this->text;
	}
	void setText(std::string txt) 
	{
		this->text = txt;
	}
	Token operator= (const Token &temp)
	{
		this->text = temp.text;
		this->type = temp.type;
		return *this;
	}

};

