#pragma once
#include "Statement.h"
#include "UserDefinedFunction.h"
#include <list>
class FunctionDefineStatement :
	public Statement
{
private:
	std::string name;
	std::vector<std::string> list_arguments;
	std::shared_ptr<Statement> body;
	std::shared_ptr<List_variables> main_list_veriables;
	std::vector<bool> bool_amp;
public:
	FunctionDefineStatement(std::string name, std::vector<std::string> list_arguments, std::shared_ptr<Statement> body, std::shared_ptr<List_variables> main_list_veriables, std::vector<bool> bool_amp);
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	~FunctionDefineStatement();
};

