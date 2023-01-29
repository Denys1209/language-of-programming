#pragma once
#include "Statement.h"
#include <iostream> 
class PrintStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> exp;
public:
	PrintStatement(std::shared_ptr<Expression> exp);
	void execute(List_variables &main_veriables_list) override;
	std::string get_str();
};

