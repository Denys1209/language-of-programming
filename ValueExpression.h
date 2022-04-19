#pragma once
#include "Expression.h"
#include "DoubleValue.h"
#include "IntValue.h"
#include "BoolValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"

class ValueExpression :
	public Expression
{
private:
	value_ptr value;
public:
	
	ValueExpression(int value)
	{
		this->value = std::make_unique<IntValue>(value);
	}
	ValueExpression(float value)
	{
		this->value = std::make_unique<FloatValue>(value);
	}
	ValueExpression(double value)
	{
		this->value = std::make_unique<DoubleValue>(value);
	}
	
	ValueExpression(std::string value)
	{
		this->value = std::make_unique<StringValue>(value);
	}
	value_ptr eval(List_variables &main_veriables_list) override
	{
		if ((*this->value).is_string()) {
			return std::make_unique<StringValue>((*this->value).asString());
		}
		switch ((*this->value).getType())
		{
		case Token_type::INT:
			return std::make_unique<IntValue>((*this->value).asInt());
		case Token_type::DOUBLE:
			return std::make_unique<DoubleValue>((*this->value).asDouble());
		case Token_type::FLOAT:
			return std::make_unique<FloatValue>((*this->value).asFloat());
		case Token_type::BOOL:
			return std::make_unique<BoolValue>((*this->value).asBool());
		default:
			throw std::exception("unknow type value");

		}
		
	}
	std::string get_str() override 
	{
		return (*this->value).asString();
	}
};

