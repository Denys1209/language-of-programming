#pragma once
#include "Value.h"
class DoubleValue :
	public Value
{
private:
	double value;
public:
	DoubleValue()
	{
		this->value = 0;
	}
	DoubleValue(double value)
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
	Token_type getType() override { return Token_type::FLOAT; }
	std::string asString() override
	{
		return std::to_string(this->value);
	}
	bool is_string() override { return false; }
};

