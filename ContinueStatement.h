#pragma once
#include "Statement.h"
class ContinueStatement :
	public Statement
{
private:
public:
	ContinueStatement() = default;
	void execute(List_variables &main_veriables_list)override
	{
		throw CONTINUE_TEXT;
	};
	std::string get_str() override { return ""; };
	~ContinueStatement() {};
};

