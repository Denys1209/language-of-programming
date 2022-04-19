#pragma once
#include "System_const.h"
#include "Token_types.h"
#include <string>
#include <exception>

class Value
{

public:
	int		virtual asInt()		{ return 0; };
	float	virtual asFloat()	{ return 0; };
	double	virtual asDouble()	{ return 0; };
	bool	virtual asBool()	{ return 0; };
	std::string	virtual asString() { return ""; };
	Token_type virtual getType() { return Token_type::TYPE; }
	
	bool virtual is_string() { return false; }
};
using value_ptr = std::unique_ptr<Value>;

