#pragma once
#include "Expression.h"
#include "ReferenceValue.h"
class ReferenceExpression :
	public Expression
{

private:
	std::string name_value;

public:
	ReferenceExpression(std::string name_value);
	value_ptr eval(List_variables &main_veriables_list) override;
	~ReferenceExpression();
};

