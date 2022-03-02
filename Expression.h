#pragma once
#include <string>
#include "setting.h"
class Expression
{
public:
	virtual double eval(Veriables &main_veriables_list) { return 0; };
	virtual std::string get_str() { return ""; };
	virtual ~Expression() {};
};

