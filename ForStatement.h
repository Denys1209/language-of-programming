#pragma once
#include "Statement.h"
class ForStatement :
	public Statement
{
private:
	

	std::unique_ptr<Statement> initialization;
	std::unique_ptr<Expression> termination;
	std::unique_ptr<Statement> increment;
	std::unique_ptr<Statement> block;
public:
	ForStatement(std::unique_ptr<Statement> stinitializationatement, std::unique_ptr<Expression> termination,  std::unique_ptr<Statement> increment, std::unique_ptr<Statement> block)
	{
		this->initialization = std::move(stinitializationatement);
		this->termination = std::move(termination);
		this->increment = std::move(increment);
		this->block = std::move(block);

	};
	void execute(List_variables &main_veriables_list) override
	{
		main_veriables_list.add_variables_table();

		for ((*initialization).execute(main_veriables_list); (*((*termination).eval(main_veriables_list))).asInt() != 0; (*increment).execute(main_veriables_list))
		{
			try {
				(*block).execute(main_veriables_list);
			}
			catch (std::exception s )
			{
				if (s.what() == BREAK_TEXT)
				{
					break;
				}
				else if (s.what() == CONTINUE_TEXT)
				{
					continue;
				}
				else 
				{
					throw s;
				}
			}
		}
		main_veriables_list.delet_variables_table_last();
	};
	std::string get_str() override { return ""; };
	virtual ~ForStatement() {};
};

