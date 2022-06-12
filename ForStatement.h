#pragma once
#include "Statement.h"
class ForStatement :
	public Statement
{
private:
	

	std::shared_ptr<Statement> initialization;
	std::shared_ptr<Expression> termination;
	std::shared_ptr<Statement> increment;
	std::shared_ptr<Statement> block;
public:
	ForStatement(std::shared_ptr<Statement> stinitializationatement, std::shared_ptr<Expression> termination,  std::shared_ptr<Statement> increment, std::shared_ptr<Statement> block)
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
			catch (const char*s)
			{
				if (s == BREAK_TEXT)
				{
					break;

				}
				else if (s == CONTINUE_TEXT)
				{
					continue;
				}

			}
			catch (std::exception s)
			{
				throw s;
			}
		}
		main_veriables_list.delet_variables_table_last();
	};
	std::string get_str() override { return ""; };
	virtual ~ForStatement() {};
};

