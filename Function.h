#pragma once
#include "Value.h"
#include <functional>
#include <vector>
#include <exception>

class Function
{

public:
	
	Function() = default;
	
	virtual value_ptr exute(std::vector<value_ptr> arg ) { return nullptr; };
	virtual bool is_user_function() { return false; };
	//virtual Token get_type(int i) {
	//	auto a = Token(Token_type::NONE, "");
	//	return a;};
	virtual std::string getArgsName(int index) { return "\0"; }
	virtual int getAtgsCount() { return 0; }


};
using function_ptr = std::unique_ptr<Function>;
