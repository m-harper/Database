#pragma once

#ifdef DB_EXPORTS
#define DB_API __declspec(dllexport) 
#else
#define DB_API __declspec(dllimport) 
#endif

#include "Table.h"
#include <sstream>

class DB_API Database {
private:
	class Parse;

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
};

class Database::Parse {
	struct Token;
	class TokenStream;
public:
	Parse() {};

};

struct Database::Parse::Token {
	char kind;
		double value;
		std::string name;
		Token(char ch) :kind(ch), value(0) { }
		Token(char ch, double val) :kind(ch), value(val) { }
		Token(char ch, std::string n) :kind(ch), name(n) { }
};

class Database::Parse::TokenStream {
	bool isFull;
		Token buffer;

	public:
		// Defult constructor
		TokenStream() :isFull(false), buffer(0) { }

		Token get();
		void unget(Token t) { buffer = t; isFull = true; }

		void ignore(char);
};