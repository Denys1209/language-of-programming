#pragma once
#include "Value.h"
#include "Token.h"
#include <functional>
#include <vector>
#include <exception>

class Function
{

public:
	
	Function() = default;
	
	virtual value_ptr exute(std::vector<value_ptr> arg ) { return nullptr; }
	virtual bool is_user_function() { return false; }
	virtual std::string getArgsName(int index) { return "\0"; }
	virtual int getAtgsCount() { return 0; }
	virtual	~Function() = default;

};
using function_ptr = std::shared_ptr<Function>;
