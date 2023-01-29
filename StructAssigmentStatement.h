#pragma once
#include "Statement.h"
#include "StructValue.h"
#include <list>
class StructAssigmentStatement :
	public Statement
{
private:
	std::string name;
	std::string type;
	std::shared_ptr<Value> get_struct(List_variables &main_veriables_list, std::string new_type);
public:
	StructAssigmentStatement(std::string type, std::string name);
	void execute(List_variables &main_veriables_list) override;
};

