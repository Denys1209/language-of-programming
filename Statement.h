#pragma once
#include <string>
#include "setting.h"
#include "Expression.h"
class Statement
{
public:
	Statement() = default;
	virtual void execute(Veriables &main_veriables_list) {};
	virtual std::string get_str() { return ""; };
	virtual ~Statement() {};
};

