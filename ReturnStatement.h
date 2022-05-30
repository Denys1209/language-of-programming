#pragma once
#include "Statement.h"

class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement>
{
private:
	std::shared_ptr<Expression> exp;
	std::shared_ptr<Value> result;


public:
	ReturnStatement(std::shared_ptr<Expression> exp)
	{
		this->exp = exp;
	};
	 std::shared_ptr<Value> get_result() const {
		return this->result;
	};
	std::shared_ptr<Expression> get_expression() const {
		return this->exp;
	};
	void execute(List_variables &main_veriables_list) override 
	{
		result = (*exp).eval(main_veriables_list);
		throw this->shared_from_this();
	};
	std::string get_str() override { return "return "; };
	~ReturnStatement() {};
};




