#pragma once
#include "Expression.h"
class BinaryExpression :
	public Expression
{
private:
	std::unique_ptr<Expression> expr1, expr2;
	char operation;
public:
	BinaryExpression(char operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2)
	{
		this->expr1 = std::move(expr1);
		this->expr2 = std::move(expr2);
		this->operation = operation;
	}
	double eval(Veriables &main_veriables_list) override
	{
		switch (operation)
		{
		case '+':
			return (*expr1).eval(main_veriables_list) + (*expr2).eval(main_veriables_list);
			break;
		case '-':
			return (*expr1).eval(main_veriables_list) - (*expr2).eval(main_veriables_list);
			break;
		case '*':
			return (*expr1).eval(main_veriables_list) * (*expr2).eval(main_veriables_list);
			break;
		case '/':
			return (*expr1).eval(main_veriables_list) / (*expr2).eval(main_veriables_list);
			break;
		default:
			return (*expr1).eval(main_veriables_list) + (*expr2).eval(main_veriables_list);
			break;
		}
	}
	std::string get_str() override 
	{
		std::string res ="("+(*expr1).get_str() + operation + (*expr2).get_str()+")";
		return res;
	}
};

