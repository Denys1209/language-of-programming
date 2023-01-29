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
	
	StructValue(std::map<std::string, value_ptr> val);
	StructValue();
	std::map<std::string, value_ptr> &getVal();
	std::shared_ptr<Value> operator_point(std::string name) override;
	Token_type getType() const override;
};

