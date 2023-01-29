#pragma once
#include "Statement.h"
#include "ListExpression.h"
class  PointAssigmentStatement  :
	public Statement
{
private:
	std::shared_ptr<Expression> exp1;
	std::shared_ptr<Expression> exp2;

public:
	PointAssigmentStatement(std::shared_ptr<Expression> exp1, std::shared_ptr<Expression> exp2);
	void execute(List_variables &main_veriables_list) override;


};

