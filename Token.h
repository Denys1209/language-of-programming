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
	Token();
	
	Token(Token_type type, std::string  txt);
	Token(const Token &temp);
	Token_type getType() const;
	void setType(Token_type type);

	std::string getText() const;
	void setText(std::string txt);
	Token operator= (const Token &temp);
	

};

