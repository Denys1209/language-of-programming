#pragma once
#include "Expression.h"
#include "Value.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"
#include "Function.h"
#include <vector>

class FunctionExpression :
	public Expression
{
private:
	std::string name;
	std::vector<std::unique_ptr<Expression>> agruments;
public:
	FunctionExpression(std::string name, std::vector<std::unique_ptr<Expression>> agruments)
	{
		this->name = std::move(name);
		this->agruments = std::move(agruments);
	}
	FunctionExpression(std::string name)
	{
		this->name = std::move(name);
	}
	FunctionExpression() = default;
	
	void AddArgument(std::unique_ptr<Expression> agr)
	{
		this->agruments.push_back(std::move(agr));
	}
	value_ptr return_value_for_type(Token &type, value_ptr &arg)
	{
		if (type.getType() == Token_type::INT)
		{
			return std::make_unique<IntValue>((*arg).asInt());
		}
		else if (type.getType() == Token_type::STRING)
		{
			return std::make_unique<StringValue>((*arg).asString());
		}
		else if (type.getType() == Token_type::FLOAT)
		{
			return std::make_unique<FloatValue>((*arg).asFloat());
		}
		else if (type.getType() == Token_type::DOUBLE)
		{
			return std::make_unique<DoubleValue>((*arg).asDouble());
		}
		else 
		{
			throw std::exception(UNKNOW_THE_TYPE);
		}
	}
	value_ptr eval(List_variables &main_veriables_list)  {
		std::vector<value_ptr> values;
		for (int i=0; i< this->agruments.size(); ++i)
		{
			values.push_back(std::move((*this->agruments[i]).eval(main_veriables_list)));
		}
		auto &func = (main_veriables_list.get_function(this->name));
		main_veriables_list.add_variables_table();
		if ((*func).is_user_function())
		{
			
			if (this->agruments.size() != (*func).getAtgsCount()) 
			{
				throw std::exception(PASS_INCORRECT_NUMBER);
			}
			for (int i = 0; i< this->agruments.size(); ++i)
			{
				//main_veriables_list.creat_value((*func).getArgsName(i),this->return_value_for_type((*func).get_type(i), values[i]));
			}

		}
		auto rw = std::move((*func).exute(std::move(values)));
		main_veriables_list.delet_variables_table_last();
		return rw;

	};
	std::string get_str()override { return ""; };
	~FunctionExpression() {};
};
