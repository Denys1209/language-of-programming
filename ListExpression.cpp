#include "ListExpression.h"
ListExpression::ListExpression(std::list<std::shared_ptr<Expression>> list_expression)
{
	for (auto i = list_expression.begin(); i != list_expression.end(); i++) {
		this->list_expression.push_back((*i));

	}
}
ListExpression::ListExpression() = default;
value_ptr ListExpression::eval(List_variables &main_veriables_list)
{
	std::shared_ptr<ListValue> rw = std::make_shared<ListValue>();
	for (auto i = list_expression.begin(); i != list_expression.end(); i++) {
		value_ptr temp = (*(*i)).eval(main_veriables_list);
		(*rw).push_back(temp);
	}
	return rw;
}
void ListExpression::push_back(std::shared_ptr<Expression> new_element)
{
	this->list_expression.push_back(new_element);
}
std::shared_ptr<Expression> ListExpression::get_element_expression(int idex)
{
	return this->list_expression[idex];
}
std::shared_ptr<Expression> ListExpression::last_element()
{
	return this->list_expression[get_size() - 1];
}
int ListExpression::get_size()
{
	return this->list_expression.size();
}