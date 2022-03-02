#pragma once
#include "Expression.h"
class NumberExpression :
	public Expression
{
private:
	double value;
public:
	NumberExpression(double value)
	{
		this->value = value;
	}
	double eval(Veriables &main_veriables_list) override
	{
		return this->value;
	}
	std::string get_str() override 
	{
		return std::to_string(this->value);
	}
};

