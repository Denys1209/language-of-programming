#include "ReferenceValue.h"

ReferenceValue::ReferenceValue()
{
	this->value = nullptr;
}
ReferenceValue::ReferenceValue(std::shared_ptr<Value> value)
{
	this->value = value;
}
int ReferenceValue::asInt() const 
{
	return (*this->value).asInt();
}
double ReferenceValue::asDouble()const 
{
	return (*this->value).asDouble();
}
float ReferenceValue::asFloat()const 
{
	return (*this->value).asFloat();
}
bool ReferenceValue::asBool()const 
{
	return (*this->value).asBool();
}
Token_type ReferenceValue::getType()const  { return (*this->value).getType(); }
value_ptr ReferenceValue::operator_equal(const value_ptr &value) {
	(*this->value).operator_equal(value);
	return std::make_shared<ReferenceValue>(this->value);
}
bool ReferenceValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	if (this->value != value) return true;
	return false;
}
bool ReferenceValue::operator_two_equal(const value_ptr &value)  {

	return (*this->value).operator_two_equal(value);
}
bool ReferenceValue::operator_more(const value_ptr &value)  {

	return (*this->value).operator_more(value);
}
bool ReferenceValue::operator_more_or_equal(const value_ptr &value)  {

	return (*this->value).operator_more_or_equal(value);
}
bool ReferenceValue::operator_less_or_equal(const value_ptr &value) {

	return (*this->value).operator_less_or_equal(value);
}
bool ReferenceValue::operator_less(const value_ptr &value)  {

	return (*this->value).operator_less(value);
}
value_ptr ReferenceValue::operator_plus(const value_ptr &value)  {

	return (*this->value).operator_plus(value);
}
value_ptr ReferenceValue::operator_minus(const value_ptr &value)  {
	return (*this->value).operator_minus(value);
}
std::shared_ptr<Value> ReferenceValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	return (*this->value).operator_multiply(value);
}
std::shared_ptr<Value> ReferenceValue::operator_share(const std::shared_ptr<Value> &value)
{
	return (*this->value).operator_share(value);
}
std::string ReferenceValue::asString()const 
{
	return (*this->value).asString();
}
value_ptr ReferenceValue::getElementIndex(int index) 
{
	return (*this->value).getElementIndex(index);
}
std::shared_ptr<Value> ReferenceValue::operator_point(std::string name) 
{
	return (*this->value).operator_point(name);
}
void ReferenceValue::setElementIndex(int index, const value_ptr&ele) 
{
	(*this->value).setElementIndex(index, ele);
}
void ReferenceValue::push_back(value_ptr&ele) 
{
	(*this->value).push_back(ele);
}
int ReferenceValue::getSize() 
{
	return (*this->value).getSize();
}
bool ReferenceValue::is_string()const  { return (*this->value).is_string(); }
