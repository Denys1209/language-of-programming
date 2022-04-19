#pragma once
#include "Value.h"
class BoolValue :
	public Value
{
private:
	bool value;
public:

	BoolValue()
	{
		this->value = false;
	}
	BoolValue(bool value)
	{
		this->value = value;
	}
	BoolValue(std::string value)
	{
		if (value == "") 
		{
			this->value = false;
		}
		else {
			this->value = true;
		}
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
	Token_type getType() override { return Token_type::BOOL; }
	std::string asString() override
	{
		if (this->value) {
			return "true";
		}
		else
		{
			return "false";
		}
	}
	bool is_string() override { return false; }
};

