#pragma once
#include "Statement.h"
#include <vector>
class BlockStatement :
	public Statement
{
private:
	std::vector<std::shared_ptr<Statement>> lis;
public:
	BlockStatement();

	void add(std::shared_ptr<Statement> statement);
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	~BlockStatement();
};

