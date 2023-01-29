#include "StringValue.h"

StringValue::StringValue()
{
	this->value = "";
}
StringValue::StringValue(std::string value)
{
	this->value = std::move(value);
}
int StringValue::asInt()const 
{

	try {
		return std::stod(this->value);
	}
	catch (std::exception s)
	{
		return 0;
	}
}
float StringValue::asFloat()const 
{

	try {
		return std::stod(this->value);
	}
	catch (std::exception s)
	{
		return 0;
	}
}
double StringValue::asDouble()const
{

	try {
		return std::stod(this->value);
	}
	catch (std::exception s)
	{
		return 0;
	}
}
bool StringValue::asBool()const 
{

	try {
		return std::stod(this->value);
	}
	catch (std::exception s)
	{
		return 0;
	}
}
value_ptr StringValue::operator_equal(const value_ptr &value) {
	this->value = (*value).asString();
	return std::make_shared<StringValue>(this->value);
}
std::shared_ptr<Value> StringValue::getElementIndex(int index)
{
	return nullptr;
}
void StringValue::setElementIndex(int index, const value_ptr&ele)
{

	this->value[index] = (*(*ele).asString().c_str());
}
void StringValue::push_back(value_ptr&ele)
{
	this->value.push_back((*(*ele).asString().c_str()));
}
int StringValue::getSize() 
{
	return this->value.size();
}
bool StringValue::operator_not_equal(const std::shared_ptr<Value> &value)
{
	if (this->value != (*value).asString()) return true;
	return false;
}
bool StringValue::operator_two_equal(const value_ptr &value)
{

	return this->value == (*value).asString();
}
bool StringValue::operator_more(const value_ptr &value)
{
	throw std::exception("String doesn't have operator >");
	return 0;
}
bool StringValue::operator_more_or_equal(const value_ptr &value)
{
	throw std::exception("String doesn't have operator >=");
	return this->value >= (*value).asString();
}
bool StringValue::operator_less_or_equal(const value_ptr &value)
{
	throw std::exception("String doesn't have operator <=");
	return this->value <= (*value).asString();
}
bool StringValue::operator_less(const value_ptr &value)
{
	throw std::exception("String doesn't have operator <");
	return this->value < (*value).asString();
}
value_ptr StringValue::operator_plus(const value_ptr &value)
{
	return std::make_shared<StringValue>(this->value + (*value).asString());
}
value_ptr StringValue::operator_minus(const value_ptr &value) 
{
	throw std::exception("String doesn't have operator -");
	return this->shared_from_this();
}
std::shared_ptr<Value> StringValue::operator_multiply(const std::shared_ptr<Value> &value)
{
	std::string buf = "";
	for (int i = 0; i < (*value).asInt(); ++i)
	{
		buf += this->value;
	}
	return std::make_shared<StringValue>(buf);
}
std::shared_ptr<Value> StringValue::operator_share(const std::shared_ptr<Value> &value)
{
	throw std::exception("String doesn't have operator /");
	return nullptr;
}
Token_type StringValue::getType()const  { return Token_type::STRING; }
std::string StringValue::asString()const
{
	return this->value;
}
bool StringValue::is_string()const  { return true; }