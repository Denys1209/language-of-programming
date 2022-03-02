#pragma once
#include "Statement.h"
#include "Expression.h"
class AssigmentStatement : public Statement
{
private:
	std::string varible;
	std::unique_ptr<Expression> exp;
public:
	AssigmentStatement(std::string varible, std::unique_ptr<Expression> exp)
	{
		this->varible = varible;
		this->exp = std::move(exp);
	}
	AssigmentStatement()
	{
		
	}
	void execute(Veriables &main_veriables_list) override
	{
		double result = (*exp).eval(main_veriables_list);
		main_veriables_list.set(this->varible, result);
	}
	std::string get_str() override
	{
		std::string r = varible+ " = " + (*exp).get_str();
		return r;
	}
};

