#pragma once
#include "Value.h"
#include <vector>
class ListValue :
	public Value,
	public std::enable_shared_from_this<ListValue>
{
private:
	std::vector<value_ptr> list;
public:
	ListValue();

	ListValue(const std::vector<value_ptr> &list);
	ListValue(int size);
	ListValue(const ListValue &CopyList);
	value_ptr getElementIndex(int index) override;
	void setElementIndex(int index, const value_ptr&ele) override;
	void push_back(value_ptr&ele) override;
	int getSize() override;
	Token_type getType() const override;
	int asInt()const override;
	float asFloat()const override;
	double asDouble()const override;
	std::vector<value_ptr> asList()const override;
	bool asBool()const override;
	value_ptr operator_equal(const value_ptr &value)override;
	bool operator_not_equal(const std::shared_ptr<Value> &value) override;
	bool operator_two_equal(const value_ptr &value) override;
	bool operator_more(const value_ptr &value) override;
	bool operator_more_or_equal(const value_ptr &value) override;
	bool operator_less_or_equal(const value_ptr &value)override;
	bool operator_less(const value_ptr &value) override;
	value_ptr operator_plus(const value_ptr &value) override;
	value_ptr operator_minus(const value_ptr &value) override;
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override;
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value);
	std::string asString() const override;

};

