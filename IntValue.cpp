#include "IntValue.h"

IntValue::IntValue()
{
	this->value = 0;
}
IntValue::IntValue(int value)
{
	this->value = value;
}
int IntValue::asInt() const 
{
	return this->value;
}
double IntValue::asDouble()const 
{
	return this->value;
}
float IntValue::asFloat()const 
{
	return this->value;
}
bool IntValue::asBool()const 
{
	return this->value;
}
Token_type IntValue::getType()const  { return Token_type::INT; }
value_ptr IntValue::operator_equal(const value_ptr &value) {
	this->value = (*value).asInt();
	return std::make_shared<IntValue>(this->value);
}
bool IntValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	if (this->value != (*value).asInt()) return true;
	return false;
}
bool IntValue::operator_two_equal(const value_ptr &value)  {

	return this->value == (*value).asInt();
}
bool IntValue::operator_more(const value_ptr &value)  {

	return this->value > (*value).asInt();
}
bool IntValue::operator_more_or_equal(const value_ptr &value)  {

	return this->value >= (*value).asInt();
}
bool IntValue::operator_less_or_equal(const value_ptr &value) {

	return this->value <= (*value).asInt();
}
bool IntValue::operator_less(const value_ptr &value)  {

	return this->value < (*value).asInt();
}
value_ptr IntValue::operator_plus(const value_ptr &value)  {

	return std::make_shared<IntValue>(this->value + (*value).asInt());
}
value_ptr IntValue::operator_minus(const value_ptr &value)  {
	return std::make_shared<IntValue>(this->value - (*value).asInt());
}
std::shared_ptr<Value> IntValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	return std::make_shared<IntValue>(this->value * (*value).asInt());
}
std::shared_ptr<Value> IntValue::operator_share(const std::shared_ptr<Value> &value)
{
	return std::make_shared<IntValue>(this->value / (*value).asInt());
}
std::string IntValue::asString()const 
{
	return std::to_string(this->value);
}
bool IntValue::is_string()const  { return false; }