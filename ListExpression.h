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
	ListExpression(std::list<std::shared_ptr<Expression>> list_expression)
	{
		for (auto i = list_expression.begin(); i != list_expression.end(); i++) {
			this->list_expression.push_back( (*i));
			
		}
	}
	ListExpression() = default;
	value_ptr eval(List_variables &main_veriables_list)override  
	{
		std::shared_ptr<ListValue> rw = std::make_shared<ListValue>();
		for (auto i = list_expression.begin(); i != list_expression.end(); i++) {
			value_ptr temp = (*(*i)).eval(main_veriables_list);
			(*rw).push_back(temp);
		}
		return rw;
	}
	void push_back(std::shared_ptr<Expression> new_element) 
	{
		this->list_expression.push_back(new_element);
	}
	std::shared_ptr<Expression> get_element_expression(int idex)
	{
		return this->list_expression[idex];
	}
	std::shared_ptr<Expression> last_element()
	{
		return this->list_expression[get_size()-1];
	}
	int get_size() 
	{
		return this->list_expression.size();
	}
};

