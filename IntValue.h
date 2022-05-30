#pragma once
#include "Value.h"

class IntValue :
	public Value,
	std::enable_shared_from_this<IntValue>
{
private:
	int value;
public:
	IntValue()
	{
		this->value = 0;
	}
	IntValue(int value)
	{
		this->value = value;
	}
	int asInt() const override
	{
		return this->value;
	}
	double asDouble()const override
	{
		return this->value;
	}
	float asFloat()const override
	{
		return this->value;
	}
	bool asBool()const override
	{
		return this->value;
	}
	Token_type getType()const override { return Token_type::INT; }
	value_ptr operator_equal(const value_ptr &value)override {
		this->value = (*value).asInt();
		return std::make_shared<IntValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != (*value).asInt()) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return this->value == (*value).asInt();
	}
	bool operator_more(const value_ptr &value) override {

		return this->value > (*value).asInt();
	}
	bool operator_more_or_equal(const value_ptr &value) override {

		return this->value >= (*value).asInt();
	}
	bool operator_less_or_equal(const value_ptr &value)override {

		return this->value <= (*value).asInt();
	}
	bool operator_less(const value_ptr &value) override {

		return this->value < (*value).asInt();
	}
	value_ptr operator_plus(const value_ptr &value) override {
		
		return std::make_shared<IntValue>(this->value+(*value).asInt());
	}
	value_ptr operator_minus(const value_ptr &value) override {
		return std::make_shared<IntValue>(this->value - (*value).asInt());
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		return std::make_shared<IntValue>(this->value * (*value).asInt());
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		return std::make_shared<IntValue>(this->value / (*value).asInt());
	}
	std::string asString()const override
	{
		return std::to_string(this->value);
	}
	bool is_string()const override { return false; }



};
