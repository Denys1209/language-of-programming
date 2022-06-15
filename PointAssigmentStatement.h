#pragma once
#include "Statement.h"
#include "ListExpression.h"
class PointAssigmentStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> exp1;
	std::shared_ptr<Expression> exp2;

public:
	PointAssigmentStatement(std::shared_ptr<Expression> exp1,std::shared_ptr<Expression> exp2)
	{
		this->exp1 = std::move(exp1);		
		this->exp2 = std::move(exp2);
	}
	void execute(List_variables &main_veriables_list) override 
	{
		std::shared_ptr<Value> val = (*exp1).eval(main_veriables_list);
		(*val).operator_equal((*exp2).eval(main_veriables_list));
	};


};

