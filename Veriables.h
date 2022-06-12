#pragma once
#include <map>
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
#include "Token_types.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#define PI 3.14159265
class Veriables {
private:
	
	std::map<std::string, value_ptr> veriables;
	std::map<std::string, function_ptr> functions;
	std::map<std::string, value_ptr> type_map;
	bool isExistValue(std::string key);
	bool isExistFunction(std::string key);
	bool isExistType(std::string key);
public:
	Veriables();
	Veriables(int);
	
	value_ptr &get_value(std::string key);
	value_ptr &get_type_value(std::string key);
	function_ptr &get_function(std::string key);
	void set(std::string name, value_ptr value);
	void creat_value(std::string name, value_ptr value);
	void creat_function(std::string name, function_ptr function);
};
