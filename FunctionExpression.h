#pragma once
#include "Expression.h"
#include "Value.h"
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
public:
	FunctionExpression(std::string name, std::vector<std::shared_ptr<Expression>> agruments)
	{
		this->name = name;
		this->agruments = agruments;
	}
	FunctionExpression(std::string name)
	{
		this->name = std::move(name);
	}
	FunctionExpression() = default;
	
	void AddArgument(std::shared_ptr<Expression> agr)
	{
		this->agruments.push_back(agr);
	}
	value_ptr eval(List_variables &main_veriables_list)  {
		std::vector<value_ptr> values;
		for (int i=0; i< this->agruments.size(); ++i)
		{
			values.push_back((*this->agruments[i]).eval(main_veriables_list));
		}
		auto &func = (main_veriables_list.get_function(this->name));
		main_veriables_list.add_variables_table();
		if ((*func).is_user_function())
		{
			std::shared_ptr<UserDefinedFunction> func_new = std::static_pointer_cast<UserDefinedFunction>(func);
			std::vector<bool> bool_amp = (*func_new).amp_bool();
			if (this->agruments.size() != (*func).getAtgsCount()) 
			{
				throw std::exception(PASS_INCORRECT_NUMBER);
			}
			for (int i = 0; i < this->agruments.size();++i) {
				if (bool_amp[i]) 
				{
					main_veriables_list.creat_value((*func).getArgsName(i), std::make_shared<ReferenceValue>(values[i]));
				}
				else {
					main_veriables_list.creat_value((*func).getArgsName(i), values[i]);
				}
				
			}

		}
		value_ptr rw = (*func).exute(values);
		main_veriables_list.delet_variables_table_last();
		return rw;

	};
	std::string get_str()override { return ""; };
	~FunctionExpression() {};
};
