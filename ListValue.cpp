#include "ListValue.h"

ListValue::ListValue() = default;


ListValue::ListValue(const std::vector<value_ptr> &list)
{
	this->list = list;
}

ListValue::ListValue(int size)
{
	this->list.resize(size);
}

ListValue::ListValue(const ListValue &CopyList)
{
	this->list.resize(CopyList.list.size());
	for (const auto& temp : CopyList.list)
	{
		this->list.push_back(temp);
	}

}
value_ptr ListValue::getElementIndex(int index) 
{
	return this->list[index];
}
void ListValue::setElementIndex(int index, const value_ptr&ele) 
{
	(*this->list[index]).operator_equal(ele);
}
void ListValue::push_back(value_ptr&ele) 
{
	this->list.push_back(ele);
}
int ListValue::getSize() {
	return this->list.size();
}
Token_type ListValue::getType() const 
{
	return Token_type::LIST;
}
int ListValue::asInt()const 
{
	throw std::exception("List can't convert to int");
}
float ListValue::asFloat()const 
{
	throw std::exception("List can't convert to float");
}
double ListValue::asDouble()const 
{
	throw std::exception("List can't convert to double");
}
std::vector<value_ptr> ListValue::asList()const
{
	return this->list;
}
bool ListValue::asBool()const  { throw std::exception("List can't convert to bool"); }
value_ptr ListValue::operator_equal(const value_ptr &value) {
	this->list = (*value).asList();
	return std::make_shared<ListValue>(this->list);
}
bool ListValue::operator_not_equal(const std::shared_ptr<Value> &value)  {
	throw std::exception("List doesn't have operator !=");
	return false;
}
bool ListValue::operator_two_equal(const value_ptr &value)  {
	throw std::exception("List doesn't have operator ==");
	return 0;
}
bool ListValue::operator_more(const value_ptr &value)  {
	throw std::exception("List doesn't have operator >");
	return 0;
}
bool ListValue::operator_more_or_equal(const value_ptr &value)  {
	throw std::exception("List doesn't have operator >=");
	return 0;
}
bool ListValue::operator_less_or_equal(const value_ptr &value) {
	throw std::exception("List doesn't have operator <=");
	return 0;
}
bool ListValue::operator_less(const value_ptr &value)  {
	throw std::exception("List doesn't have operator <");
	return 0;
}
value_ptr ListValue::operator_plus(const value_ptr &value)  {
	throw std::exception("List doesn't have operator +");
	return nullptr;
}
value_ptr ListValue::operator_minus(const value_ptr &value)  {
	throw std::exception("List doesn't have operator -");
	return nullptr;
}
std::shared_ptr<Value> ListValue::operator_multiply(const std::shared_ptr<Value> &value) 
{
	throw std::exception("List doesn't have operator *");
	return nullptr;
}
std::shared_ptr<Value> ListValue::operator_share(const std::shared_ptr<Value> &value)
{
	throw std::exception("List doesn't have operator /");
	return nullptr;
}
std::string ListValue::asString() const 
{
	std::string buf = "{";
	for (const auto &i : this->list)
	{
		buf += (*i).asString() + ", ";
	}
	buf += "}";
	return buf;
}