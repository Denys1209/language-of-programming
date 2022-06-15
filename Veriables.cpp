#include "Veriables.h"
Veriables::Veriables()
{
	auto sin = [](std::vector<value_ptr> arg)
	{
		double res, param;
		param = (*arg[0]).asInt();
		res = std::sin(param * PI / 180);

		return std::make_shared<DoubleValue>(res);
	};
	auto system = [](std::vector<value_ptr> arg)
	{
		std::system(((*arg[0]).asString()).c_str());

		return nullptr;
	};
	auto getBatton = [](std::vector<value_ptr> arg)
	{
		return std::make_shared<StringValue>(std::string(1, char(_getch())));
	};
	auto len = [](std::vector<value_ptr> arg)
	{
		auto list = std::static_pointer_cast<ListValue>(arg[0]);
		return std::make_shared<IntValue>((*list).getSize());
	};
	

	

	this->veriables.insert(std::pair<std::string, value_ptr>("PI", std::move(std::make_shared<DoubleValue>(PI))));
	this->veriables.insert(std::pair<std::string, value_ptr>("E", std::move(std::make_shared<DoubleValue>(2.71828))));
	this->veriables.insert(std::pair<std::string, value_ptr>("GOLDEN_RATIO", std::move(std::make_shared<DoubleValue>(1.618))));
	this->veriables.insert(std::pair<std::string, value_ptr>("true", std::move(std::make_shared<BoolValue>(true))));
	this->veriables.insert(std::pair<std::string, value_ptr>("false", std::move(std::make_shared<BoolValue>(false))));
	this->functions.insert(std::pair<std::string, function_ptr>("sin", std::move(std::make_shared<SystemFunction>(sin, 1))));
	this->functions.insert(std::pair<std::string, function_ptr>("system", std::move(std::make_shared<SystemFunction>(system, 1))));
	this->functions.insert(std::pair<std::string, function_ptr>("getBatton", std::move(std::make_shared<SystemFunction>(getBatton, 0))));
	this->functions.insert(std::pair<std::string, function_ptr>("len", std::move(std::make_shared<SystemFunction>(len, 1))));

}
Veriables::Veriables(int) {};

bool Veriables::isExistValue(std::string key)
{

	if (this->veriables.find(key) == this->veriables.end())
	{
		return false;
	}
	return true;

}
bool Veriables::isExistFunction(std::string key)
{

	if (this->functions.find(key) == this->functions.end())
	{
		return false;
	}
	return true;

}
bool Veriables::isExistType(std::string key)
{

	if (this->type_map.find(key) == this->type_map.end())
	{
		return false;
	}
	return true;

}
value_ptr &Veriables::get_value(std::string key) {
	if (!this->isExistValue(key)) {
		std::string exp = "unknow value " + key;
		throw std::exception(exp.c_str());
	}
	return this->veriables[key];

}

std::shared_ptr<type_struct> Veriables::get_type_value(std::string key)
{
	return this->type_map[key];
}

function_ptr &Veriables::get_function(std::string key) {
	if (!this->isExistFunction(key)) {
		std::string exp = "unknow function " + key;
		throw std::exception(exp.c_str());
	}
	return this->functions[key];
}
void Veriables::set(std::string name, value_ptr value)
{
	try {
		this->get_value(name);
		if ((*this->veriables[name]).getType() == (*value).getType()) {
			(*this->veriables[name]).operator_equal(value);
		}
		else 
		{
			this->veriables[name] = std::move(value);
		}
		
	}
	catch (std::exception)
	{
		std::string exp = "this value " + name + " isn't exist";
		throw std::exception(exp.c_str());
	}

}
void Veriables::creat_value(std::string name, value_ptr value)
{
	if (!isExistValue(name)) {
		this->veriables.insert(std::pair<std::string, value_ptr>(name, std::move(value)));
		return;
	}
	switch ((*value).getType())
	{
	case Token_type::INT:
		this->veriables[name] = std::move(std::make_shared<IntValue>((*this->get_value(name)).asInt()));
		break;
	case Token_type::DOUBLE:
		this->veriables[name] = std::move(std::make_shared<DoubleValue>((*this->get_value(name)).asDouble()));
		break;
	case Token_type::FLOAT:
		this->veriables[name] = std::move(std::make_shared<FloatValue>((*this->get_value(name)).asFloat()));
		break;
	case Token_type::BOOL:
		this->veriables[name] = std::move(std::make_shared<BoolValue>((*this->get_value(name)).asBool()));
		break;
	case Token_type::STRING:
		this->veriables[name] = std::move(std::make_shared<StringValue>((*this->get_value(name)).asString()));
		break;
	default:
		break;
	}

}
void Veriables::creat_type_value(std::string name, std::list<Token> list_values, std::vector<std::string> list_names)
{
	std::shared_ptr<type_struct> new_type = std::make_shared<type_struct>(list_values, list_names);
	this->type_map[name] = new_type;
}
void Veriables::creat_function(std::string name, function_ptr function)
{
	try {
		this->get_value(name);
		this->functions[name] = std::move(function);
	}
	catch (std::exception)
	{
		this->functions.insert(std::pair<std::string, function_ptr>(name, std::move(function)));
	}

}