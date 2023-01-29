#pragma once
#include "Expression.h"
class UnaryExpression :
	public Expression
{
private:
	std::shared_ptr<Expression> expr1;
	char operation;
public:
	UnaryExpression(char operation, std::shared_ptr<Expression> expr1);
	UnaryExpression();
	value_ptr eval(List_variables &main_veriables_list) override;
	
	std::string get_str() override;
};

