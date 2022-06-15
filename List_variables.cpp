#include "List_variables.h"
std::shared_ptr<Veriables> &List_variables::find_veriavbles_for_name(std::string name)
{
	for (auto i = this->main_list.begin(); i != this->main_list.end(); ++i)
	{
		try
		{
			(*(*i)).get_value(name);
			return (*i);
		}
		catch (std::exception exc)
		{
			continue;
		}

	}
	std::string exc = "unknow value " + name;
	throw std::exception(exc.c_str());
}

value_ptr & List_variables::get_value(std::string key)
{
	for (auto i = this->main_list.begin(); i!=this->main_list.end();++i)
	{
		try 
		{
			return (*(*i)).get_value(key);
		}
		catch (std::exception exc)
		{
			continue;
		}
		
	}
	std::string exc = "unknow value " + key;
	throw std::exception(exc.c_str());
}
std::shared_ptr<type_struct> List_variables::get_type_value(std::string key)
{
	for (auto i = this->main_list.begin(); i != this->main_list.end(); ++i)
	{
		try
		{
			return (*(*i)).get_type_value(key);
		}
		catch (std::exception exc)
		{
			continue;
		}
	}
	std::string exc = "unknow struct " + key;
	throw std::exception(exc.c_str());
}
function_ptr &List_variables::get_function(std::string key)
{
	for (auto i = this->main_list.begin(); i != this->main_list.end(); ++i)
	{
		try
		{
			return (*(*i)).get_function(key);
		}
		catch (std::exception exc)
		{
			continue;
		}
	}
	std::string exc= "unknow function "+ key;
	throw std::exception(exc.c_str());
}
void List_variables::set(std::string name, value_ptr value)
{
	for (auto i = this->main_list.begin(); i != this->main_list.end(); ++i)
	{
		try
		{
			(*(this->find_veriavbles_for_name(name))).set(name, std::move(value));
			return;
			
		}
		catch (std::exception exc)
		{
			continue;
		}

	}
	std::string exc = "unknow value " + name;
	throw std::exception(exc.c_str());
}

void List_variables::creat_value(std::string name, value_ptr value)
{
	(*(*(this->main_list.begin()))).creat_value(name, std::move(value));
}

void List_variables::creat_type_value(std::string name, std::list<Token> list_values, std::vector<std::string> list_names)
{
	(*(*(this->main_list.begin()))).creat_type_value(name, list_values, list_names);

}

void List_variables::creat_function(std::string name, function_ptr function)
{
	(*(*(this->main_list.begin()))).creat_function(name, function);
}

void List_variables::add_variables_table()
{
	this->main_list.push_front(std::make_shared<Veriables>(0));
}

void List_variables::delet_variables_table_last()
{
	this->main_list.pop_front();
}
