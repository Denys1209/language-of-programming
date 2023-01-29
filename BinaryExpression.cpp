#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(char operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2)
{
	this->expr1 = std::move(expr1);
	this->expr2 = std::move(expr2);
	this->operation = operation;
}
value_ptr BinaryExpression::eval(List_variables &main_veriables_list) 
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
std::string BinaryExpression::get_str() 
{
	std::string res = "(" + (*expr1).get_str() + operation + (*expr2).get_str() + ")";
	return res;
}