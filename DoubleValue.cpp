#include "DoubleValue.h"
DoubleValue::DoubleValue()
{
	this->value = 0;
}
DoubleValue::DoubleValue(double value)
{
	this->value = value;
}
int DoubleValue::asInt()const 
{
	return this->value;
}
double DoubleValue::asDouble()const 
{
	return this->value;
}
float DoubleValue::asFloat()const 
{
	return this->value;
}
bool DoubleValue::asBool()const 
{
	return this->value;
}
value_ptr DoubleValue::operator_equal(const value_ptr &value) {
	this->value = (*value).asDouble();
	return std::make_shared<DoubleValue>(this->value);
}
bool DoubleValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	if (this->value != (*value).asDouble()) return true;
	return false;
}
bool DoubleValue::operator_two_equal(const value_ptr &value)  {

	return this->value == (*value).asDouble();
}
bool DoubleValue::operator_more(const value_ptr &value)  {

	return this->value > (*value).asDouble();
}
bool DoubleValue::operator_more_or_equal(const value_ptr &value)  {

	return this->value >= (*value).asDouble();
}
bool DoubleValue::operator_less_or_equal(const value_ptr &value) {

	return this->value <= (*value).asDouble();
}
bool DoubleValue::operator_less(const value_ptr &value)  {

	return this->value < (*value).asDouble();
}
value_ptr DoubleValue::operator_plus(const value_ptr &value)  {
	return std::make_shared<DoubleValue>(this->value + (*value).asDouble());
}
value_ptr DoubleValue::operator_minus(const value_ptr &value)  {
	return std::make_shared<DoubleValue>(this->value - (*value).asDouble());
}
std::shared_ptr<Value> DoubleValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	return std::make_shared<DoubleValue>(this->value * (*value).asDouble());
}
std::shared_ptr<Value> DoubleValue::operator_share(const std::shared_ptr<Value> &value)
{
	return std::make_shared<DoubleValue>(this->value / (*value).asDouble());
}
Token_type DoubleValue::getType()const  { return Token_type::DOUBLE; }
std::string DoubleValue::asString()const 
{
	return std::to_string(this->value);
}
bool DoubleValue::is_string()const  { return false; }