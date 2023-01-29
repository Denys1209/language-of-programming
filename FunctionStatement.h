#pragma once
#include "Statement.h"
#include "Expression.h"
class FunctionStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> exp;
public:
	FunctionStatement(std::shared_ptr<Expression> exp);
	FunctionStatement();
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	~FunctionStatement();
};

