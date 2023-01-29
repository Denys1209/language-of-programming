#include "FunctionStatement.h"
FunctionStatement::FunctionStatement(std::shared_ptr<Expression> exp)
{
	this->exp = std::move(exp);
};
FunctionStatement::FunctionStatement() = default;
void FunctionStatement::execute(List_variables &main_veriables_list) 
{
	(*exp).eval(main_veriables_list);
};
std::string FunctionStatement::get_str()  { return ""; };
FunctionStatement::~FunctionStatement() {};