#include "Database.h"

Database::Database() {
}

Database::Database(const Database& _db) {
	// Copy the other database's tables and table names
	std::list<Table> otherTables = _db.getTables();
	std::list<std::string> otherNames = _db.getNames();

	std::list<std::string>::iterator nit = otherNames.begin();
	for (std::list<Table>::iterator it = otherTables.begin(); it != otherTables.end(); it++) {
		addTable(*it, *nit);
		// Also increment name iterator
		nit++;
	}
}


Database::~Database() {
	// Intentionally left blank
}

void Database::addTable(Table _table, std::string _name) {
	tables.push_back(_table);
	tableNames.push_back(_name);
}

void Database::dropTable(std::string _tableName) {
	// Find the index of the name
	int index = 0;
	for (std::list<std::string>::iterator it = tableNames.begin(); it != tableNames.end(); it++) {
		if (*it == _tableName) {
			// Remove the name from the list
			tableNames.erase(it);
			break;
		}
		index++;
	}
	// We now know the index of the table to delete
	std::list<Table>::iterator it = tables.begin();
	for (int i = 0; i < index; i++) {
		it++;
	}
	// The iterator is now pointing to the correct table
	// Remove the table
	tables.erase(it);
}

std::list<std::string> Database::listTables() {
	return tableNames;
}

std::list<Table> Database::getTables() const {
	return tables;
}

Table Database::query(std::list<std::string> _tableAttributes, std::string _tableName, std::string _where) {
	return Table();
}

void Database::deleteRecord(std::string _tableName, std::string _where) {
	// Find the index of the _tableName
	int index = 0;
	for (std::list<std::string>::iterator it = tableNames.begin(); it != tableNames.end(); it++) {
		if (*it == _tableName) {
			break;
		}
		index++;
	}

	// Iterate to the correct index in tables
	std::list<Table>::iterator it = tables.begin();
	for (int i = 0; i < index; i++) {
		it++;
	}

	// In the table, delete the record defined by the where statement
	//TODO parse where
}

/* Parsing requirements:
 *
 *
 *
 *
 */