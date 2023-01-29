#include "ContinueStatement.h"

ContinueStatement::ContinueStatement() = default;
void ContinueStatement::execute(List_variables &main_veriables_list)
{
	throw CONTINUE_TEXT;
};
std::string ContinueStatement::get_str()  { return ""; };
ContinueStatement::~ContinueStatement() {};