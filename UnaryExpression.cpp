#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(char operation, std::shared_ptr<Expression> expr1)
{
	this->expr1 = std::move(expr1);
	this->operation = operation;
}
UnaryExpression::UnaryExpression() = default;
value_ptr UnaryExpression::eval(List_variables &main_veriables_list) 
{
	switch (this->operation)
	{
	case '-':
		return  std::make_shared<IntValue>(-(*((*expr1).eval(main_veriables_list))).asInt());
	case '+':
		return std::make_shared<IntValue>((*((*expr1).eval(main_veriables_list))).asInt());
	default:
		throw std::exception("");
	}
}
std::string UnaryExpression::get_str() 
{
	std::string rv = "";
	return rv;
}