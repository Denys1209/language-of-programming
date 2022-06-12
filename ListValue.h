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
	ListValue() = default;

	ListValue(const std::vector<value_ptr> &list) 
	{
		this->list = list;
	}
	ListValue(int size)
	{
		this->list.resize(size);
	}
	ListValue(const ListValue &CopyList)
	{
		this->list.resize(CopyList.list.size());
		for (const auto& temp : CopyList.list) 
		{
			this->list.push_back(temp);
		}

	}
	value_ptr getElementIndex(int index) override
	{
		return this->list[index];
	}
	void setElementIndex(int index, const value_ptr&ele) override
	{
		(*this->list[index]).operator_equal(ele);
	}
	void push_back(value_ptr&ele) override
	{
		this->list.push_back(ele);
	}
	int getSize() override
	{
		return this->list.size();
	}
	Token_type getType() const override
	{
		return Token_type::LIST;
	}
	int asInt()const override
	{
		throw std::exception("List can't convert to int");
	}
	float asFloat()const override
	{
		throw std::exception("List can't convert to float");
	}
	double asDouble()const override
	{
		throw std::exception("List can't convert to double");
	}
	std::vector<value_ptr> asList()const override
	{
		return this->list;
	}
	bool asBool()const override{throw std::exception("List can't convert to bool");}
	value_ptr operator_equal(const value_ptr &value)override {
		this->list = (*value).asList();
		return std::make_shared<ListValue>(this->list);
	}
	bool operator_not_equal(const std::shared_ptr<Value> &value) override {
		throw std::exception("List doesn't have operator !=");
		return false;
	}
	bool operator_two_equal(const value_ptr &value) override {
		throw std::exception("List doesn't have operator ==");
		return 0;
	}
	bool operator_more(const value_ptr &value) override {
		throw std::exception("List doesn't have operator >");
		return 0;
	}
	bool operator_more_or_equal(const value_ptr &value) override {
		throw std::exception("List doesn't have operator >=");
		return 0;
	}
	bool operator_less_or_equal(const value_ptr &value)override {
		throw std::exception("List doesn't have operator <=");
		return 0;
	}
	bool operator_less(const value_ptr &value) override {
		throw std::exception("List doesn't have operator <");
		return 0;
	}
	value_ptr operator_plus(const value_ptr &value) override {
		throw std::exception("List doesn't have operator +");
		return nullptr;
	}
	value_ptr operator_minus(const value_ptr &value) override {
		throw std::exception("List doesn't have operator -");
		return nullptr;
	}
	std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value) override
	{
		throw std::exception("List doesn't have operator *");
		return nullptr;
	}
	std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		throw std::exception("List doesn't have operator /");
		return nullptr;
	}
	std::string asString() const override
	{
		std::string buf = "{";
		for (const auto &i : this->list) 
		{
			buf +=(*i).asString()+", ";
		}
		buf += "}";
		return buf;
	}

};

