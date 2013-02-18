#pragma once

#ifdef DB_EXPORTS
#define DB_API __declspec(dllexport) 
#else
#define DB_API __declspec(dllimport) 
#endif

#include "Table.h"

class DB_API Database {
public:
	Database();
	Database(const Database &in);
	~Database();

	void addTable(Table table, std::string name);
	void dropTable(std::string tableName);
	std::list<std::string> listTables();
	std::list<Table> getTables() const;
	std::list<std::string> getNames() const;
	Table query(std::list<std::string> tableAttributes ,std::string tableName, std::string whereArgument);
	void deleteRecord(std::string tableName, std::string whereArgument);

private:
	std::list<std::string> tableNames;
	std::list<Table> tables;
};