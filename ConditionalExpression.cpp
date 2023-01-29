#include "ConditionalExpression.h"
ConditionalExpression::ConditionalExpression(std::string operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2)
{
	this->expr1 = std::move(expr1);
	this->expr2 = std::move(expr2);
	this->operation = operation;
}

std::string ConditionalExpression::get_str()
{
	std::string res = "(" + (*expr1).get_str() + operation + (*expr2).get_str() + ")";
	return res;
}

value_ptr ConditionalExpression::eval(List_variables &main_veriables_list)
{
	value_ptr val1 = std::move((*expr1).eval(main_veriables_list));
	value_ptr val2 = std::move((*expr2).eval(main_veriables_list));
	
	if (this->operation == "==") {
		return std::make_shared<BoolValue>((*val1).operator_two_equal(val2));
	}
	else if (this->operation == "<") {
		return std::make_shared<BoolValue>((*val1).operator_less(val2));
	}
	else if (this->operation == ">") {
		return std::make_shared<BoolValue>((*val1).operator_more(val2));
	}
	else if (this->operation == ">=") {
		return std::make_shared<BoolValue>((*val1).operator_more_or_equal(val2));
	}
	else if (this->operation == "<=") {
		return std::make_shared<BoolValue>(((*val1).operator_less_or_equal(val2)));
	}
	else if (this->operation == "!=") {
		return std::make_shared<BoolValue>(((*val1).operator_not_equal(val2)));
	}
	else if (this->operation == "||") {
		return std::make_shared<BoolValue>((*val1).operator_or(val2));
	}
	else if (this->operation == "&&") {
		return std::make_shared<BoolValue>(((*val1).operator_two_and(val2)));
	}
	std::string exc = "not so operation "+this->operation;
	throw std::exception(exc.c_str());
}
ConditionalExpression::~ConditionalExpression() {}
