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
	std::unique_ptr<Statement> body;
	std::vector<Token> args_types_names;
	std::shared_ptr<List_variables> main_list_veriables;
public:
	FunctionDefineStatement(std::string name, std::vector<std::string> list_arguments, std::unique_ptr<Statement> body, std::shared_ptr<List_variables> main_list_veriables, std::vector<Token> args_types_names)
	{
		this->name = std::move(name);
		this->list_arguments = std::move(list_arguments);
		this->body = std::move(body);
		this->main_list_veriables = main_list_veriables;
		this->args_types_names = std::move(args_types_names);
	}
	void execute(List_variables &main_veriables_list) override { main_veriables_list.creat_function(this->name, std::move(std::make_unique<UserDefinedFunction>(std::move(this->list_arguments),std::move(this->body), this->main_list_veriables, std::move(this->args_types_names) ) )); };
	std::string get_str() override { return ""; };
	~FunctionDefineStatement() {};
};

