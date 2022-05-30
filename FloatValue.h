#pragma once
#include "Value.h"
class FloatValue :
	public Value,
	public std::enable_shared_from_this<FloatValue>
{
private:
	float value;
public:
	FloatValue()
	{
		this->value = 0;
	}
	FloatValue(float value)
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
		this->value = (*value).asFloat();
		return std::make_shared<FloatValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != (*value).asFloat()) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return this->value == (*value).asFloat();
	}
	bool operator_more(const value_ptr &value) override {

		return this->value > (*value).asFloat();
	}
	bool operator_more_or_equal(const value_ptr &value) override {

		return this->value >= (*value).asFloat();
	}
	bool operator_less_or_equal(const value_ptr &value)override {

		return this->value <= (*value).asFloat();
	}
	bool operator_less(const value_ptr &value) override {

		return this->value < (*value).asFloat();
	}
	value_ptr operator_plus(const value_ptr &value) override {
		return std::make_shared<FloatValue>(this->value + (*value).asFloat());
	}
	value_ptr operator_minus(const value_ptr &value) override {
		return std::make_shared<FloatValue>(this->value - (*value).asFloat());
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		return std::make_shared<FloatValue>(this->value * (*value).asFloat());
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		
		return std::make_shared<FloatValue>(this->value / (*value).asFloat());
	}
	Token_type getType()const override { return Token_type::FLOAT; }
	std::string asString()const override
	{
		return std::to_string(this->value);
	}
	bool is_string()const override { return false; }
};

