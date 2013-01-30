#pragma once

#include <string>
#include <list>
#include "Table.h"

class Database {
public:
	Database();
	~Database();

	void add_table(std::string, Table);
	Table drop(std::string);
	std::list<std::string>* list_tables();
	std::list<Table>* get_tables();
	// Query function
	// Delete command
};

