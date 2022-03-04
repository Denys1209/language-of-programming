#pragma once
#include <string>
#include <exception>

class Value
{

public:
	double virtual asDouble() { return 0; };
	std::string virtual asString() { return ""; };
	bool virtual is_string() { return false; }
};
using value_ptr = std::unique_ptr<Value>;

