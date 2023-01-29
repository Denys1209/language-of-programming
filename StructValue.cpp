#include "StructValue.h"

StructValue::StructValue(std::map<std::string, value_ptr> val)
{
	this->val = std::move(val);
}
StructValue::StructValue() = default;
std::map<std::string, value_ptr> &StructValue::getVal()
{
	return val;
}
std::shared_ptr<Value> StructValue::operator_point(std::string name) 
{
	return this->val[name];
}
Token_type StructValue::getType() const 
{
	return Token_type::STRUCT;
}