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
Token Parser::consume(Token_type type)
{
	Token current = this->get(0);
	if (type != current.getType()) { std::string exp = "Token "+current.getText()+ "doesn't match "; throw std::exception(exp.c_str()); }
	pos++;
	return current;

}
std::vector<std::unique_ptr<Statement>> Parser::parse()
{
	std::vector<std::unique_ptr<Statement>> result;
	while (!match(Token_type::ENDFILLER))
	{
		result.push_back(std::move(statement()));
	}
	for (auto&i : result)
	{
		(*i).execute(this->main_veriables_list);
	}
	return result;
}
std::unique_ptr<Statement> Parser::assigmentStatement()
{
	Token current = this->get(0);
	if (current.getType() == Token_type::WORD && this->get(1).getType() == Token_type::EQ)
	{
		consume(Token_type::WORD);
		std::string variable = current.getText();
		consume(Token_type::EQ);
		return std::make_unique<AssigmentStatement>(variable, this->expression());
	}
	throw std::exception("Unknow operator");
}

std::unique_ptr<Expression> Parser::multiplicative()
{
	std::unique_ptr<Expression> expr = std::move(unary());
	while (true)
	{
		if (match(Token_type::STAR))
		{
			expr = std::make_unique<BinaryExpression>('*', std::move(expr), std::move(unary()));
			continue;

		}
		if (match(Token_type::SLASH))
		{
			expr = std::make_unique<BinaryExpression>('/', std::move(expr), std::move(unary()));
			continue;
		}
		break;
	}
	return expr;
}
std::unique_ptr<Expression> Parser::additive()
{
	std::unique_ptr<Expression> expr = std::move(multiplicative());
	while (true)
	{
		if (match(Token_type::PLUS))
		{
			expr = std::make_unique<BinaryExpression>('+', std::move(expr), std::move(multiplicative()));
			continue;

		}
		if (match(Token_type::MINUS))
		{
			expr = std::make_unique<BinaryExpression>('-', std::move(expr), std::move(multiplicative()));
			continue;
		}
		break;
	}
	return expr;
}
std::unique_ptr<Expression> Parser::primary()
{
	Token current = this->get(0);
	if (this->match(Token_type::NUMBER))
	{
		return std::make_unique<NumberExpression>(this->string_to_int(current.getText()));
	}
	if (this->match(Token_type::WORD))
	{
		return std::make_unique<constantExpression>(current.getText());
	}
	if (this->match(Token_type::LPAREN))
	{
		std::unique_ptr<Expression>re = this->expression();
		this->match(Token_type::RPAREN);
		return re;

	}
	
	throw std::exception("unknown expression");
}