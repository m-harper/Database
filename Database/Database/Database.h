#pragma once

#ifdef DB_EXPORTS
#define DB_API __declspec(dllexport) 
#else
#define DB_API __declspec(dllimport) 
#endif

#define TOKEN_KIND_OP 'o'
#define TOKEN_KIND_NUM '8'
#define TOKEN_KIND_ATT 'a'
#define TOKEN_KIND_VAL 'v'
#define TOKEN_KIND_LOG 'l'


#include "Table.h"
#include <sstream>
#include <vector>
#include <iostream>

class DB_API Database {
private:
	class Parse;
	class Token;

public:
	Database();
	Database(const Database&);
	~Database();

	void addTable(Table table, std::string name);
	void dropTable(std::string tableName);
	std::list<std::string> listTables();
	std::list<Table> getTables() const;
	std::list<std::string> getNames() const;
	Table query(std::list<std::string> tableAttributes ,std::string tableName, std::string whereArgument);
	void deleteRecord(std::string tableName, std::string whereArgument);

	double stringToDouble(std::string);

	// Parser functions
	enum token { eq, neq, lt, lte, gt, gte, and, or, not};

	std::vector<Token> vectorToken;

	/************************************
	Expression:
		Term
		Expression op Term

	Term:
		Primary
		Term op Primary

	Primary:
		Number
		Attribute
		( Expression )

	************************************/
	bool primary();
	bool term();
	bool expression();
private:
	std::list<std::string> tableNames;
	std::list<Table> tables;
	bool doesRecordPass(std::list<std::string> attributes, Record record, std::vector<Token> vectorToken);
};


/*class Database::Parse {
	class Token;
	class TokenStream;
public:
	Parse() {};

};*/

/*
const char attribute = 'a';		// t.kind == attribute means t is attribute
const char op = 'o';			// t.kind == op means t is an operator
const char number = '8';		// t.kind == number means t is a number
*/
class Database::Token {
public:
	char kind;
	double value;
	std::string name;
	bool check;
	token op;
	Token() {}
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string n) :kind(ch), name(n) { }
	Token(char ch, bool b) :kind(ch), check(b) {}
	Token(char ch, token n) :kind(ch), op(n) {}
};

/*
class Database::Parse::TokenStream {
	bool isFull;
		Token buffer;

	public:
		// Defult constructor
		TokenStream() :isFull(false), buffer(0) { }

		Token get();
		void unget(Token t) { buffer = t; isFull = true; }

		void ignore(char);
};	*/
