#include "Parser.h"

Token Parser::get(int relativePosition)
{
	int position = this->pos + relativePosition;
	if (position >= this->size) return End;
	return tokens[position];
}
bool Parser::match(Token_type type)
{
	Token current = this->get(0);
	if (type != current.getType()) return false;
	pos++;
	return true;

}
Token_type Parser::write_current_token_value_type()
{
	Token current = this->get(0);
	pos++;
	if (current.getType() == Token_type::INT)
	{
		return Token_type::INT;
	}
	else if (current.getType() == Token_type::FLOAT)
	{
		return Token_type::FLOAT;
	}
	else if (current.getType() == Token_type::DOUBLE)
	{
		return Token_type::DOUBLE;
	}
	else if (current.getType() == Token_type::STRING)
	{
		return Token_type::STRING;
	}
	else if (current.getType() == Token_type::LIST)
	{
		return Token_type::LIST;
	}
	else 
	{
		throw std::exception(UNKNOW_THE_TYPE);
	}
}
Token Parser::consume(Token_type type)
{
	Token current = this->get(0);
	if (type != current.getType()) { std::string exp = "Token "+current.getText()+ "doesn't match "; throw std::exception(exp.c_str()); }
	pos++;
	return current;

}
std::shared_ptr<Expression> Parser::function() 
{
	std::string name = consume(Token_type::WORD).getText();
	match(Token_type::LPAREN);
	std::shared_ptr<FunctionExpression> function = std::make_shared<FunctionExpression>(name);
	while (!match(Token_type::RPAREN))
	{
		(*function).AddArgument(this->expression());
		match(Token_type::COMMA);
	}
	return function;

}
std::list<std::shared_ptr<Statement>> Parser::parse()
{
	std::list<std::shared_ptr<Statement>> result;
	while (!match(Token_type::ENDFILLER))
	{
		result.push_back(std::move(statement()));
	}
	
	return result;
}
std::shared_ptr<Statement> Parser::DoWhilestatement()
{
	
	std::shared_ptr<Statement> statement = std::move(this->statementOrBlock());
	consume(Token_type::WHILE);
	std::shared_ptr<Expression> conditional = std::move(this->expression());
	return std::make_shared<DoWhileStatement>(std::move(statement), std::move(conditional));
}

std::shared_ptr<Statement>  Parser::assigmentStatement()
{
	Token current = this->get(0); 
	if (current.getType() == Token_type::LIST && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::LIST);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ)
		{
			consume(Token_type::EQ);
			return std::make_shared<AssigmentStatement>(variable, this->expression());
		}
		else if (this->get(0).getType() == Token_type::LSQUARE_BRACKET)
		{
			
			std::shared_ptr<ListExpression> index = std::make_shared<ListExpression>();
			do {
				consume(Token_type::LSQUARE_BRACKET);
				(*index).push_back(this->expression());
				consume(Token_type::RSQUARE_BRACKET);
			} while (this->get(0).getType() == Token_type::LSQUARE_BRACKET);
			return std::make_shared<AssigmentStatement>(variable, index);
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::move(std::make_shared<ValueExpression>(std::vector<value_ptr>())));
		}
	}
	if (current.getType() == Token_type::REFERENCE && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::REFERENCE);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ) {
			consume(Token_type::EQ);
			std::string val = this->get(0).getText();
			consume(Token_type::WORD);
			return std::make_shared<AssigmentStatement>(variable, std::make_shared<ReferenceExpression>(val));
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::make_shared<ReferenceExpression>(nullptr));
		}
	}
	if (current.getType() == Token_type::INT && this->get(1).getType() == Token_type::WORD)
	{
		
		consume(Token_type::INT);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ)
		{
			consume(Token_type::EQ);
			return std::make_shared<AssigmentStatement>(variable, this->expression());
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::move(std::make_shared<ValueExpression>(int(0))));
		}
	}
	if (current.getType() == Token_type::FLOAT && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::FLOAT);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ)
		{
			consume(Token_type::EQ);
			return std::make_shared<AssigmentStatement>(variable, this->expression());
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::move(std::make_shared<ValueExpression>(float(0))));
		}
	}
	if (current.getType() == Token_type::DOUBLE && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::DOUBLE);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ)
		{
			consume(Token_type::EQ);
			return std::make_shared<AssigmentStatement>(variable, this->expression());
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::move(std::make_shared<ValueExpression>(double(0))));
		}
	}
	if (current.getType() == Token_type::STRING && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::STRING);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		if (this->get(0).getType() == Token_type::EQ)
		{
			consume(Token_type::EQ);
			return std::make_shared<AssigmentStatement>(variable, this->expression());
		}
		else {
			return std::make_shared<AssigmentStatement>(variable, std::move(std::make_shared<ValueExpression>("")));
		}
	}
	if (current.getType() == Token_type::BOOL && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::BOOL);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		consume(Token_type::EQ);
		return std::make_shared<AssigmentStatement>(variable, this->expression());
		
		
	}
	if (current.getType() == Token_type::INPUT && this->get(1).getType() == Token_type::WORD)
	{

		consume(Token_type::INPUT);
		std::string variable = this->get(0).getText();
		consume(Token_type::WORD);
		return std::make_shared<InputStatement>(variable);
	}
	if (this->get(0).getType() == Token_type::WORD && this->get(1).getType() == Token_type::EQ)
	{
		
		consume(Token_type::WORD);
		std::string variable = current.getText();
		consume(Token_type::EQ);
		return std::make_shared<SetValueStatement>(variable, this->expression());
	}
	if (this->get(0).getType() == Token_type::WORD && this->get(1).getType() == Token_type::LSQUARE_BRACKET)
	{

		
	std::string variable = consume(Token_type::WORD).getText();
		std::shared_ptr<ListExpression> index = std::make_shared<ListExpression>();
		do {
			consume(Token_type::LSQUARE_BRACKET);
			(*index).push_back(this->expression());
			consume(Token_type::RSQUARE_BRACKET);
		} while (this->get(0).getType() == Token_type::LSQUARE_BRACKET);
		consume(Token_type::EQ);
		return std::make_shared<ListAssigmentStatement>(variable, index, this->expression());
	}
	
	std::string ex = "Unknow operator assigmentStatement " + current.getText();
	throw std::exception(ex.c_str());
}
std::shared_ptr<Statement>  Parser::block() 
{
	std::shared_ptr<BlockStatement> bloc  = std::move(std::make_shared<BlockStatement>());
	consume(Token_type::LBRACE);
	while (!match(Token_type::RBRACE))
	{
		(*bloc).add(std::move(statement()));
	}
	
	return bloc;
}
std::shared_ptr<Statement>  Parser::Forstatement()
{
	std::shared_ptr<Statement> initialization = std::move(assigmentStatement());
	consume(Token_type::COMMAPOINT);
	std::shared_ptr<Expression> termination = std::move(expression());
	consume(Token_type::COMMAPOINT);
	std::shared_ptr<Statement> increment = std::move(assigmentStatement());
	std::shared_ptr<Statement> block = std::move(statementOrBlock());
	return std::make_shared<ForStatement>(std::move(initialization), std::move(termination), std::move(increment), std::move(block));
}
std::shared_ptr<Statement>  Parser::statementOrBlock()
{
	if (get(0).getType() == Token_type::LBRACE) return block();
	return statement();
}
std::shared_ptr<Statement>  Parser::ifelse()
{
	std::list<std::shared_ptr<Expression>> conditionals;
	std::list<std::shared_ptr<Statement>> ifStatements;
	conditionals.push_back(std::move(this->expression()));
	ifStatements.push_back(std::move(this->statementOrBlock()));
	while (get(0).getType() == Token_type::ELSE && get(1).getType() == Token_type::IF) {
		this->consume(Token_type::ELSE);
		this->consume(Token_type::IF);
		conditionals.push_back(std::move(this->expression()));
		ifStatements.push_back(std::move(this->statementOrBlock()));
	}
	std::shared_ptr<Statement> elseStatement = nullptr;
	if (match(Token_type::ELSE)) {elseStatement = std::move(this->statementOrBlock());}
	return std::make_shared<IfStatement>(std::move(conditionals), std::move(ifStatements), std::move(elseStatement));
	return nullptr;
	
}
std::shared_ptr<Statement>  Parser::Whilestatement()
{
	std::shared_ptr<Expression> conditional = std::move(this->expression());
	std::shared_ptr<Statement> statement = std::move(this->statementOrBlock());
	return std::make_shared<WhileStatement>(std::move(conditional), std::move(statement));
}
std::shared_ptr<Statement>  Parser::FunctionDefine()
{
	std::string name = consume(Token_type::WORD).getText();
	match(Token_type::LPAREN);
	std::vector<std::string> args;
	std::vector<bool> bool_amp;

	while (!match(Token_type::RPAREN))
	{
		if (this->get(0).getType() == Token_type::AMP) { bool_amp.push_back(1); consume(Token_type::AMP); }
		else bool_amp.push_back(0);
		
		args.push_back(consume(Token_type::WORD).getText());
		match(Token_type::COMMA);
	}
	std::shared_ptr<Statement> body = this->statementOrBlock();
	return std::make_shared<FunctionDefineStatement>(std::move(name), std::move(args), std::move(body), this->main_list_variables, bool_amp);
}
std::shared_ptr<Expression> Parser::multiplicative()
{
	std::shared_ptr<Expression> expr = std::move(unary());
	while (true)
	{
		if (match(Token_type::STAR))
		{
			expr = std::make_shared<BinaryExpression>('*', std::move(expr), std::move(unary()));
			continue;

		}
		if (match(Token_type::SLASH))
		{
			expr = std::make_shared<BinaryExpression>('/', std::move(expr), std::move(unary()));
			continue;
		}
		break;
	}
	return expr;
}
std::shared_ptr<Expression> Parser::element()
{
	std::string variable = consume(Token_type::WORD).getText();
	std::shared_ptr<ListExpression> index = std::make_shared<ListExpression>();

	do {
		consume(Token_type::LSQUARE_BRACKET);
		(*index).push_back(this->expression());
		consume(Token_type::RSQUARE_BRACKET);
	} while (this->get(0).getType() == Token_type::LSQUARE_BRACKET);
	return std::make_shared<ListAccessExpression>(variable, index);
	
}
std::shared_ptr<Expression> Parser::logicalOr()
{
	std::shared_ptr<Expression> result = std::move(this->logicalAnd());
	while (true) {
		if (match(Token_type::BARBAR))
		{
			result =  std::move(std::make_shared<ConditionalExpression>("||", std::move(result), std::move(logicalAnd())));
			continue;
		}
		break;
	}
	return result;
}
std::shared_ptr<Expression> Parser::creatListExpression()
{
	std::list<std::shared_ptr<Expression>> list_expression_for_list_value;
	consume(Token_type::LBRACE);
	while (!match(Token_type::RBRACE))
	{
		list_expression_for_list_value.push_back(this->expression());
		match(Token_type::COMMA);
	}
	return std::make_shared<ListExpression>(list_expression_for_list_value);
}
std::shared_ptr<Expression> Parser::logicalAnd()
{
	std::shared_ptr<Expression> result = std::move(this->equality());
	
	while (true) {
		if (match(Token_type::AMPAMP))
		{
			result = std::move(std::make_shared<ConditionalExpression>("&&", std::move(result), std::move(equality())));
			continue;
		}
		break;
	}
	return result;
}
std::shared_ptr<Expression> Parser::equality()
{
	std::shared_ptr<Expression> result = std::move(this->conditional());
	if (match(Token_type::NOEQ))
	{
		 return std::make_shared<ConditionalExpression>("!=", std::move(result), std::move(conditional()));
		
	}
	if (match(Token_type::DEQ))
	{
		return std::make_shared<ConditionalExpression>("==", std::move(result), std::move(conditional()));
		

	}
	return result;
}
std::shared_ptr<Expression> Parser::conditional()
{
	std::shared_ptr<Expression> expr = std::move(additive());
	while (true)
	{
		
		if (match(Token_type::LT))
		{
			expr = std::make_shared<ConditionalExpression>("<", std::move(expr), std::move(additive()));
			continue;
		}
		if (match(Token_type::GT))
		{
			expr = std::make_shared<ConditionalExpression>(">", std::move(expr), std::move(additive()));
			continue;
		}
		if (match(Token_type::LTEQ))
		{
			expr = std::make_shared<ConditionalExpression>("<=", std::move(expr), std::move(additive()));
			continue;
		}
		if (match(Token_type::GTEQ))
		{
			expr = std::make_shared<ConditionalExpression>(">=", std::move(expr), std::move(additive()));
			continue;
		}
		
		break;
	}
	return expr;
}
std::shared_ptr<Expression> Parser::additive()
{
	std::shared_ptr<Expression> expr = std::move(multiplicative());
	while (true)
	{
		if (match(Token_type::PLUS))
		{
			expr = std::make_shared<BinaryExpression>('+', std::move(expr), std::move(multiplicative()));
			continue;

		}
		if (match(Token_type::MINUS))
		{
			expr = std::make_shared<BinaryExpression>('-', std::move(expr), std::move(multiplicative()));
			continue;
		}
		break;
	}
	return expr;
}
std::shared_ptr<Expression> Parser::primary()
{
	Token current = this->get(0);
	if (this->match(Token_type::NUMBER))
	{
		std::string cur = current.getText();
		if (cur.find(".")!= std::string::npos) {
			return std::make_shared<ValueExpression>(this->string_to_double(cur));
		}
		else 
		{
			return std::make_shared<ValueExpression>(std::stoi(cur));
		}
	}
	if (this->get(0).getType() == Token_type::LBRACE) {
		return this->creatListExpression();
	}
	if (this->get(0).getType() == Token_type::WORD && this->get(1).getType() == Token_type::LPAREN)
	{
		return this->function();
	}
	if (this->get(0).getType() == Token_type::WORD && this->get(1).getType() == Token_type::LSQUARE_BRACKET)
	{
	
		return this->element();
	}
	if (this->match(Token_type::WORD))
	{
		
		return std::make_shared<constantExpression>(current.getText());
	}
	
	if (this->match(Token_type::TEXT))
	{
		return std::make_shared<ValueExpression>(current.getText());
	}
	
	if (this->match(Token_type::LPAREN))
	{
		std::shared_ptr<Expression>re = this->expression();
		this->match(Token_type::RPAREN);
		return re;

	}
	
	throw std::exception("unknown expression");
}
std::shared_ptr<Expression> Parser::expression()
{
	return logicalOr();
}


std::shared_ptr<Statement> Parser::statement()
{
	if (match(Token_type::PRINT)) 
	{
		return std::make_shared<PrintStatement>(this->expression());
	}
	if (match(Token_type::IF))
	{
		return this->ifelse();
	}
	if (match(Token_type::BREAK))
	{
		return std::make_shared<BreakStatement>();
	}
	if (match(Token_type::CONTINUE))
	{
		return std::make_shared<ContinueStatement>();
	}
	if (match(Token_type::RETURN))
	{
		return std::make_shared<ReturnStatement>(this->expression());
	}
	if (match(Token_type::DO))
	{
		return this->DoWhilestatement();
	}
	if (match(Token_type::WHILE))
	{
		return this->Whilestatement();
	}
	if (match(Token_type::FOR))
	{
		return this->Forstatement();
	}
	if (match(Token_type::VOID))
	{
		return this->FunctionDefine();
	}
	if (this->get(0).getType() == Token_type::WORD && this->get(1).getType() == Token_type::LPAREN)
	{
		return std::make_shared<FunctionStatement>(this->function());
	}
	return assigmentStatement();
}

std::shared_ptr<Expression> Parser::unary()
{
	if (match(Token_type::MINUS)) 
	{
		return std::make_shared<UnaryExpression>('-', primary());
	}
	return primary();
}