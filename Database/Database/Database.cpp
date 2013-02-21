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

std::list<std::string> Database::getNames() const {
	return tableNames;
}

Table Database::query(std::list<std::string> _tableAttributes, std::string _tableName, std::string _where) {
	
	// Get the index of the requested table
	int tableIndex = 0;
	for (std::list<std::string>::iterator it = tableNames.begin(); it != tableNames.end(); it++) {
		if (*it == _tableName) {
			break;
		}
		tableIndex++;
	}

	// Get the requested table
	std::list<Table>::iterator tit = tables.begin();
	for (int i = 0; i < tableIndex; i++) {
		tit++;
	}
	Table table = *tit;

	// Get the index of the requested attribute in the table
	std::list<int> indices;
	int attIndex = 0;
	for (std::list<std::string>::iterator ait = _tableAttributes.begin(); ait != _tableAttributes.end(); ait++) {
		for (std::list<std::string>::iterator it = table.getFields().begin(); it != table.getFields().end(); it++) {
			if (*ait == *it) {
				indices.push_back(attIndex);
			}
			attIndex++;
		}
		attIndex =0;
	}

	// We now have the correct table and the indicies of the requested fields
	// TODO parse _where to sort fields
	

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

double Database::stringToDouble(std::string _string) {
	std::stringstream ss(_string);
	double result;
	ss >> result;
	return result;
}

