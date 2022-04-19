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
		if ((*vl).getType() == Token_type::INT) { return std::make_unique<IntValue>((*main_veriables_list.get_value(name)).asInt()); }
		else if ((*vl).getType() == Token_type::FLOAT) { return std::make_unique<FloatValue>((*main_veriables_list.get_value(name)).asFloat()); }
		else if ((*vl).getType() == Token_type::DOUBLE) { return std::make_unique<DoubleValue>((*main_veriables_list.get_value(name)).asDouble()); }
		else if ((*vl).getType() == Token_type::STRING) { return std::make_unique<StringValue>((*main_veriables_list.get_value(name)).asString()); }
		else if ((*vl).getType() == Token_type::BOOL) { return std::make_unique<BoolValue>((*main_veriables_list.get_value(name)).asBool()); }

		/*if ((*vl).is_string()) {
			return std::make_unique<StringValue>((*main_veriables_list.get_value(name)).asString());
		}
		else { 
			return std::make_unique<IntValue>((*main_veriables_list.get_value(name)).asInt()); 
		}*/
	}
	std::string get_str()override
	{
		
		return this->name;
	}
};

