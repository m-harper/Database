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
	class Parsed;
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
	int stringToInt(std::string);
	std::string checkNumType(std::string);

	// Parser functions
//	enum token { eq, neq, lt, lte, gt, gte, in, exists, and, or, not, lpar, rpar, all, any, field, num };
	Token getToken(std::string&);
	Parsed parse(std::string);

private:
	std::list<std::string> tableNames;
	std::list<Table> tables;

	// Class for parser ouput
	class Parsed {
	public:
		std::list<std::string> fields;
		std::list<std::string> conditions;
		std::list<double> numbers;
	};

	const char condition = 'c';	// t.kind == condition means that t is a condition Token
	const char number = '8';	// t.kind == number means that t is a number Token
	const char name = 'a';		// t.kind == name means that t is a name Token
	const char boolean = 'b';	// t.kind == boolean means that t is a boolean Token	

	class Token {
	public:
		char kind;			// what kind of token
		bool boolean;
		int value;
		double value;		// for number: a value
		std::string name;	// for name: name itself
		Token(char ch):kind(ch), value(0) {}
		Token(char ch, bool b):kind(ch), boolean(b) {}
		Token(char ch, int val):kind(ch), value(val) {}
		Token(char ch, float val):kind(ch), value(val) {}
		Token(char ch, double val):kind(ch), value(val) {}
		Token(char ch, std::string n):kind(ch), name(n) {}
	};

	std::vector<Token> tokenVector;

/*	class Token_stream {
	public:
		Token_stream();		// make a Token_stream that reads from cin
		Token get();		// get a Token (get() is defined elsewhere)
		void putback(Token t);	// put a Token back
		void ignore(char c);	// discard characters up to and including a c
	private:
		bool full;			// is there a Token in the buffer?
		Token buffer;		// here is where we keep a token put back using putback()
	};		*/

};