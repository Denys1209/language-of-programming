#include "PointAssigmentStatement.h"
PointAssigmentStatement::PointAssigmentStatement(std::shared_ptr<Expression> exp1, std::shared_ptr<Expression> exp2)
{
	this->exp1 = std::move(exp1);
	this->exp2 = std::move(exp2);
}
void PointAssigmentStatement::execute(List_variables &main_veriables_list) 
{
	std::shared_ptr<Value> val = (*exp1).eval(main_veriables_list);
	(*val).operator_equal((*exp2).eval(main_veriables_list));
};