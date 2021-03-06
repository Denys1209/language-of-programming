#pragma once
#include "Statement.h"
#include <vector>
class BlockStatement :
	public Statement
{
private:
	std::vector<std::shared_ptr<Statement>> lis;
public:
	BlockStatement() = default;

	void add(std::shared_ptr<Statement> statement) 
	{
		
		this->lis.push_back(std::move(statement));

	}
	void execute(List_variables &main_veriables_list) override
	{
		main_veriables_list.add_variables_table();
		try {
			for (auto &i : this->lis)
			{
				(*i).execute(main_veriables_list);
			}
		}
		catch (const char*exc) {
			main_veriables_list.delet_variables_table_last();
			throw exc;
		}
		catch (std::exception exc) {
			main_veriables_list.delet_variables_table_last();
			throw exc;
		}
		main_veriables_list.delet_variables_table_last();
	};
	std::string get_str() override { return ""; };
	~BlockStatement() {};
};

