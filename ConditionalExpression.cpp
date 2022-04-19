#include "ConditionalExpression.h"

bool ConditionalExpression::compareString(std::string val1, std::string val2) 
{
	if (this->operation == "==") {
		return val1 == val2;
	}
	else if (this->operation == "!=") {
		return val1 != val2;
	}
	else {
		throw std::exception("unkow operation Conditional string");

	}
}
bool ConditionalExpression::compareInt(int val1, int val2) 
{
	if (this->operation == "==") {
		return val1 == val2;
	}
	else if (this->operation == "<") {
		return val1 < val2;
	}
	else if (this->operation == ">") {
		return val1 > val2;
	}
	else if (this->operation == ">=") {
		return val1 >= val2;
	}
	else if (this->operation == "<=") {
		return val1 <= val2;
	}
	else if (this->operation == "!=") {
		return val1 != val2;
	}
	else {
		throw std::exception("unkow operation Conditional int");

	}
}
bool ConditionalExpression::compareDouble(double val1, double val2) 
{
	if (this->operation == "==") {
		return val1 == val2;
	}
	else if (this->operation == "<") {
		return val1 < val2;
	}
	else if (this->operation == ">") {
		return val1 > val2;
	}
	else if (this->operation == ">=") {
		return val1 >= val2;
	}
	else if (this->operation == "<=") {
		return val1 <= val2;
	}
	else if (this->operation == "!=") {
		return val1 != val2;
	}
	else {
		throw std::exception("unkow operation Conditional double");

	}
}
bool ConditionalExpression::compareFloat(float val1, float val2) 
{
	if (this->operation == "==") {
		return val1 == val2;
	}
	else if (this->operation == "<") {
		return val1 < val2;
	}
	else if (this->operation == ">") {
		return val1 > val2;
	}
	else if (this->operation == ">=") {
		return val1 >= val2;
	}
	else if (this->operation == "<=") {
		return val1 <= val2;
	}
	else if (this->operation == "!=") {
		return val1 != val2;
	}
	else {
		throw std::exception("unkow operation Conditional float");

	}
}
bool ConditionalExpression::compareBool(bool val1, bool val2) 
{
	if (this->operation == "==") {
		return val1 == val2;
	}
	else if (this->operation == "!=") {
		return val1 != val2;
	}
	else if (this->operation == "||") {
		return val1 || val2;
	}
	else if (this->operation == "&&") {
		return val1 && val2;
	}
	else {
		throw std::exception("unkow operation Conditional bool");

	}
}
value_ptr ConditionalExpression::eval(List_variables &main_veriables_list)
{
	value_ptr val1 = std::move((*expr1).eval(main_veriables_list));
	value_ptr val2 = std::move((*expr2).eval(main_veriables_list));
	if ((*val1).getType() == Token_type::STRING && (*val2).getType() == Token_type::STRING)
	{
		return std::make_unique<BoolValue>(compareString((*val1).asString(), (*val2).asString()));
	}
	else if ((*val1).getType() == Token_type::FLOAT && (*val2).getType() == Token_type::FLOAT)
	{
		return std::make_unique<BoolValue>(compareFloat((*val1).asFloat(), (*val2).asFloat()));
	}
	else if ((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::INT)
	{
		return std::make_unique<BoolValue>(compareInt((*val1).asInt(), (*val2).asInt()));
	}
	else if ((*val1).getType() == Token_type::DOUBLE && (*val2).getType() == Token_type::DOUBLE)
	{
		return std::make_unique<BoolValue>(compareDouble((*val1).asDouble(), (*val2).asDouble()));
	}
	else if ((*val1).getType() == Token_type::BOOL && (*val2).getType() == Token_type::BOOL)
	{
		return std::make_unique<BoolValue>(compareBool((*val1).asBool(), (*val2).asBool()));
	}
	else if (((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::FLOAT) || ((*val2).getType() == Token_type::INT && (*val1).getType() == Token_type::FLOAT))
	{
		return std::make_unique<BoolValue>(compareFloat((*val1).asFloat(), (*val2).asFloat()));
	}
	else if (((*val1).getType() == Token_type::INT && (*val2).getType() == Token_type::DOUBLE) || ((*val2).getType() == Token_type::INT && (*val1).getType() == Token_type::DOUBLE))
	{
		return std::make_unique<BoolValue>(compareDouble((*val1).asDouble(), (*val2).asDouble()));
	}
	else
	{
		return std::make_unique<BoolValue>(compareBool((*val1).asBool(), (*val2).asBool()));
	}
}