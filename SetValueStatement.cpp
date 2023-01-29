#include "SetValueStatement.h"

SetValueStatement::SetValueStatement(std::string varible, std::shared_ptr<Expression> exp)
{
	this->varible = varible;
	this->exp = std::move(exp);

}
SetValueStatement::SetValueStatement() = default;
void SetValueStatement::execute(List_variables &main_veriables_list) 
{
	value_ptr result = (*exp).eval(main_veriables_list);
	main_veriables_list.set(this->varible, std::move(result));
}
std::string  SetValueStatement::get_str() 
{
	std::string r = varible + " = " + (*exp).get_str();
	return r;
}