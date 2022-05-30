#pragma once
#include "Statement.h"
#include "Expression.h"
class WhileStatement :
	public Statement
{
private:
	std::shared_ptr<Expression> condition;
	std::shared_ptr<Statement> statement;
public:
	WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> statement)
	{
		this->condition = std::move(condition);
		this->statement = std::move(statement);

	};
	void execute(List_variables &main_veriables_list)override
	{
		
		while ((*(*this->condition).eval(main_veriables_list)).asBool()) 
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
			
		}
	
	};
	std::string get_str() override { return ""; };
	~WhileStatement() {};
};

