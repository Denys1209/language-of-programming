#pragma once
enum Token_type
{
	NUMBER,
	WORD,
	TEXT,
	TYPE,
	INT,
	STRING,
	DOUBLE,
	FLOAT,
	BOOL,
	LIST,
	VOID,
	REFERENCE,
	NONE,
	RETURN,


	PRINT,
	IF,
	ELSE,
	INPUT,
	WHILE,
	FOR,
	BREAK,
	CONTINUE,
	DO,

	PLUS,
	MINUS,
	STAR,
	SLASH,
	LPAREN,//(
	RPAREN,//)

	EQ, //=
	NOEQ, //!=
	LT,//<
	GT,//>
	DEQ,//==
	LTEQ,//<=
	GTEQ,//>=
	BAR,//|
	BARBAR,//||
	AMP,//&
	AMPAMP,//&&
	NO,//!
	LBRACE,//{
	RBRACE,//}
	LSQUARE_BRACKET,//[
	RSQUARE_BRACKET,//]
	COMMAPOINT,//;
	COMMA,
	ENDFILLER

};