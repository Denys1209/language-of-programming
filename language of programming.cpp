
#include "Lexer.h"
#include <iostream> 
#include <string>   
#include "Parser.h"
#include <exception>   
#include "Statement.h"




int  main(int argc, char** argv) {

	std::string prog = "w= 2+2 w2 = PI+w";
	Lexer first(prog);
	std::vector<Token> PROG_TOKEN = first.tokenize();
	/*for (auto &i : PROG_TOKEN) 
	{
		std::cout << i.getType() <<i.getText()<<std::endl;
	}*/
	std::vector<std::unique_ptr<Statement>> exp;
	Parser par(PROG_TOKEN);
	try {
		exp = par.parse();
	}
	catch (std::exception s) 
	{
		std::cout << s.what() << std::endl;
	}
	
	for (auto&i : exp) 
	{
		std::cout << (*i).get_str()<<std::endl;
	}
	
	try {
		std::cout << "\n";
		std::cout << "w" << "=" << par.get_main_veriables_list().get("w") << std::endl;
		std::cout << "w2" << "=" << par.get_main_veriables_list().get("w2") << std::endl;
	}
	catch (std::exception s)
	{
		std::cout << s.what() << std::endl;
	}
	
	return 0;

}

