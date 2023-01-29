#include "FunctionExpression.h"
std::shared_ptr<StructValue> FunctionExpression::getStruct(std::shared_ptr<StructValue> val)
{
	std::map<std::string, value_ptr> newStructMap;
	for (const auto & i : (*val).getVal())
	{
		switch ((*i.second).getType())
		{
		case Token_type::INT:
			newStructMap[i.first] = std::make_shared<IntValue>((*i.second).asInt());
			break;
		case Token_type::FLOAT:
			newStructMap[i.first] = std::make_shared<FloatValue>((*i.second).asFloat());
			break;
		case Token_type::DOUBLE:
			newStructMap[i.first] = std::make_shared<DoubleValue>((*i.second).asDouble());
			break;
		case Token_type::BOOL:
			newStructMap[i.first] = std::make_shared<BoolValue>((*i.second).asBool());
			break;
		case Token_type::STRING:
			newStructMap[i.first] = std::make_shared<StringValue>((*i.second).asString());
			break;
		case Token_type::STRUCT:
			newStructMap[i.first] = getStruct(std::static_pointer_cast<StructValue>(i.second));
			break;


		default:
			break;
		}
	}
	return std::make_shared<StructValue>(newStructMap);
}
FunctionExpression::FunctionExpression(std::string name, std::vector<std::shared_ptr<Expression>> agruments)
	{
		this->name = name;
		this->agruments = agruments;
	}
FunctionExpression::FunctionExpression(std::string name)
	{
		this->name = std::move(name);
	}
FunctionExpression::FunctionExpression() = default;

	void FunctionExpression::AddArgument(std::shared_ptr<Expression> agr)
	{
		this->agruments.push_back(agr);
	}
	value_ptr FunctionExpression::eval(List_variables &main_veriables_list) {
		std::vector<value_ptr> values;
		for (int i = 0; i < this->agruments.size(); ++i)
		{
			values.push_back((*this->agruments[i]).eval(main_veriables_list));
		}
		auto &func = (main_veriables_list.get_function(this->name));
		main_veriables_list.add_variables_table();
		if ((*func).is_user_function())
		{
			std::shared_ptr<UserDefinedFunction> func_new = std::static_pointer_cast<UserDefinedFunction>(func);
			std::vector<bool> bool_amp = (*func_new).amp_bool();
			if (this->agruments.size() != (*func).getAtgsCount())
			{
				throw std::exception(PASS_INCORRECT_NUMBER);
			}
			for (int i = 0; i < this->agruments.size(); ++i) {
				if (bool_amp[i])
				{
					main_veriables_list.creat_value((*func).getArgsName(i), std::make_shared<ReferenceValue>(values[i]));
				}
				else {
					if ((*values[i]).getType() == Token_type::STRUCT)
					{
						main_veriables_list.creat_value((*func).getArgsName(i), getStruct(std::static_pointer_cast<StructValue>(values[i])));
					}
					else {
						main_veriables_list.creat_value((*func).getArgsName(i), values[i]);
					}
				}

			}

		}
		value_ptr rw = (*func).exute(values);
		main_veriables_list.delet_variables_table_last();
		return rw;

	};
	std::string FunctionExpression::get_str() { return ""; };
	FunctionExpression::~FunctionExpression() {};