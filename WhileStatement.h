#pragma once
#include "Statement.h"
#include "Expression.h"
class WhileStatement :
	public Statement
{
private:
	std::unique_ptr<Expression> condition;
	std::unique_ptr<Statement> statement;
public:
	WhileStatement(std::unique_ptr<Expression> condition, std::unique_ptr<Statement> statement)
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
	
	};
	std::string get_str() override { return ""; };
	~WhileStatement() {};
};

