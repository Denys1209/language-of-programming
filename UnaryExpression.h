#pragma once
#include "Expression.h"
class UnaryExpression :
	public Expression
{
private:
	std::unique_ptr<Expression> expr1;
	char operation;
public:
	UnaryExpression(char operation, std::unique_ptr<Expression> expr1)
	{
		this->expr1 = std::move(expr1);
		this->operation = operation;
	}
	UnaryExpression() = default;
	value_ptr eval(Veriables &main_veriables_list) override
	{
		switch (this->operation)
		{
		case '-':
			return  std::make_unique<NumberValue>(-(*((*expr1).eval(main_veriables_list))).asDouble());
		case '+':
			return std::make_unique<NumberValue>((*((*expr1).eval(main_veriables_list))).asDouble());
		default:
			throw std::exception("");
		}
	}
	std::string get_str() override
	{
		std::string rv = "";
		return rv;
	}
};

