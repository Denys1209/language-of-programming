#pragma once
#include <map>
#include <string>
#include <exception>
enum Token_type
{
	NUMBER,
	PLUS,
	MINUS,
	STAR,
	SLASH,
	LPAREN,//(
	RPAREN,//)
	WORD,
	EQ, //=
	ENDFILLER

};
class Veriables {
private:
	std::map<std::string, double> veriables;
public:
	Veriables() 
	{
		veriables = { {"PI", 3.14}, {"E", 2.71828}, {"GOLDEN_RATIO", 1.618} };
	}
	bool isExist(std::string key) 
	{	
		if (this->veriables.find(key) == this->veriables.end())
		{	
			return false;
		}
		return true;

	}
	double get(std::string key)
	{
		if (!this->isExist(key)) {
			std::string exp = "unknow constant " + key;
			throw std::exception(exp.c_str());
		}
		return this->veriables[key];
	}
	void set(std::string name, double value) 
	{
		this->veriables.insert(std::pair<std::string, double>(name, value));
	}
};
