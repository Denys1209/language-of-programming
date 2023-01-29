#include "constantExpression.h"
constantExpression::constantExpression(std::string name)
{
	this->name = name;
}
value_ptr constantExpression::eval(List_variables &main_veriables_list) 
{

	value_ptr vl = main_veriables_list.get_value(name);
	if ((*vl).getType() == Token_type::INT) { return std::static_pointer_cast<IntValue>(vl); }
	else if ((*vl).getType() == Token_type::FLOAT) { return std::static_pointer_cast<FloatValue>(vl); }
	else if ((*vl).getType() == Token_type::DOUBLE) { return std::static_pointer_cast<DoubleValue>(vl); }
	else if ((*vl).getType() == Token_type::STRING) { return std::static_pointer_cast<StringValue>(vl); }
	else if ((*vl).getType() == Token_type::BOOL) { return std::static_pointer_cast<BoolValue>(vl); }
	else if ((*vl).getType() == Token_type::LIST) { return std::static_pointer_cast<ListValue>(vl); }
	else if ((*vl).getType() == Token_type::STRUCT) { return std::static_pointer_cast<StructValue>(vl); }


}
std::string constantExpression::get_str()
{

	return this->name;
}