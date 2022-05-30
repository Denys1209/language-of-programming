#pragma once
#include "Statement.h"
#include "Expression.h"
class FunctionStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> exp;
public:
	FunctionStatement(std::shared_ptr<Expression> exp)
	{
		this->exp = std::move(exp);
	};
	FunctionStatement() = default;
	void execute(List_variables &main_veriables_list) override
	{
		(*exp).eval(main_veriables_list);
	};
	std::string get_str() override { return ""; };
	~FunctionStatement()  {};
};

