#pragma once
#include "Value.h"

class IntValue :
	public Value
{
private:
	int value;
public:
	IntValue()
	{
		this->value = 0;
	}
	IntValue(int value)
	{
		this->value = value;
	}
	int asInt() override
	{
		return this->value;
	}
	double asDouble() override
	{
		return this->value;
	}
	float asFloat() override
	{
		return this->value;
	}
	bool asBool() override
	{
		return this->value;
	}
	Token_type getType() override { return Token_type::INT; }
	std::string asString() override
	{
		return std::to_string(this->value);
	}
	bool is_string() override { return false; }


};
