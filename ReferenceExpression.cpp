#include "ReferenceExpression.h"
ReferenceExpression::ReferenceExpression(std::string name_value)
{
	this->name_value = name_value;
}
value_ptr ReferenceExpression::eval(List_variables &main_veriables_list) 
{

	return std::make_shared<ReferenceValue>(main_veriables_list.get_value(this->name_value));
};
ReferenceExpression::~ReferenceExpression() = default;