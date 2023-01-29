#pragma once
#include "Statement.h"
class InputStatement :
	public Statement
{
private:
	std::string name;
public:
	InputStatement(std::string name);
	void execute(List_variables &main_veriables_list);
	virtual std::string get_str();
};

