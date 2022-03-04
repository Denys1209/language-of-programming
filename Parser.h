#pragma once
#include "Token.h"
#include <vector>
#include "ValueExpression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "constantExpression.h"
#include "AssigmentStatement.h"
#include <sstream>
#include <exception>
#include "PrintStatement.h"
class Parser
{
private:
	std::vector<Token> tokens;
	int size;
	int pos;
	Token End = Token(Token_type::ENDFILLER, "");
	Veriables main_veriables_list;
	double string_to_double(std::string s) 
	{
		
		return std::stod(s);
	}
	std::unique_ptr<Expression> expression();
	std::unique_ptr<Statement> statement();
	std::unique_ptr<Expression> unary();
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

