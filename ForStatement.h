#pragma once
#include "Statement.h"
class ForStatement :
	public Statement
{
private:
	

	std::shared_ptr<Statement> initialization;
	std::shared_ptr<Expression> termination;
	std::shared_ptr<Statement> increment;
	std::shared_ptr<Statement> block;
public:
	ForStatement(std::shared_ptr<Statement> stinitializationatement, std::shared_ptr<Expression> termination, std::shared_ptr<Statement> increment, std::shared_ptr<Statement> block);
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	virtual ~ForStatement();
};

