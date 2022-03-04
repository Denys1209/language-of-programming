#pragma once
#include "Value.h"
class NumberValue :
	public Value
{
private:
	double value;
public:
	NumberValue(double value)
	{
		this->value = value;
	}
	double asDouble() override 
	{
		return this->value;
	}
	std::string asString() override
	{
		return std::to_string(this->value);
	}
	bool is_string() override { return false; }


};
