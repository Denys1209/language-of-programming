#pragma once
#include "Statement.h"
class BreakStatement :
	public Statement
{
private:
public:
	BreakStatement();
	void execute(List_variables &main_veriables_list)override;
	std::string get_str() override;
	~BreakStatement();
};

