#pragma once
#include "Statement.h"
class InputStatement :
	public Statement
{
private:
	std::string name;
public:
	InputStatement(std::string name)
	{
		this->name = std::move(name);
	};
	void execute(List_variables &main_veriables_list)
	{
		if ((*(main_veriables_list.get_value(this->name))).is_string())
		{
			std::string res;
			std::cin >> res;
			main_veriables_list.set(this->name, std::make_unique<StringValue>(res));
		}
		else 
		{
			double res;
			std::cin >> res;
			main_veriables_list.set(this->name, std::make_unique<IntValue>(res));
		}
	};
	virtual std::string get_str() { return ""; };
};

