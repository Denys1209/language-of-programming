#pragma once
#include "Value.h"
class StringValue :
	public Value,
	public std::enable_shared_from_this<StringValue>
{
private:
	std::string value;
public:
	StringValue();
	StringValue(std::string value);
	int asInt()const override;
	float asFloat()const override;
	double asDouble()const override;
	bool asBool()const override;
	value_ptr operator_equal(const value_ptr &value)override;
	std::shared_ptr<Value> getElementIndex(int index) override;
	void setElementIndex(int index, const value_ptr&ele)override;
	void push_back(value_ptr&ele)override;
	int getSize() override;
	bool operator_not_equal(const std::shared_ptr<Value> &value) override;
	value_ptr operator_minus(const value_ptr &value) override;
	bool operator_two_equal(const value_ptr &value) override;
	bool operator_more(const value_ptr &value) override;
	bool operator_more_or_equal(const value_ptr &value) override;
	bool operator_less_or_equal(const value_ptr &value)override;
	bool operator_less(const value_ptr &value) override;
	value_ptr operator_plus(const value_ptr &value) override;
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override;
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value);
	Token_type getType()const override;
	std::string asString()const override;
	bool is_string()const override;
};

