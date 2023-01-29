#pragma once
#include "Statement.h"
#include "Expression.h"
class AssigmentStatement : public Statement
{
private:
	std::string varible;
	std::shared_ptr<Expression> exp;
	
public:
	AssigmentStatement(std::string varible, std::shared_ptr<Expression> exp);
	AssigmentStatement();
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	virtual ~AssigmentStatement();
};

