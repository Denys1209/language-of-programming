#pragma once
#include "Statement.h"
class StructDefineStatement :
	public Statement
{
private:
	std::string name;
	std::list<Token> list_values;
	std::vector<std::string> list_names;
public:
	StructDefineStatement(std::string name, std::list<Token> list_values,std::vector<std::string> list_names)
	{
		this->name = std::move(name);
		this->list_values = std::move(list_values);
		this->list_names = std::move(list_names);
	}
	void execute(List_variables &main_veriables_list) override
	{
		main_veriables_list.creat_type_value(name, list_values, list_names);
	};
};

