#pragma once
#include "Expression.h"
#include "DoubleValue.h"
#include "IntValue.h"
#include "BoolValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"
#include "ListValue.h"

class ValueExpression :
	public Expression
{
private:
	value_ptr value;
public:
	
	ValueExpression(int value);
	ValueExpression(float value);
	ValueExpression(double value);
	ValueExpression(std::vector<value_ptr> value);
	ValueExpression(std::string value);
	value_ptr eval(List_variables &main_veriables_list) override;
	std::string get_str() override;
};

