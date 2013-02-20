#pragma once

#ifdef DB_EXPORTS
#define DB_API __declspec(dllexport) 
#else
#define DB_API __declspec(dllimport) 
#endif

#include "Table.h"

class DB_API Database {
private:
	class Parsed;

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

	// Parser functions
	enum token { eq, neq, lt, lte, gt, gte, in, exists, and, or, not, lpar, rpar, all, any, field, num };
	token getToken(std::string&);
	Parsed parse(std::string);

private:
	std::list<std::string> tableNames;
	std::list<Table> tables;

	// Class for parser ouput
	class Parsed {
		std::list<std::string> fields;
		std::list<std::string> conditions;
	};
};