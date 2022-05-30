#pragma once
#include "Value.h"
class StringValue :
	public Value,
	public std::enable_shared_from_this<StringValue>
{
private:
	std::string value;
public:
	StringValue()
	{
		this->value = "";
	}
	StringValue(std::string value)
	{
		this->value = std::move(value);
	}
	int asInt()const override
	{
		
		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	float asFloat()const override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	double asDouble()const override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	bool asBool()const override
	{

		try {
			return std::stod(this->value);
		}
		catch (std::exception s)
		{
			return 0;
		}
	}
	value_ptr operator_equal(const value_ptr &value)override {
		this->value = (*value).asString();
		return std::make_shared<StringValue>(this->value);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		if (this->value != (*value).asString()) return true;
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {

		return this->value == (*value).asString();
	}
	bool operator_more(const value_ptr &value) override {
		throw std::exception("String doesn't have operator >");
		return 0;
	}
	bool operator_more_or_equal(const value_ptr &value) override {
		throw std::exception("String doesn't have operator >=");
		return this->value >= (*value).asString();
	}
	bool operator_less_or_equal(const value_ptr &value)override {
		throw std::exception("String doesn't have operator <=");
		return this->value <= (*value).asString();
	}
	bool operator_less(const value_ptr &value) override {
		throw std::exception("String doesn't have operator <");
		return this->value < (*value).asString();
	}
	value_ptr operator_plus(const value_ptr &value) override {
		return std::make_shared<StringValue>(this->value+(*value).asString());
	}
	value_ptr operator_minus(const value_ptr &value) override {
		throw std::exception("String doesn't have operator -");
		return this->shared_from_this();
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		std::string buf = "";
		for (int i =0; i< (*value).asInt(); ++i) 
		{
			buf += this->value;
		}
		return std::make_shared<StringValue>(buf);
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		throw std::exception("String doesn't have operator /");
		return nullptr;
	}
	Token_type getType()const override { return Token_type::STRING; }
	std::string asString()const override
	{
		return this->value;
	}
	bool is_string()const override { return true; }
};

