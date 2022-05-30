#pragma once
#include "Expression.h"
#include "Expression.h"
#include "IntValue.h"
#include <typeinfo>
#include "StringValue.h"
#include "BoolValue.h"
class ConditionalExpression :
	public Expression

{
private:
	std::shared_ptr<Expression> expr1, expr2;
	std::string operation;
public:
	ConditionalExpression(std::string operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2)
	{
		this->expr1 = std::move(expr1);
		this->expr2 = std::move(expr2);
		this->operation = operation;
	}
	value_ptr eval(List_variables &main_veriables_list) override;
	std::string get_str() override
	{
		std::string res = "(" + (*expr1).get_str() + operation + (*expr2).get_str() + ")";
		return res;
	}
};
