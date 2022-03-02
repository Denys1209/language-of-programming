#pragma once
#include "Expression.h"

class constantExpression :
	public Expression
{
private:
	std::string name;
	
public:
	constantExpression(std::string name)
	{
		this->name = name;
	}
	double eval(Veriables &main_veriables_list) override
	{
		return main_veriables_list.get(name);
	}
	std::string get_str()override
	{
		
		return this->name;
	}
};

