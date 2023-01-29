#include "PrintStatement.h"

PrintStatement::PrintStatement(std::shared_ptr<Expression> exp)
{
	this->exp = std::move(exp);
}
void PrintStatement::execute(List_variables &main_veriables_list)
{
	std::cout << (*(*this->exp).eval(main_veriables_list)).asString();
}
std::string PrintStatement::get_str()
{
	return "print " + (*this->exp).get_str();
}