#pragma once
#include <string>
#include <iostream> 
#include "List_variables.h"
#include "Expression.h"
#include "System_const.h"
class Statement
{
public:
	Statement() = default;
	virtual void execute(List_variables &main_veriables_list) {};
	virtual std::string get_str() { return ""; };
	virtual ~Statement() {};
};

