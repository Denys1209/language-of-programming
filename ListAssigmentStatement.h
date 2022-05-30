#pragma once
#include "Statement.h"
#include "ListValue.h"

class ListAssigmentStatement :
	public Statement
{
private:
	std::string variable;
	std::shared_ptr<Expression> index;
	std::shared_ptr<Expression> expression;

	std::shared_ptr<ListValue> get_list(List_variables &main_veriables_list)
	{
		std::shared_ptr<ListValue> rw = std::static_pointer_cast<ListValue>(main_veriables_list.get_value(this->variable));
		std::shared_ptr<ListExpression> list_expression = std::static_pointer_cast<ListExpression>(index);
		for (int i = 0; i < (*list_expression).get_size() - 1; ++i) {
			rw = std::static_pointer_cast<ListValue>((*rw).getElementIndex((*(*(*list_expression).get_element_expression(i))
				.eval(main_veriables_list)).asInt()
			));
		}
		return rw;
	}

public:
	ListAssigmentStatement(std::string varialbe, std::shared_ptr<Expression> index, std::shared_ptr<Expression> expression) 
	{
		this->variable = std::move(varialbe);
		this->index = index;
		this->expression = expression;
	}
	void execute(List_variables &main_veriables_list) override
	{
		std::shared_ptr<ListValue> list = get_list(main_veriables_list);
		std::shared_ptr<Value> index = (*(*std::static_pointer_cast<ListExpression>(this->index)).last_element()).eval(main_veriables_list);
		
		
		try {
			(*list).setElementIndex((*index).asInt(), (*expression).eval(main_veriables_list));

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

