#include "BinaryExpression.h"
std::unique_ptr<IntValue> BinaryExpression::BinaryInt(int val1, int val2) 
{
	switch (this->operation)
	{
	case '+':
		return std::make_unique<IntValue>(val1 + val2);
	case '-':
		return std::make_unique<IntValue>(val1 - val2);
	case '*':
		return std::make_unique<IntValue>(val1 * val2);
	case '/':
		return std::make_unique<IntValue>(val1 / val2);
	default:
		throw std::exception("unkow operation");
	}
}
std::unique_ptr<DoubleValue> BinaryExpression::BinaryDouble(double val1, double val2)
{
	switch (this->operation)
	{
	case '+':
		return std::make_unique<DoubleValue>(val1 + val2);
	case '-':
		return std::make_unique<DoubleValue>(val1 - val2);
	case '*':
		return std::make_unique<DoubleValue>(val1 * val2);
	case '/':
		return std::make_unique<DoubleValue>(val1 / val2);
	default:
		throw std::exception("unkow operation");
	}
}
std::unique_ptr<FloatValue> BinaryExpression::BinaryFloat(float val1, float val2)
{
	switch (this->operation)
	{
	case '+':
		return std::make_unique<FloatValue>(val1 + val2);
	case '-':
		return std::make_unique<FloatValue>(val1 - val2);
	case '*':
		return std::make_unique<FloatValue>(val1 * val2);
	case '/':
		return std::make_unique<FloatValue>(val1 / val2);
	default:
		throw std::exception("unkow operation");
	}
}
std::unique_ptr<StringValue> BinaryExpression::BinaryString(value_ptr val1, value_ptr val2)
{
	if (operation == '+') {

		return std::make_unique<StringValue>((*val1).asString() + (*val2).asString());

	}
	else if (operation == '*') {
		std::string str;
		int iteration;
		if ((*val2).is_string()) {
			iteration = (*val1).asInt();
			str = std::move((*val2).asString());
		}
		else
		{
			iteration = (*val2).asInt();
			str = std::move((*val1).asString());
		}
		std::string buffer = "";
		for (int i = 0; i < iteration; ++i)
		{
			buffer += str;
		}
		return std::make_unique<StringValue>(buffer);
	}
	else {
		throw std::exception("unkow operation");
	}
}