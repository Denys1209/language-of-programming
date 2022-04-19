#pragma once
#include "Expression.h"
#include "Expression.h"
#include "IntValue.h"
#include <typeinfo>
#include "StringValue.h"
#include "BoolValue.h"
class ConditionalExpression :
	public Expression

{
private:
	std::unique_ptr<Expression> expr1, expr2;
	std::string operation;
	bool compareString(std::string val1, std::string val2);
	bool compareInt(int val1, int val2);
	bool compareDouble(double val1, double val2);
	bool compareFloat(float val1, float val2);
	bool compareBool(bool val1, bool val2);
public:
	ConditionalExpression(std::string operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2)
	{
		this->expr1 = std::move(expr1);
		this->expr2 = std::move(expr2);
		this->operation = operation;
	}
	value_ptr eval(List_variables &main_veriables_list) override;
	std::string get_str() override
	{
		std::string res = "(" + (*expr1).get_str() + operation + (*expr2).get_str() + ")";
		return res;
	}
};
