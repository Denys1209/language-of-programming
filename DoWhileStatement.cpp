#include "DoWhileStatement.h"
DoWhileStatement::DoWhileStatement(std::shared_ptr<Statement> statement, std::shared_ptr<Expression> condition)
{
	this->condition = condition;
	this->statement = statement;

};
void DoWhileStatement::execute(List_variables &main_veriables_list)
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

	} while ((*(*this->condition).eval(main_veriables_list)).asInt());

};
std::string DoWhileStatement::get_str()  { return ""; };
DoWhileStatement::~DoWhileStatement() {};