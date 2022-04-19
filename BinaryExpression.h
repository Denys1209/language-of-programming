#pragma once
#include "Expression.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "BoolValue.h"
#include "StringValue.h"
class BinaryExpression :
	public Expression
{
private:
	std::unique_ptr<Expression> expr1, expr2;
	char operation;
	std::unique_ptr<IntValue> BinaryInt(int val1, int val2);
	std::unique_ptr<DoubleValue> BinaryDouble(double val1, double val2);
	std::unique_ptr<FloatValue> BinaryFloat(float val1, float val2);
	std::unique_ptr<StringValue> BinaryString(value_ptr val1, value_ptr val2);
public:
	BinaryExpression(char operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2)
	{
		this->expr1 = std::move(expr1);
		this->expr2 = std::move(expr2);
		this->operation = operation;
	}
	value_ptr eval(List_variables &main_veriables_list) override
	{
		value_ptr val1 = std::move((*expr1).eval(main_veriables_list));
		value_ptr val2 = std::move((*expr2).eval(main_veriables_list));
		if ((*val1).getType() == Token_type::STRING && (*val2).getType() == Token_type::STRING)
		{
			return this->BinaryString(std::move(val1), std::move(val2));
		}
		else if ((*val1).getType() == Token_type::FLOAT && (*val2).getType() == Token_type::FLOAT)
		{
			return this->BinaryFloat((*val1).asFloat(), (*val2).asFloat());
		}
		else if ((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::INT)
		{
			return this->BinaryInt((*val1).asInt(), (*val2).asInt());
		}
		else if ((*val1).getType() == Token_type::DOUBLE && (*val2).getType() == Token_type::DOUBLE)
		{
			return this->BinaryDouble((*val1).asDouble(), (*val2).asDouble());
		}
		else if (((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::FLOAT) || ((*val2).getType() == Token_type::INT && (*val1).getType() == Token_type::FLOAT))
		{
			return this->BinaryFloat((*val1).asFloat(), (*val2).asFloat());
		}
		else if (((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::DOUBLE) || ((*val2).getType() == Token_type::INT && (*val1).getType() == Token_type::DOUBLE))
		{
			return this->BinaryDouble((*val1).asDouble(), (*val2).asDouble());
		}
		else if (((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::STRING) || ((*val2).getType() == Token_type::INT && (*val1).getType() == Token_type::STRING))
		{
			return this->BinaryString(std::move(val1), std::move(val2));
		}
		else if (((*val1).getType() == Token_type::DOUBLE && (*val2).getType() == Token_type::STRING) || ((*val2).getType() == Token_type::DOUBLE && (*val1).getType() == Token_type::STRING))
		{
			return this->BinaryString(std::move(val1), std::move(val2));
		}
		else if (((*val1).getType() == Token_type::FLOAT && (*val2).getType() == Token_type::STRING) || ((*val2).getType() == Token_type::FLOAT && (*val1).getType() == Token_type::STRING))
		{
			return this->BinaryString(std::move(val1), std::move(val2));
		}
		else { throw std::exception(OVERLOAD_COMBINATION_OF_TYPE); }
	}
	std::string get_str() override 
	{
		std::string res ="("+(*expr1).get_str() + operation + (*expr2).get_str()+")";
		return res;
	}
};

