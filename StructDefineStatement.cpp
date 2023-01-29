#include "StructDefineStatement.h"
StructDefineStatement::StructDefineStatement(std::string name, std::list<Token> list_values, std::vector<std::string> list_names)
{
	this->name = std::move(name);
	this->list_values = std::move(list_values);
	this->list_names = std::move(list_names);
}
void StructDefineStatement::execute(List_variables &main_veriables_list) 
{
	main_veriables_list.creat_type_value(name, list_values, list_names);
};