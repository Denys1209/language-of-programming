#pragma once
#include "Veriables.h"
#include <forward_list>
class List_variables
{
private:
	std::forward_list<std::unique_ptr<Veriables>> main_list;
	std::unique_ptr<Veriables> &find_veriavbles_for_name(std::string name);
public:
	List_variables() 
	{
		main_list.push_front(std::move(std::make_unique<Veriables>()));
	}
	value_ptr &get_value(std::string key);
	function_ptr &get_function(std::string key);
	void set(std::string name, value_ptr value);
	void creat_value(std::string name, value_ptr value);
	void creat_function(std::string name, function_ptr function);
	void add_variables_table();
	void delet_variables_table_last();
};

