#include "BoolValue.h"
BoolValue::BoolValue()
{
	this->value = false;
}
BoolValue::BoolValue(bool value)
{
	this->value = value;
}
BoolValue::BoolValue(std::string value)
{
	if (value == "")
	{
		this->value = false;
	}
	else {
		this->value = true;
	}
}
int BoolValue::asInt()const 
{
	return this->value;
}
double BoolValue::asDouble()const 
{
	return this->value;
}
float BoolValue::asFloat()const 
{
	return this->value;
}
bool BoolValue::asBool()const 
{
	return this->value;
}
value_ptr BoolValue::operator_equal(const value_ptr &value) {
	this->value = (*value).asBool();
	return std::make_shared<BoolValue>(this->value);
}
bool BoolValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	if (this->value != (*value).asBool()) return true;
	return false;
}
bool BoolValue::operator_two_equal(const value_ptr &value)  {

	return this->value == (*value).asBool();
}
bool BoolValue::operator_more(const value_ptr &value)  {
	throw std::exception("Bool doesn't have operator >");
	return this->value > (*value).asBool();
}
bool BoolValue::operator_more_or_equal(const value_ptr &value)  {
	throw std::exception("Bool doesn't have operator >=");
	return this->value >= (*value).asBool();
}
bool BoolValue::operator_less_or_equal(const value_ptr &value) {
	throw std::exception("Bool doesn't have operator <=");
	return this->value <= (*value).asBool();
}
bool BoolValue::operator_less(const value_ptr &value)  {
	throw std::exception("Bool doesn't have operator <");
	return this->value < (*value).asBool();
}
bool BoolValue::operator_or(const std::shared_ptr<Value> &value)  {

	return this->value || (*value).asBool();
}
bool BoolValue::operator_two_and(const std::shared_ptr<Value> &value)  {

	return this->value && (*value).asBool();
}
value_ptr BoolValue::operator_plus(const value_ptr &value)  {
	return std::make_shared<BoolValue>(this->value + (*value).asBool());
}
value_ptr BoolValue::operator_minus(const value_ptr &value)  {
	return std::make_shared<BoolValue>(this->value - (*value).asBool());
}
std::shared_ptr<Value> BoolValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	throw std::exception("Bool doesn't have operator *");
	return nullptr;
}
std::shared_ptr<Value> BoolValue::operator_share(const std::shared_ptr<Value> &value)
{
	throw std::exception("Bool doesn't have operator /");
	return nullptr;
}
Token_type BoolValue::getType()const { return Token_type::BOOL; }
std::string BoolValue::asString()const {
	if (this->value) {
		return "true";
	}
	else
	{
		return "false";
	}
}
bool BoolValue::is_string()const { return false; }