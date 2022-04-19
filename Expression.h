#pragma once
#include <string>
#include "List_variables.h"
#include "DoubleValue.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"
#include "System_const.h"

class Expression
{
public:
	virtual value_ptr eval(List_variables &main_veriables_list) { return nullptr; };
	virtual std::string get_str() { return ""; };
	virtual ~Expression() {};
};

