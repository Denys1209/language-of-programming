#include "IfStatement.h"
IfStatement::IfStatement() = default;
IfStatement::IfStatement(std::list<std::shared_ptr<Expression>> expressions, std::list<std::shared_ptr<Statement>> ifStatements, std::shared_ptr<Statement> elseStatement)
{
	this->expressions = std::move(expressions);
	this->ifStatements = std::move(ifStatements);
	this->elseStatement = std::move(elseStatement);
}
void IfStatement::execute(List_variables &main_veriables_list) 
{

	auto expression_count = this->expressions.begin();
	auto ifStatements_count = this->ifStatements.begin();
	while (expression_count != this->expressions.end()) {
		bool result = (*(*(*expression_count)).eval(main_veriables_list)).asInt();
		if (result)
		{
			(*(*ifStatements_count)).execute(main_veriables_list);
			return;
		}
		expression_count++;
		ifStatements_count++;
	}
	if (this->elseStatement != nullptr)
	{
		(*this->elseStatement).execute(main_veriables_list);
	}

};
std::string IfStatement::get_str()  { return ""; };