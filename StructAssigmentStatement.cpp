#include "StructAssigmentStatement.h"
std::shared_ptr<Value> StructAssigmentStatement::get_struct(List_variables &main_veriables_list, std::string new_type)
{
	std::shared_ptr<type_struct> type = main_veriables_list.get_type_value(new_type);
	std::map<std::string, std::shared_ptr<Value>> map_val;
	int i = 0;
	for (auto key : (*type).list_values)
	{
		switch (key.getType())
		{
		case Token_type::INT:
			map_val[(*type).list_names[i]] = std::make_shared<IntValue>(0);
			break;
		case Token_type::FLOAT:
			map_val[(*type).list_names[i]] = std::make_shared<FloatValue>(0);
			break;
		case Token_type::DOUBLE:
			map_val[(*type).list_names[i]] = std::make_shared<DoubleValue>(0);
			break;
		case Token_type::STRING:
			map_val[(*type).list_names[i]] = std::make_shared<StringValue>("");
			break;
		case Token_type::BOOL:
			map_val[(*type).list_names[i]] = std::make_shared<BoolValue>(0);
			break;
		case Token_type::WORD:
			map_val[(*type).list_names[i]] = get_struct(main_veriables_list, key.getText());
			break;
		}
		++i;
	}
	return std::make_shared<StructValue>(map_val);
}
StructAssigmentStatement::StructAssigmentStatement(std::string type, std::string name)
{
	this->type = std::move(type);
	this->name = std::move(name);
}
void  StructAssigmentStatement::execute(List_variables &main_veriables_list) 
{
	std::shared_ptr<type_struct> type = main_veriables_list.get_type_value(this->type);
	std::map<std::string, std::shared_ptr<Value>> map_val;
	int i = 0;
	for (auto key : (*type).list_values)
	{
		switch (key.getType())
		{
		case Token_type::INT:
			map_val[(*type).list_names[i]] = std::make_shared<IntValue>(0);
			break;
		case Token_type::FLOAT:
			map_val[(*type).list_names[i]] = std::make_shared<FloatValue>(0);
			break;
		case Token_type::DOUBLE:
			map_val[(*type).list_names[i]] = std::make_shared<DoubleValue>(0);
			break;
		case Token_type::STRING:
			map_val[(*type).list_names[i]] = std::make_shared<StringValue>("");
			break;
		case Token_type::BOOL:
			map_val[(*type).list_names[i]] = std::make_shared<BoolValue>(0);
			break;
		case Token_type::WORD:
			map_val[(*type).list_names[i]] = get_struct(main_veriables_list, key.getText());
			break;
		}
		++i;
	}
	std::shared_ptr<StructValue> val = std::make_shared<StructValue>(map_val);
	main_veriables_list.creat_value(name, val);
};