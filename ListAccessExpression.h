#pragma once
#include "Expression.h"
#include "ListValue.h"
class ListAccessExpression :
	public Expression
{
private:

	std::string variable;
	std::shared_ptr<Expression> index;

	std::shared_ptr<ListValue> get_list(List_variables &main_veriables_list)
	{
		std::shared_ptr<ListValue> rw = std::static_pointer_cast<ListValue>(main_veriables_list.get_value(this->variable));
		std::shared_ptr<ListExpression> list_expression = std::static_pointer_cast<ListExpression>(index);
		for (int i = 0; i < (*list_expression).get_size()-1; ++i) {
			rw = std::static_pointer_cast<ListValue>((*rw).getElementIndex((*(*(*list_expression).get_element_expression(i))
				.eval(main_veriables_list)).asInt()
				));
		}
		return rw;
	}

public:
	ListAccessExpression(std::string variable, std::shared_ptr<Expression> index)
	{
		this->variable = std::move(variable);
		this->index = index;
	}
	value_ptr eval(List_variables &main_veriables_list) override
	{
		
		std::shared_ptr<Value> list = get_list(main_veriables_list);

		std::shared_ptr<Value> value = (*(*std::static_pointer_cast<ListExpression>(index)).last_element()).eval(main_veriables_list);
		try {
			return (*list).getElementIndex((*value).asInt());
		}
		catch (std::exception exp)
		{
			throw exp;
		}
		catch (...)
		{
			throw std::exception(OUT_OF_THE_LIST);
		}
		
	}


};

