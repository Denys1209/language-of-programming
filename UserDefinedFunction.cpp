#include "UserDefinedFunction.h"
UserDefinedFunction::UserDefinedFunction(std::vector<std::string> argsNames, std::shared_ptr<Statement> body, std::shared_ptr<List_variables> main_list_variables, std::vector<bool> bool_amp)
{
	this->argsNames = std::move(argsNames);
	this->body = body;
	this->main_list_variables = main_list_variables;
	this->bool_amp = std::move(bool_amp);
}

int UserDefinedFunction::getAtgsCount()  { return this->argsNames.size(); }

std::string UserDefinedFunction::getArgsName(int index)  
{
	return this->argsNames.at(index);
}
bool UserDefinedFunction::is_user_function() { return true; }
std::vector<bool> UserDefinedFunction::amp_bool()
{
	return this->bool_amp;
}
value_ptr UserDefinedFunction::exute(std::vector<value_ptr> arg)
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
UserDefinedFunction::~UserDefinedFunction() {}