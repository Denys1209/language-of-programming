#pragma once
#include "System_const.h"
#include "Token_types.h"
#include <string>
#include <exception>
#include <vector>

class Value 
{
public:
	int		virtual asInt()	const		{ return 0; };
	float	virtual asFloat()const { return 0; };
	double	virtual asDouble()const { return 0; };
	bool	virtual asBool()const { return 0; };
	virtual std::vector<std::shared_ptr<Value>>  asList() const{
		std::vector<std::shared_ptr<Value>> return_value = {};
		return return_value;
	}

	std::string	virtual asString()const { return ""; };
	Token_type virtual getType()const { return Token_type::TYPE; }
	bool virtual is_string()const { return false; }
	virtual std::shared_ptr<Value> operator_equal(const std::shared_ptr<Value> &value){

		return nullptr;
	}
	virtual bool operator_not_equal(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_two_equal(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_more(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_more_or_equal(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_less_or_equal(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_less(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual bool operator_or(const std::shared_ptr<Value> &value)  {

		return false;
	}
	virtual bool operator_two_and(const std::shared_ptr<Value> &value) {

		return false;
	}
	virtual std::shared_ptr<Value> operator_plus(const std::shared_ptr<Value> &value) {

		return nullptr;
	}
	virtual std::shared_ptr<Value> operator_minus(const std::shared_ptr<Value> &value) {

		return nullptr;
	}
	virtual std::shared_ptr<Value> operator_multiply(const std::shared_ptr<Value> &value ) 
	{
		return nullptr;
	}
	virtual std::shared_ptr<Value> operator_share(const std::shared_ptr<Value> &value)
	{
		return nullptr;
	}
	virtual std::shared_ptr<Value> getElementIndex(int index) 
	{
		return nullptr;
	}

	virtual void setElementIndex(int index, const std::shared_ptr<Value>&ele)
	{
		
	}
	virtual void push_back(std::shared_ptr<Value>&ele)
	{
		
	}
	virtual std::shared_ptr<Value> operator_point(std::string name)
	{
		return nullptr;
	}
	virtual int getSize()
	{
		return 0;
	}
	virtual ~Value() = default;
};
using value_ptr = std::shared_ptr<Value>;

