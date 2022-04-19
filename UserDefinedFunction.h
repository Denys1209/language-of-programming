#pragma once
#include "Function.h"
#include "Statement.h"
#include "List_variables.h"

#include <list>
#include <string>
class UserDefinedFunction :
	public Function
{
private:
	std::vector<std::string> argsNames;
	std::unique_ptr<Statement> body;
	std::shared_ptr<List_variables> main_list_variables = nullptr;
	std::vector<Token> args_types_names;
public:
	UserDefinedFunction(std::vector<std::string> argsNames, std::unique_ptr<Statement> body, std::shared_ptr<List_variables> main_list_variables, std::vector<Token> args_types_names)
	{
		this->argsNames = std::move(argsNames);
		this->body = std::move(body);
	    this->main_list_variables = main_list_variables;
		this->args_types_names = std::move(args_types_names);
	}

	int getAtgsCount() override { return this->argsNames.size(); }

	std::string getArgsName(int index)  override
	{
		return this->argsNames.at(index);
	}
	//Token get_type(int i) override { return this->args_types_names[i]; };
	bool is_user_function()override { return true; };

	value_ptr exute(std::vector<value_ptr> arg) override
	{
		 (*this->body).execute(*main_list_variables);
		 return nullptr;
	}
	~UserDefinedFunction() {};

};

