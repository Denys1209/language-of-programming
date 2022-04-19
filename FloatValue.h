#pragma once
#include "Value.h"
class FloatValue :
	public Value
{
private:
	float value;
public:
	FloatValue()
	{
		this->value = 0;
	}
	FloatValue(float value)
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

