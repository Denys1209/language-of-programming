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
	VOID,
	NONE,

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
	COMMAPOINT,//;
	COMMA,
	ENDFILLER

};