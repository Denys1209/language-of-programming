#pragma once
#include "Expression.h"
#include "NumberValue.h"
#include <typeinfo>
#include "StringValue.h"
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
	value_ptr eval(Veriables &main_veriables_list) override
	{
		value_ptr val1 = std::move((*expr1).eval(main_veriables_list));
		value_ptr val2 = std::move((*expr2).eval(main_veriables_list));
		if ((*val1).is_string()) 
		{
			std::string string1 = (*val1).asString();
			std::string string2 = (*val2).asString();
			if (operation == '+') {

				return std::make_unique<StringValue>(string1 + string2);
			
			}
			else if (operation == '*') {
				int iteration = (*val2).asDouble();
				std::string buffer = "";
				for (int i = 0; i < iteration; ++i)
				{
					buffer += string1;
				}
				return std::make_unique<StringValue>(buffer);
			}
			else {
				throw std::exception("unkow operation");
			}
		}
		double number_1 = (*val1).asDouble();
		double number_2 = (*val2).asDouble();
		switch (operation)
		{
		case '+':
			return std::make_unique<NumberValue>(number_1 + number_2);
			break;
		case '-':
			return std::make_unique<NumberValue>(number_1 - number_2);
			break;
		case '*':
			return std::make_unique<NumberValue>(number_1 * number_2);
			break;
		case '/':
			return std::make_unique<NumberValue>(number_1 / number_2);
			break;
		default:
			throw std::exception("unkow operation");
			break;
		}
	}
	std::string get_str() override 
	{
		std::string res ="("+(*expr1).get_str() + operation + (*expr2).get_str()+")";
		return res;
	}
};

