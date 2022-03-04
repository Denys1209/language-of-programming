#pragma once
#include "Value.h"
class StringValue :
	public Value
{
private:
	std::string value;
public:
	StringValue(std::string value)
	{
		this->value = std::move(value);
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
	std::string asString() override
	{
		return this->value;
	}
	bool is_string() override { return true; }
};

