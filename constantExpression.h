#pragma once
#include "Expression.h"

class constantExpression :
	public Expression
{
private:
	std::string name;
	
public:
	constantExpression(std::string name)
	{
		this->name = name;
	}
	value_ptr eval(List_variables &main_veriables_list) override
	{
		value_ptr &vl = main_veriables_list.get_value(name);
		if ((*vl).getType() == Token_type::INT) { return std::make_shared<IntValue>((*main_veriables_list.get_value(name)).asInt()); }
		else if ((*vl).getType() == Token_type::FLOAT) { return std::make_shared<FloatValue>((*main_veriables_list.get_value(name)).asFloat()); }
		else if ((*vl).getType() == Token_type::DOUBLE) { return std::make_shared<DoubleValue>((*main_veriables_list.get_value(name)).asDouble()); }
		else if ((*vl).getType() == Token_type::STRING) { return std::make_shared<StringValue>((*main_veriables_list.get_value(name)).asString()); }
		else if ((*vl).getType() == Token_type::BOOL) { return std::make_shared<BoolValue>((*main_veriables_list.get_value(name)).asBool()); }
		else if ((*vl).getType() == Token_type::LIST) { return std::make_shared<ListValue>((*main_veriables_list.get_value(name)).asList()); }
	
	}
	std::string get_str()override
	{
		
		return this->name;
	}
};

