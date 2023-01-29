#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(std::shared_ptr<Expression> exp)
{
	this->exp = exp;
};
std::shared_ptr<Value> ReturnStatement::get_result() const {
	return this->result;
};
std::shared_ptr<Expression> ReturnStatement::get_expression() const {
	return this->exp;
};
void ReturnStatement::execute(List_variables &main_veriables_list) 
{
	result = (*exp).eval(main_veriables_list);
	throw this->shared_from_this();
};
std::string ReturnStatement::get_str()  { return "return "; };
ReturnStatement::~ReturnStatement()=default;