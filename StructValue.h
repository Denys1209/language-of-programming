#pragma once
#include "Value.h"
#include "Token.h"
#include <map>
class StructValue :
	public Value
{
private:
	std::map<std::string, value_ptr> val;
public:
	StructValue(std::map<std::string, value_ptr> val)
	{
		this->val = std::move(val);
	}
	std::shared_ptr<Value> operator_point(std::string name) override
	{
		return this->val[name];
	}
};

