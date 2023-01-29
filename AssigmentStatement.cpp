#include "AssigmentStatement.h"

AssigmentStatement::AssigmentStatement(std::string varible, std::shared_ptr<Expression> exp)
{
	this->varible = varible;
	this->exp = std::move(exp);

}
AssigmentStatement::AssigmentStatement()
{

}
void AssigmentStatement::execute(List_variables &main_veriables_list) 
{
	value_ptr result = (*exp).eval(main_veriables_list);
	main_veriables_list.creat_value(this->varible, std::move(result));
}
std::string AssigmentStatement::get_str()
{
	std::string r = varible + " = " + (*exp).get_str();
	return r;
}
AssigmentStatement::~AssigmentStatement()
{

}