#pragma once
#include "Statement.h"
class DoWhileStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> condition;
	std::shared_ptr<Statement> statement;
public:
	DoWhileStatement(std::shared_ptr<Statement> statement, std::shared_ptr<Expression> condition);
	void execute(List_variables &main_veriables_list)override;
	std::string get_str() override;
	~DoWhileStatement();
};

