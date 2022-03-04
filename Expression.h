#pragma once
#include <string>
#include "setting.h"
#include "Value.h"

class Expression
{
public:
	virtual value_ptr eval(Veriables &main_veriables_list) { return nullptr; };
	virtual std::string get_str() { return ""; };
	virtual ~Expression() {};
};

