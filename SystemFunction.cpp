#include "SystemFunction.h"
SystemFunction::SystemFunction(std::function<value_ptr(std::vector<value_ptr> arg)> f, int size)
{
	this->function = std::move(f);
	this->size = size;
}
SystemFunction::SystemFunction() = default;
bool SystemFunction::is_user_function() { return false; };
int SystemFunction::getAtgsCount()  { return this->size; }


value_ptr SystemFunction::exute(std::vector<value_ptr> arg) 
{
	if (arg.size() != size) throw std::exception(PASS_INCORRECT_NUMBER);
	return this->function(std::move(arg));
}