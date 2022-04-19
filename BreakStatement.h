#pragma once
#include "Statement.h"
class BreakStatement :
	public Statement
{
private:
public:
	BreakStatement() = default;
	void execute(List_variables &main_veriables_list)override
	{
		throw BREAK_TEXT;
	};
	std::string get_str() override { return ""; };
	~BreakStatement() {};
};

