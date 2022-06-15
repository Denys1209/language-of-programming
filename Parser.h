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
#include "ListValue.h"
#include "StructValue.h"
#include "ListExpression.h"
#include "BoolValue.h"
#include "ReturnStatement.h"
#include "ListExpressionDeclaration.h"
#include "ListAssigmentStatement.h"
#include "ListAccessExpression.h"
#include "ReferenceValue.h"
#include "ReferenceExpression.h"
#include "StructDefineStatement.h"
#include "PointExpression.h"
#include "StructAssigmentStatement.h"
#include "PointAssigmentStatement.h"

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
	std::shared_ptr<Expression> expression();
	std::shared_ptr<Statement> statement();
	std::shared_ptr<Expression> conditional();
	std::shared_ptr<Expression> unary();
	std::shared_ptr<Expression> function();
	std::shared_ptr<Expression> primary();
	std::shared_ptr<Expression> additive();
	std::shared_ptr<Expression> multiplicative();
	std::shared_ptr<Expression> element();
	std::shared_ptr<Expression> point();
	std::shared_ptr<Expression> logicalOr();
	std::shared_ptr<Expression> creatListExpression();
	std::shared_ptr<Expression> logicalAnd();
	std::shared_ptr<Expression> equality();

	std::shared_ptr<Statement> assigmentStatement();
	std::shared_ptr<Statement> ifelse();
	std::shared_ptr<Statement> Whilestatement();
	std::shared_ptr<Statement> Forstatement();
	std::shared_ptr<Statement> block();
	std::shared_ptr<Statement> statementOrBlock();
	std::shared_ptr<Statement> DoWhilestatement();
	std::shared_ptr<Statement> FunctionDefine();
	Token write_current_token_value_type();

public:
	Parser(std::vector<Token> tokens)
	{
		this->tokens = tokens;
		this->size = tokens.size();
		this->pos = 0;
		
	}
	std::list<std::shared_ptr<Statement>> parse();
	
	bool match(Token_type type);
	Token get(int relativePosition);
	Token consume(Token_type type);
	List_variables &get_main_veriables_list() { return *this->main_list_variables; }
};

