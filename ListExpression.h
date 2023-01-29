#pragma once
#include "Expression.h"
#include <list>
#include "ListValue.h"
class ListExpression :
	public Expression
{
private:
	std::vector<std::shared_ptr<Expression>> list_expression;
public:
	ListExpression(std::list<std::shared_ptr<Expression>> list_expression);
	ListExpression();
	value_ptr eval(List_variables &main_veriables_list)override;
	void push_back(std::shared_ptr<Expression> new_element);
	std::shared_ptr<Expression> get_element_expression(int idex);
	std::shared_ptr<Expression> last_element();
	int get_size();
};

