#pragma once
#include "Expression.h"
class PointExpression :
	public Expression
{
private:
	std::string name;
	std::vector<std::string> keyStringName;
	value_ptr read_point(List_variables &main_veriables_list);
public:
	PointExpression(std::string name, std::vector<std::string> keyStringName);
	value_ptr eval(List_variables &main_veriables_list);
	~PointExpression();


};

