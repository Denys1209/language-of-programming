#pragma once
#include "Function.h"
#include "Statement.h"
#include "ReturnStatement.h"
#include "List_variables.h"

#include <list>
#include <string>
class UserDefinedFunction :
	public Function
{
private:
	std::vector<std::string> argsNames;
	std::shared_ptr<Statement> body;
	std::shared_ptr<List_variables> main_list_variables = nullptr;
	std::vector<bool> bool_amp;
public:
	UserDefinedFunction(std::vector<std::string> argsNames, std::shared_ptr<Statement> body, std::shared_ptr<List_variables> main_list_variables, std::vector<bool> bool_amp);

	int getAtgsCount() override;

	std::string getArgsName(int index)  override;
	bool is_user_function()override;
	std::vector<bool> amp_bool();
	value_ptr exute(std::vector<value_ptr> arg) override;
	~UserDefinedFunction();
};

