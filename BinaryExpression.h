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
	std::shared_ptr<Expression> expr1, expr2;
	char operation;
	std::shared_ptr<IntValue> BinaryInt(int val1, int val2);
	std::shared_ptr<DoubleValue> BinaryDouble(double val1, double val2);
	std::shared_ptr<FloatValue> BinaryFloat(float val1, float val2);
	std::shared_ptr<StringValue> BinaryString(value_ptr val1, value_ptr val2);
public:
	BinaryExpression(char operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2)
	{
		this->expr1 = std::move(expr1);
		this->expr2 = std::move(expr2);
		this->operation = operation;
	}
	value_ptr eval(List_variables &main_veriables_list) override
	{
		value_ptr val1 = (*expr1).eval(main_veriables_list);
		value_ptr val2 = (*expr2).eval(main_veriables_list);

		switch (this->operation)
		{
		case '+':
			return (*val1).operator_plus(val2);
		case '-':
			return (*val1).operator_minus(val2);
		case '*':
			return (*val1).operator_multiply(val2);
		case '/':
			return (*val1).operator_share(val2);
		}
		std::string buf = OVERLOAD_COMBINATION_OF_TYPE + this->operation;
		throw std::exception(buf.c_str());
	}
	std::string get_str() override 
	{
		std::string res ="("+(*expr1).get_str() + operation + (*expr2).get_str()+")";
		return res;
	}
};

