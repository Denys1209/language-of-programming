#pragma once
#include "Expression.h"
#include "ReferenceValue.h"
class ReferenceExpression :
	public Expression
{

private:
	std::string name_value;

public:
	ReferenceExpression(std::string name_value)
	{
		this->name_value = name_value;
	}
	 value_ptr eval(List_variables &main_veriables_list) override 
	 {

		 return std::make_shared<ReferenceValue>(main_veriables_list.get_value(this->name_value));
	 };
};

