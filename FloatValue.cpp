#include "FloatValue.h"


FloatValue::FloatValue()
{
	this->value = 0;
}
FloatValue::FloatValue(float value)
{
	this->value = value;
}
int FloatValue::asInt()const 
{
	return this->value;
}
double FloatValue::asDouble()const 
{
	return this->value;
}
float FloatValue::asFloat()const 
{
	return this->value;
}
bool FloatValue::asBool()const 
{
	return this->value;
}
value_ptr FloatValue::operator_equal(const value_ptr &value) {
	this->value = (*value).asFloat();
	return std::make_shared<FloatValue>(this->value);
}
bool FloatValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	if (this->value != (*value).asFloat()) return true;
	return false;
}
bool FloatValue::operator_two_equal(const value_ptr &value)  {

	return this->value == (*value).asFloat();
}
bool FloatValue::operator_more(const value_ptr &value)  {

	return this->value > (*value).asFloat();
}
bool FloatValue::operator_more_or_equal(const value_ptr &value)  {

	return this->value >= (*value).asFloat();
}
bool FloatValue::operator_less_or_equal(const value_ptr &value) {

	return this->value <= (*value).asFloat();
}
bool FloatValue::operator_less(const value_ptr &value)  {

	return this->value < (*value).asFloat();
}
value_ptr FloatValue::operator_plus(const value_ptr &value)  {
	return std::make_shared<FloatValue>(this->value + (*value).asFloat());
}
value_ptr FloatValue::operator_minus(const value_ptr &value)  {
	return std::make_shared<FloatValue>(this->value - (*value).asFloat());
}
std::shared_ptr<Value> FloatValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	return std::make_shared<FloatValue>(this->value * (*value).asFloat());
}
std::shared_ptr<Value> FloatValue::operator_share(const std::shared_ptr<Value> &value)
{

	return std::make_shared<FloatValue>(this->value / (*value).asFloat());
}
Token_type FloatValue::getType()const  { return Token_type::FLOAT; }
std::string FloatValue::asString()const 
{
	return std::to_string(this->value);
}
bool FloatValue::is_string()const  { return false; }