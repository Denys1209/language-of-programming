#pragma once
#include "Token.h"
#include <vector>
#include "ValueExpression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "constantExpression.h"
#include "Expression.h"
#include "AssigmentStatement.h"
#include <sstream>
#include <exception>
#include "PrintStatement.h"
#include "ConditionalExpression.h"
#include "IfStatement.h"
#include "BlockStatement.h"
#include <list>
#include "InputStatement.h"
#include "WhileStatement.h"
#include "ForStatement.h"
#include "ContinueStatement.h"
#include "BreakStatement.h"
#include "DoWhileStatement.h"
#include "FunctionExpression.h"
#include "FunctionStatement.h"
#include "SetValueStatement.h"
#include "FunctionDefineStatement.h"
#include "SystemFunction.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "DoubleValue.h"
#include "StringValue.h"
#include "BoolValue.h"



class Parser
{
private:
	std::vector<Token> tokens;
	int size;
	int pos;
	Token End = Token(Token_type::ENDFILLER, "");
	std::shared_ptr<List_variables> main_list_variables = std::make_shared<List_variables>();
	
	double string_to_double(std::string s)
	{
		
		return std::stod(s);
	}
	std::unique_ptr<Expression> expression();
	std::unique_ptr<Statement> statement();
	std::unique_ptr<Expression> conditional();
	std::unique_ptr<Expression> unary();
	std::unique_ptr<Expression> function();
	std::unique_ptr<Expression> primary();
	std::unique_ptr<Expression> additive();
	std::unique_ptr<Expression> multiplicative();
	std::unique_ptr<Statement> assigmentStatement();
	std::unique_ptr<Statement> ifelse();
	std::unique_ptr<Statement> Whilestatement();
	std::unique_ptr<Statement> Forstatement();
	std::unique_ptr<Expression> logicalOr();
	std::unique_ptr<Expression> logicalAnd();
	std::unique_ptr<Expression> equality();
	std::unique_ptr<Statement> block();
	std::unique_ptr<Statement> statementOrBlock();
	std::unique_ptr<Statement> DoWhilestatement();
	std::unique_ptr<Statement> FunctionDefine();
	Token_type write_current_token_value_type();

public:
	Parser(std::vector<Token> tokens)
	{
		this->tokens = tokens;
		this->size = tokens.size();
		this->pos = 0;
		
	}
	std::list<std::unique_ptr<Statement>> parse();
	
	bool match(Token_type type);
	Token get(int relativePosition);
	Token consume(Token_type type);
	List_variables &get_main_veriables_list() { return *this->main_list_variables; }
};

