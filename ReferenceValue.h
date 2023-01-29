#pragma once
#include "Value.h"
class ReferenceValue :
	public Value
{
private:
	std::shared_ptr<Value> value;
public:
	ReferenceValue();
	ReferenceValue(std::shared_ptr<Value> value);
	int asInt() const override;
	double asDouble()const override;
	float asFloat()const override;
	bool asBool()const override;
	Token_type getType()const override;
	value_ptr operator_equal(const value_ptr &value)override;
	bool operator_not_equal(const std::shared_ptr<Value> &value) override;
	bool operator_two_equal(const value_ptr &value) override;
	bool operator_more(const value_ptr &value) override;
	bool operator_more_or_equal(const value_ptr &value)override;
	bool operator_less_or_equal(const value_ptr &value)override;
	bool operator_less(const value_ptr &value) override;
	value_ptr operator_plus(const value_ptr &value) override;
	
	value_ptr operator_minus(const value_ptr &value) override;
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override;
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value);
	std::string asString()const override;
	value_ptr getElementIndex(int index) override;
	std::shared_ptr<Value> operator_point(std::string name) override;
	 void setElementIndex(int index, const value_ptr&ele) override;
	void push_back(value_ptr&ele) override;
	int getSize() override;
	bool is_string()const override;


};

