#include "BreakStatement.h"
BreakStatement::BreakStatement() = default;
void BreakStatement::execute(List_variables &main_veriables_list)
{
	throw BREAK_TEXT;
};
std::string BreakStatement::get_str()  { return ""; };
BreakStatement::~BreakStatement() {};