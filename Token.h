#pragma once
#include <string>
#include "Veriables.h"
class Token
{
private:
	Token_type type;
	std::string txt;
public:
	Token() = default;
	
	Token(Token_type type, std::string  txt)
	{
		this->type = type;
		this->txt = txt;
	}
	Token_type getType() 
	{
		return this->type;
	}
	void setType(Token_type type)
	{
		this->type = type;
	}

	std::string getText() 
	{
		return this->txt;
	}
	void setText(std::string txt) 
	{
		this->txt = txt;
	}


};

