#pragma once
#include "Statement.h"
class ContinueStatement :
	public Statement
{
private:
public:
	ContinueStatement();
	void execute(List_variables &main_veriables_list)override;
	std::string get_str() override;
	~ContinueStatement();
};

