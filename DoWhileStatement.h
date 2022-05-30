#pragma once
#include "Statement.h"
class DoWhileStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> condition;
	std::shared_ptr<Statement> statement;
public:
	DoWhileStatement(std::shared_ptr<Statement> statement, std::shared_ptr<Expression> condition)
	{
		this->condition = std::move(condition);
		this->statement = std::move(statement);

	};
	void execute(List_variables &main_veriables_list)override
	{

		do
		{
			try {
				(*statement).execute(main_veriables_list);
			}
			catch (const char*s)
			{
				if (s == BREAK_TEXT)
				{
					main_veriables_list.delet_variables_table_last();
					break;

				}
				else if (s == CONTINUE_TEXT)
				{
					main_veriables_list.delet_variables_table_last();
					continue;
				}

			}
			catch (std::exception s)
			{
				throw s;
			}

		} while ((*(*this->condition).eval(main_veriables_list)).asInt());

	};
	std::string get_str() override { return ""; };
	~DoWhileStatement() {};
};

