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
	value_ptr eval(Veriables &main_veriables_list) override
	{
		return std::make_unique<NumberValue>((*main_veriables_list.get(name)).asDouble());
	}
	std::string get_str()override
	{
		
		return this->name;
	}
};

