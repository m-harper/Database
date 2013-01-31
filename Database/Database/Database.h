#pragma once

#include "Table.h"

class Database {

	list<Table> tables;
public:
	Database();
	~Database();

	void addTable(Table table, string name);
	void dropTable(string tableName);
	list<string>* listTables();
	list<Table>* getTables();
	Table query(list<string> tableAttributes ,string tableName, string whereArgument);
	void deleteRecord(string tableName, string whereArgument);

};

