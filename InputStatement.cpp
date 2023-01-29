#include "InputStatement.h"
InputStatement::InputStatement(std::string name)
{
	this->name = std::move(name);
};
void InputStatement::execute(List_variables &main_veriables_list)
{
	if ((*(main_veriables_list.get_value(this->name))).is_string())
	{
		std::string res;
		std::cin >> res;
		main_veriables_list.set(this->name, std::make_shared<StringValue>(res));
	}
	else
	{
		double res;
		std::cin >> res;
		main_veriables_list.set(this->name, std::make_shared<IntValue>(res));
	}
};
std::string InputStatement::get_str() { return ""; };