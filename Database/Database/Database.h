#pragma once

#include "Table.h"

class Database {

	std::list<Table> tables;
public:
	Database();
	~Database();

	void addTable(Table table, std::string name);
	void dropTable(std::string tableName);
	std::list<std::string>* listTables();
	std::list<Table>* getTables();
	Table query(std::list<std::string> tableAttributes ,std::string tableName, std::string whereArgument);
	void deleteRecord(std::string tableName, std::string whereArgument);

};

