#pragma once
#include "Statement.h"
#include <iostream> 
class PrintStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> exp;
public:
	PrintStatement(std::shared_ptr<Expression> exp)
	{
		this->exp = std::move(exp);
	}
	void execute(List_variables &main_veriables_list) override
	{
		std::cout << (*(*this->exp).eval(main_veriables_list)).asString();
	}
	std::string get_str() 
	{
		return "print " + (*this->exp).get_str();
	}
};

