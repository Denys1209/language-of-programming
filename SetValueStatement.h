#pragma once
#include "Statement.h"
class SetValueStatement :
	public Statement
{
private:
	std::string varible;
	std::unique_ptr<Expression> exp;

public:
	SetValueStatement(std::string varible, std::unique_ptr<Expression> exp)
	{
		this->varible = varible;
		this->exp = std::move(exp);

	}
	SetValueStatement() = default;
	void execute(List_variables &main_veriables_list) override
	{
		value_ptr result = (*exp).eval(main_veriables_list);
		main_veriables_list.set(this->varible, std::move(result));
	}
	std::string get_str() override
	{
		std::string r = varible + " = " + (*exp).get_str();
		return r;
	}
};

