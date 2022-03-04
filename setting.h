#pragma once
#include <map>
#include <string>
#include <exception>
#include "Value.h"
#include "NumberValue.h"
enum Token_type
{
	NUMBER,
	WORD,
	TEXT,



	PRINT,
	PLUS,
	MINUS,
	STAR,
	SLASH,
	LPAREN,//(
	RPAREN,//)
	
	EQ, //=
	ENDFILLER

};
class Veriables {
private:
	std::map<std::string, value_ptr> veriables;
public:
	Veriables() 
	{
		this->veriables.insert(std::pair<std::string, value_ptr>("PI", std::move(std::make_unique<NumberValue>(3.14))));
		this->veriables.insert(std::pair<std::string, value_ptr>("E", std::move(std::make_unique<NumberValue>(2.71828))));
		this->veriables.insert(std::pair<std::string, value_ptr>("GOLDEN_RATIO", std::move(std::make_unique<NumberValue>(1.618))));
		
	}
	bool isExist(std::string key) 
	{	
		if (this->veriables.find(key) == this->veriables.end())
		{	
			return false;
		}
		return true;

	}
	value_ptr get(std::string key){
		if (!this->isExist(key)) {
			std::string exp = "unknow constant " + key;
			throw std::exception(exp.c_str());
		}
		return std::make_unique<NumberValue>((*this->veriables[key]).asDouble());
	}
	void set(std::string name, value_ptr value)
	{
		this->veriables.insert(std::pair<std::string, value_ptr>(name, std::move(value)));
	}
};
