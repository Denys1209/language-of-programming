#include "PointExpression.h"

value_ptr PointExpression::read_point(List_variables &main_veriables_list)
{
	value_ptr val = (*main_veriables_list.get_value(this->name)).operator_point(this->keyStringName[0]);;
	for (int i = 1; i < this->keyStringName.size(); ++i)
	{
		val = (*val).operator_point(keyStringName[i]);
	}
	return val;
}
PointExpression::PointExpression(std::string name, std::vector<std::string> keyStringName)
{
	this->name = std::move(name);
	this->keyStringName = std::move(keyStringName);

}
value_ptr PointExpression::eval(List_variables &main_veriables_list)
{

	return read_point(main_veriables_list);
};
PointExpression::~PointExpression() = default;