#pragma once

#ifdef DB_EXPORTS
#define DB_API __declspec(dllexport) 
#else
#define DB_API __declspec(dllimport) 
#endif

#include "Table.h"
#include <sstream>
#include <vector>

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
	enum token { eq, neq, lt, lte, gt, gte, in, exists, and, or, not, lpar, rpar, all, any, field, num };

private:
	std::list<std::string> tableNames;
	std::list<Table> tables;
	std::vector<Token> vectorToken;
};


class Database::Parse {
	struct Token;
	class TokenStream;
public:
	Parse() {};

};


const char attribute = 'a';		// t.kind == attribute means t is attribute
const char op = 'o';			// t.kind == op means t is an operator
const char number = '8';		// t.kind == number means t is a number

struct Database::Parse::Token {
	char kind;
	double value;
	std::string name;
	Token() {}
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string n) :kind(ch), name(n) { }
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
