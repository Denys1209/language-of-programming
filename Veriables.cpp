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

	this->type_map.insert(std::pair<std::string, value_ptr>("int", std::move(std::make_shared<IntValue>(0))));
	this->type_map.insert(std::pair<std::string, value_ptr>("float", std::move(std::make_shared<FloatValue>(0))));
	this->type_map.insert(std::pair<std::string, value_ptr>("double", std::move(std::make_shared<DoubleValue>(0))));
	this->type_map.insert(std::pair<std::string, value_ptr>("bool", std::move(std::make_shared<BoolValue>(0))));
	this->type_map.insert(std::pair<std::string, value_ptr>("string", std::move(std::make_shared<StringValue>(""))));

	this->veriables.insert(std::pair<std::string, value_ptr>("PI", std::move(std::make_shared<DoubleValue>(PI))));
	this->veriables.insert(std::pair<std::string, value_ptr>("E", std::move(std::make_shared<DoubleValue>(2.71828))));
	this->veriables.insert(std::pair<std::string, value_ptr>("GOLDEN_RATIO", std::move(std::make_shared<DoubleValue>(1.618))));
	this->veriables.insert(std::pair<std::string, value_ptr>("true", std::move(std::make_shared<BoolValue>(true))));
	this->veriables.insert(std::pair<std::string, value_ptr>("false", std::move(std::make_shared<BoolValue>(false))));
	this->functions.insert(std::pair<std::string, function_ptr>("sin", std::move(std::make_shared<SystemFunction>(sin, 1))));
	this->functions.insert(std::pair<std::string, function_ptr>("system", std::move(std::make_shared<SystemFunction>(system, 1))));
	this->functions.insert(std::pair<std::string, function_ptr>("getBatton", std::move(std::make_shared<SystemFunction>(getBatton, 0))));


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

value_ptr &Veriables::get_type_value(std::string key)
{
	if (!this->isExistValue(key)) {
		std::string exp = "unknow type " + key;
		throw std::exception(exp.c_str());
	}
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