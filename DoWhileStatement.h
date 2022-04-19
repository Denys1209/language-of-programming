#pragma once
#include "Statement.h"
class DoWhileStatement :
	public Statement
{
private:
	std::unique_ptr<Expression> condition;
	std::unique_ptr<Statement> statement;
public:
	DoWhileStatement(std::unique_ptr<Statement> statement, std::unique_ptr<Expression> condition)
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
			catch (std::exception s)
			{
				if (s.what() == "break")
				{
					break;
				}
				else if (s.what() == "continue")
				{
					continue;
				}
			}

		} while ((*(*this->condition).eval(main_veriables_list)).asInt());

	};
	std::string get_str() override { return ""; };
	~DoWhileStatement() {};
};

