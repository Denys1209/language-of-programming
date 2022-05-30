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
	/*virtual std::pair<Token_type, std::string> get_type_i_element(int i) const
	{
		return std::pair<Token_type::NONE, "">;
	}*/
	virtual std::string getArgsName(int index) { return "\0"; }
	virtual int getAtgsCount() { return 0; }


};
using function_ptr = std::shared_ptr<Function>;
