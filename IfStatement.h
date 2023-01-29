#pragma once
#include "Statement.h"
#include <list>
class IfStatement :
	public Statement
{
private:
	std::list<std::shared_ptr<Expression>> expressions;
	std::list<std::shared_ptr<Statement>> ifStatements;
	std::shared_ptr<Statement> elseStatement;
public:
	IfStatement();
	IfStatement(std::list<std::shared_ptr<Expression>> expressions, std::list<std::shared_ptr<Statement>> ifStatements, std::shared_ptr<Statement> elseStatement);
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override ;
	
};

