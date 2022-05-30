#include "ConditionalExpression.h"
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