#include "BlockStatement.h"
BlockStatement::BlockStatement() = default;

void BlockStatement::add(std::shared_ptr<Statement> statement)
{

	this->lis.push_back(std::move(statement));

}
void BlockStatement::execute(List_variables &main_veriables_list) 
{
	main_veriables_list.add_variables_table();
	try {
		for (auto &i : this->lis)
		{
			(*i).execute(main_veriables_list);
		}
	}
	catch (const char*exc) {
		main_veriables_list.delet_variables_table_last();
		throw exc;
	}
	catch (std::exception exc) {
		main_veriables_list.delet_variables_table_last();
		throw exc;
	}
	main_veriables_list.delet_variables_table_last();
};
std::string BlockStatement::get_str() { return ""; };
BlockStatement::~BlockStatement() {};