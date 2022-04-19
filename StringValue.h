#pragma once
#include "Value.h"
class StringValue :
	public Value
{
private:
	std::string value;
public:
	StringValue()
	{
		this->value = "";
	}
	StringValue(std::string value)
	{
		this->value = std::move(value);
	}
	int asInt() override
	{
		
		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	float asFloat() override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	double asDouble() override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	bool asBool() override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	Token_type getType() override { return Token_type::STRING; }
	std::string asString() override
	{
		return this->value;
	}
	bool is_string() override { return true; }
};

