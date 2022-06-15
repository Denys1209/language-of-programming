#pragma once
#include "Veriables.h"
#include <forward_list>
class List_variables
{
private:
	friend Veriables;
	std::forward_list<std::shared_ptr<Veriables>> main_list;
	std::shared_ptr<Veriables> &find_veriavbles_for_name(std::string name);
public:
	List_variables() 
	{
		main_list.push_front(std::move(std::make_shared<Veriables>()));
	}
	value_ptr &get_value(std::string key);
	std::shared_ptr<type_struct> get_type_value(std::string key);
	function_ptr &get_function(std::string key);
	void set(std::string name, value_ptr value);
	void creat_value(std::string name, value_ptr value);
	void creat_type_value(std::string name, std::list<Token> list_values, std::vector<std::string> list_names);
	void creat_function(std::string name, function_ptr function);
	void add_variables_table();
	void delet_variables_table_last();
};

