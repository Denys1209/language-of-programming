#include "ListExpressionDeclaration.h"


ListExpressionDeclaration::ListExpressionDeclaration(std::shared_ptr<Expression> val)
{
	this->val = val;
}
value_ptr ListExpressionDeclaration::eval(List_variables &main_veriables_list)
{

	return std::make_shared<ListValue>((*(*val).eval(main_veriables_list)).asInt());
}