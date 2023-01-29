#pragma once
#include "Statement.h"
class StructDefineStatement :
	public Statement
{
private:
	std::string name;
	std::list<Token> list_values;
	std::vector<std::string> list_names;
public:
	StructDefineStatement(std::string name, std::list<Token> list_values, std::vector<std::string> list_names);
	void execute(List_variables &main_veriables_list) override;
};

