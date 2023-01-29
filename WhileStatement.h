#pragma once
#include "Statement.h"
#include "Expression.h"
class WhileStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> condition;
	std::shared_ptr<Statement> statement;
public:
	WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> statement);
	void execute(List_variables &main_veriables_list)override;
	std::string get_str() override;
	~WhileStatement();
};

