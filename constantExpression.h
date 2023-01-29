#pragma once
#include "Expression.h"

class constantExpression :
	public Expression
{
private:
	std::string name;
	
public:
	constantExpression(std::string name);
	value_ptr eval(List_variables &main_veriables_list) override;
	std::string get_str()override;
};

