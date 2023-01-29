#include "WhileStatement.h"

WhileStatement::WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> statement)
{
	this->condition = std::move(condition);
	this->statement = std::move(statement);

};
void WhileStatement::execute(List_variables &main_veriables_list)
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
std::string WhileStatement::get_str()  { return ""; };
WhileStatement::~WhileStatement() {};