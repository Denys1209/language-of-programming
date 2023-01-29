#pragma once
#include "Statement.h"
class SetValueStatement :
	public Statement
{
private:
	std::string varible;
	std::shared_ptr<Expression> exp;

public:
	SetValueStatement(std::string varible, std::shared_ptr<Expression> exp);
	SetValueStatement();
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	
};

