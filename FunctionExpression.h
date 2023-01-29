#pragma once
#include "Expression.h"
#include "Value.h"
#include "StructValue.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"
#include "ReferenceValue.h"
#include "Function.h"
#include "UserDefinedFunction.h"
#include <vector>

class FunctionExpression :
	public Expression
{
private:
	std::string name;
	std::vector<std::shared_ptr<Expression>> agruments;
	std::shared_ptr<StructValue> getStruct(std::shared_ptr<StructValue> val);
public:
	FunctionExpression(std::string name, std::vector<std::shared_ptr<Expression>> agruments);
	FunctionExpression(std::string name);
	FunctionExpression();
	
	void AddArgument(std::shared_ptr<Expression> agr);
	value_ptr eval(List_variables &main_veriables_list);
	std::string get_str()override;
	~FunctionExpression();
};
