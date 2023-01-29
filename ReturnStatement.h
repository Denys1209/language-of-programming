#pragma once
#include "Statement.h"

class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement>
{
private:
	std::shared_ptr<Expression> exp;
	std::shared_ptr<Value> result;


public:
	ReturnStatement(std::shared_ptr<Expression> exp);
	std::shared_ptr<Value> get_result() const;
	std::shared_ptr<Expression> get_expression() const;
	void execute(List_variables &main_veriables_list) override;
	std::string get_str() override;
	~ReturnStatement();
};




