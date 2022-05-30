#pragma once
#include "Value.h"
class BoolValue :
	public Value,
	public std::enable_shared_from_this<BoolValue>
{
private:
	bool value;
public:

	BoolValue()
	{
		this->value = false;
	}
	BoolValue(bool value)
	{
		this->value = value;
	}
	BoolValue(std::string value)
	{
		if (value == "") 
		{
			this->value = false;
		}
		else {
			this->value = true;
		}
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
	value_ptr operator_equal(const value_ptr &value) {
		this->value = (*value).asBool();
		return std::make_shared<BoolValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != (*value).asBool()) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return this->value == (*value).asBool();
	}
	bool operator_more(const value_ptr &value) override {
		throw std::exception("Bool doesn't have operator >");
		return this->value > (*value).asBool();
	}
	bool operator_more_or_equal(const value_ptr &value) override {
		throw std::exception("Bool doesn't have operator >=");
		return this->value >= (*value).asBool();
	}
	bool operator_less_or_equal(const value_ptr &value)override {
		throw std::exception("Bool doesn't have operator <=");
		return this->value <= (*value).asBool();
	}
	bool operator_less(const value_ptr &value) override {
		throw std::exception("Bool doesn't have operator <");
		return this->value < (*value).asBool();
	}
	bool operator_or(const std::shared_ptr<Value> &value) override {

		return this->value || (*value).asBool();
	}
	bool operator_two_and(const std::shared_ptr<Value> &value) override {

		return this->value && (*value).asBool();
	}
	value_ptr operator_plus(const value_ptr &value) override {
		return std::make_shared<BoolValue>(this->value+(*value).asBool());
	}
	value_ptr operator_minus(const value_ptr &value) override {
		return std::make_shared<BoolValue>(this->value - (*value).asBool());
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		throw std::exception("Bool doesn't have operator *");
		return nullptr;
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		throw std::exception("Bool doesn't have operator /");
		return nullptr;
	}
	Token_type getType()const override { return Token_type::BOOL; }
	std::string asString()const override
	{
		if (this->value) {
			return "true";
		}
		else
		{
			return "false";
		}
	}
	bool is_string()const override { return false; }
};

