#pragma once
#include "Expression.h"
#include "NumberValue.h"
#include "StringValue.h"
class ValueExpression :
	public Expression
{
private:
	value_ptr value;
public:
	ValueExpression(double value)
	{
		this->value = std::make_unique<NumberValue>(value);
	}
	ValueExpression(std::string value)
	{
		this->value = std::make_unique<StringValue>(value);
	}
	value_ptr eval(Veriables &main_veriables_list) override
	{
		return std::make_unique<StringValue>((*this->value).asString());
	}
	std::string get_str() override 
	{
		return (*this->value).asString();
	}
};

