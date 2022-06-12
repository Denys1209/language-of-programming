#pragma once
#include "Value.h"
class ReferenceValue :
	public Value
{
private:
	std::shared_ptr<Value> value;
public:
	ReferenceValue()
	{
		this->value = nullptr;
	}
	ReferenceValue(std::shared_ptr<Value> value)
	{
		this->value = value;
	}
	int asInt() const override
	{
		return (*this->value).asInt();
	}
	double asDouble()const override
	{
		return (*this->value).asDouble();
	}
	float asFloat()const override
	{
		return (*this->value).asFloat();
	}
	bool asBool()const override
	{
		return (*this->value).asBool();
	}
	Token_type getType()const override { return (*this->value).getType(); }
	value_ptr operator_equal(const value_ptr &value)override {
		(*this->value).operator_equal(value);
		return std::make_shared<ReferenceValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != value) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return (*this->value).operator_two_equal(value);
	}
	bool operator_more(const value_ptr &value) override {

		return (*this->value).operator_more(value);
	}
	bool operator_more_or_equal(const value_ptr &value) override {

		return (*this->value).operator_more_or_equal(value);
	}
	bool operator_less_or_equal(const value_ptr &value)override {

		return (*this->value).operator_less_or_equal(value);
	}
	bool operator_less(const value_ptr &value) override {

		return (*this->value).operator_less(value);
	}
	value_ptr operator_plus(const value_ptr &value) override {

		return (*this->value).operator_plus(value);
	}
	value_ptr operator_minus(const value_ptr &value) override {
		return (*this->value).operator_minus(value);
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		return (*this->value).operator_multiply(value);
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		return (*this->value).operator_share(value);
	}
	std::string asString()const override
	{
		return (*this->value).asString();
	}
	value_ptr getElementIndex(int index) override
	{
		return (*this->value).getElementIndex(index);
	}
	void setElementIndex(int index, const value_ptr&ele) override
	{
		(*this->value).setElementIndex(index,ele);
	}
	void push_back(value_ptr&ele) override
	{
		(*this->value).push_back(ele);
	}
	int getSize() override
	{
		return (*this->value).getSize();
	}
	bool is_string()const override { return (*this->value).is_string(); }


};

