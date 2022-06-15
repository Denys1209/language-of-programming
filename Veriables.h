#pragma once
#include <map>
#include <list>
#include <string>
#include <exception>
#include <cmath>
#include "Value.h"
#include "IntValue.h"
#include "DoubleValue.h"
#include "FloatValue.h"
#include "BoolValue.h"
#include "StringValue.h"
#include "SystemFunction.h"
#include "ListValue.h"
#include "StructValue.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#define PI 3.14159265
struct type_struct
{
	std::list<Token> list_values;
	std::vector<std::string> list_names;
	type_struct(std::list<Token> list_values, std::vector<std::string> list_names)
	{
		this->list_values = std::move(list_values);
		this->list_names = std::move(list_names);
	}
};
class Veriables {
	
private:
	std::map<std::string, value_ptr> veriables;
	std::map<std::string, function_ptr> functions;
	std::map<std::string, std::shared_ptr<type_struct>> type_map;
	bool isExistValue(std::string key);
	bool isExistFunction(std::string key);
	bool isExistType(std::string key);
public:
	
	Veriables();
	Veriables(int);
	
	value_ptr &get_value(std::string key);
	std::shared_ptr<type_struct> get_type_value(std::string key);
	function_ptr &get_function(std::string key);
	void set(std::string name, value_ptr value);
	void creat_value(std::string name, value_ptr value);
	void creat_type_value(std::string name, std::list<Token> list_values, std::vector<std::string> list_names);
	void creat_function(std::string name, function_ptr function);
};
