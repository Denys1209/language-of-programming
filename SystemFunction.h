#pragma once
#include "Function.h"
class SystemFunction :
	public Function
{
private:
	std::function<value_ptr(std::vector<value_ptr> arg)> function;
	int size;
public:
	SystemFunction(std::function<value_ptr(std::vector<value_ptr> arg)> f, int size);
	SystemFunction();
	bool is_user_function()override;
	int getAtgsCount() override;


	value_ptr exute(std::vector<value_ptr> arg) override;
};

