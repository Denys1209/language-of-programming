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
	FunctionDefineStatement(std::string name, std::vector<std::string> list_arguments, std::shared_ptr<Statement> body, std::shared_ptr<List_variables> main_list_veriables, std::vector<bool> bool_amp)
	{
		this->name = std::move(name);
		this->list_arguments = list_arguments;
		this->body = body;
		this->main_list_veriables = main_list_veriables;
		this->bool_amp = std::move(bool_amp);
	}
	void execute(List_variables &main_veriables_list) override {
		main_veriables_list.creat_function(this->name,
			std::make_shared<UserDefinedFunction>(std::move(this->list_arguments), 
				this->body, this->main_list_veriables, this->bool_amp));

	}
	std::string get_str() override { return ""; }
	~FunctionDefineStatement() {}
};

