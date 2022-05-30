#pragma once
#include "Value.h"
class DoubleValue :
	public Value, 
	std::enable_shared_from_this<DoubleValue>
{
private:
	double value;
public:
	DoubleValue()
	{
		this->value = 0;
	}
	DoubleValue(double value)
	{
		this->value = value;
	}
	int asInt()const override
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
	value_ptr operator_equal(const value_ptr &value)override {
		this->value = (*value).asDouble();
		return std::make_shared<DoubleValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != (*value).asDouble()) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return this->value == (*value).asDouble();
	}
	bool operator_more(const value_ptr &value) override {

		return this->value > (*value).asDouble();
	}
	bool operator_more_or_equal(const value_ptr &value) override {

		return this->value >= (*value).asDouble();
	}
	bool operator_less_or_equal(const value_ptr &value)override {

		return this->value <= (*value).asDouble();
	}
	bool operator_less(const value_ptr &value) override {

		return this->value < (*value).asDouble();
	}
	value_ptr operator_plus(const value_ptr &value) override {
		return std::make_shared<DoubleValue>(this->value + (*value).asDouble());
	}
	value_ptr operator_minus(const value_ptr &value) override {
		return std::make_shared<DoubleValue>(this->value - (*value).asDouble());
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		return std::make_shared<DoubleValue>(this->value * (*value).asDouble());
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		return std::make_shared<DoubleValue>(this->value / (*value).asDouble());
	}
	Token_type getType()const override { return Token_type::DOUBLE; }
	std::string asString()const override
	{
		return std::to_string(this->value);
	}
	bool is_string()const override { return false; }
};

