#include "Lexer.h"
#include <iostream> 
#include <string>   
#include "Parser.h"
#include <exception>   
#include "Statement.h"
#include <fstream>


int  main(int argc, char** argv) {

	std::string prog = "";
	std::ifstream filer;      
	filer.open("program2.txt");
	if (!filer.is_open())
	{
		std::cout << "error open file" << std::endl;
		return 0;
	}
	else 
	{
		char ch;
		while (filer.get(ch)) 
		{
			prog.push_back(ch);
		}
	}
	
	
	Lexer first(prog);
	std::vector<Token> PROG_TOKEN = first.tokenize();
	std::list<std::shared_ptr<Statement>> exp;
	Parser par(PROG_TOKEN);
	try {
		exp = par.parse();
	}
	catch (std::exception s) 
	{
		std::cout << s.what() << std::endl;
		return 0;
	}
	
	
	try {
		for (auto&i : exp) {
			(*i).execute(par.get_main_veriables_list());
		}
	}
	catch (std::exception s)
	{
		std::cout << s.what() << std::endl;
	}
	
	return 0;

}

