#pragma once
#include "Function.h"
class SystemFunction :
	public Function
{
private:
	std::function<value_ptr(std::vector<value_ptr> arg)> function;
	int size;
public:
	SystemFunction(std::function<value_ptr(std::vector<value_ptr> arg)> f, int size)
	{
		this->function = std::move(f);
		this->size = size;
	}
	SystemFunction() = default;
	bool is_user_function()override { return false; };
	int getAtgsCount() override { return this->size; }


	value_ptr exute(std::vector<value_ptr> arg) override
	{
		if (arg.size() != size) throw std::exception(PASS_INCORRECT_NUMBER);
		return this->function(std::move(arg));
	}
};

