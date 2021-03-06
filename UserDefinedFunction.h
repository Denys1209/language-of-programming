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
	UserDefinedFunction(std::vector<std::string> argsNames, std::shared_ptr<Statement> body, std::shared_ptr<List_variables> main_list_variables, std::vector<bool> bool_amp)
	{
		this->argsNames = std::move(argsNames);
		this->body = body;
	    this->main_list_variables = main_list_variables;
		this->bool_amp = std::move(bool_amp);
	}

	int getAtgsCount() override { return this->argsNames.size(); }

	std::string getArgsName(int index)  override
	{
		return this->argsNames.at(index);
	}
	bool is_user_function()override { return true; }
	std::vector<bool> amp_bool() 
	{
		return this->bool_amp;
	}
	value_ptr exute(std::vector<value_ptr> arg) override
	{
		try {
			(*this->body).execute(*main_list_variables);
		}
		catch (std::shared_ptr<ReturnStatement> rw)
		{
			return (*rw).get_result();
		}
		catch (std::exception rw)
		{
			throw rw;
		}
		return nullptr;
	}
	~UserDefinedFunction() {}

};

