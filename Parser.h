#pragma once
#include "Token.h"
#include <vector>
#include "NumberExpression.h"
#include "BinaryExpression.h"
#include "constantExpression.h"
#include "AssigmentStatement.h"
#include <sstream>
#include <exception>

class Parser
{
private:
	std::vector<Token> tokens;
	int size;
	int pos;
	Token End = Token(Token_type::ENDFILLER, "");
	Veriables main_veriables_list;
	double string_to_int(std::string s) 
	{
		double d;
		std::stringstream str;

		str << s;
		str >> d;
		return d;
	}
	std::unique_ptr<Expression> expression()
	{
		return additive();
	}
	std::unique_ptr<Statement> statement()
	{
		return assigmentStatement();
	}
	std::unique_ptr<Expression> unary()
	{
		return primary();
	}
	std::unique_ptr<Expression> primary();
	std::unique_ptr<Expression> additive();
	std::unique_ptr<Expression> multiplicative();
	std::unique_ptr<Statement> assigmentStatement();
public:
	Parser(std::vector<Token> tokens)
	{
		this->tokens = tokens;
		this->size = tokens.size();
		this->pos = 0;
		
	}
	std::vector<std::unique_ptr<Statement>> parse();
	
	bool match(Token_type type);
	Token get(int relativePosition);
	Token consume(Token_type type);
	Veriables &get_main_veriables_list() { return this->main_veriables_list; }
};

