#pragma once
#include "Expression.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "BoolValue.h"
#include "StringValue.h"
class BinaryExpression :
	public Expression
{
private:
	std::shared_ptr<Expression> expr1, expr2;
	char operation;
	std::shared_ptr<IntValue> BinaryInt(int val1, int val2);
	std::shared_ptr<DoubleValue> BinaryDouble(double val1, double val2);
	std::shared_ptr<FloatValue> BinaryFloat(float val1, float val2);
	std::shared_ptr<StringValue> BinaryString(value_ptr val1, value_ptr val2);
public:
	BinaryExpression(char operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2);
	value_ptr eval(List_variables &main_veriables_list) override;
	std::string get_str() override;
};

