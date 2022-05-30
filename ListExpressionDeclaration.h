#pragma once
#include "Expression.h"
#include "ListValue.h"
class ListExpressionDeclaration :
	public Expression
{
private:
	std::shared_ptr<Expression> val;
public:
	ListExpressionDeclaration(std::shared_ptr<Expression> val)
	{
		this->val = val;
	}
	value_ptr eval(List_variables &main_veriables_list)override
	{
		
		return std::make_shared<ListValue>((*(*val).eval(main_veriables_list)).asInt());
	}
};

