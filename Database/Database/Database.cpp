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

/* 
	Parsing requirements:
	Query:
	The query command should be a member function from the database.  It will return a table.  The query command should take in three arguments, a SELECT argument, a FROM argument, and a WHERE argument.  These three arguments should have the following properties
	In the SELECT argument, allow either
	A list of which attributes names to keep (the type should remain the same)
	An indicator (analogous to the * in SQL) to keep all attributes.  You can do this however you want (e.g. a null list of attributes might indicate keep all)
	In the FROM argument
	A single table name
	In the WHERE argument, references to the attribute names.
	Comparisons of =, !=, >, <, >=, <=  (only between attributes/values of the same type)
	* An IN operator (given the name of a table with only one attribute)
	* An EXISTS operator (given the name of a table with only one attribute)
	AND, OR, and NOT
	Parentheses.  Note that no more than 3 levels of parentheses need to be supported
	* Support for arbitrary nesting of parentheses
	* ALL (given the name of a table with only one attribute)
	* ANY  (given the name of a table with only one attribute)
	Note that the WHERE clause will require parsing.  The WHERE argument should be passed in as a string
 */



Database::token Database::getToken(std::string& _where) {
	// First check for parenthesis
	if (_where[0] == '(') {
		_where = _where.substr(1);
		return lpar;
	}
	if (_where[0] == ')') {
		_where = _where.substr(1);
		return rpar;
	}
	
	// Get a token from the string up to the first space
	std::string piece = _where.substr(0, _where.find(" "));

	if (piece == "=") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return eq;
	}
	if (piece == "!=") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return neq;
	}
	if (piece == "<") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return lt;
	}
	if (piece == "<=") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return lte;
	}
	if (piece == ">") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return gt;
	}
	if (piece == ">=") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return gte;
	}
	if (piece == "IN") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return in;
	}
	if (piece == "EXISTS") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return exists;
	}
	if (piece == "AND") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return and;
	}
	if (piece == "OR") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return or;
	}
	if (piece == "NOT") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return not;
	}
	if (piece == "ALL") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return all;
	}
	if (piece == "ANY") {
		// Remove the token from the string
		_where = _where.substr(_where.find(" "));
		return any;
	}
	
	// Check if the piece is a number
	bool isNum = true;
	for (int i = 0; i < piece.length(); i++) {
		if (!isdigit(piece[i]) && piece[i] != '.') {
			isNum = false;
			break;
		}
	}
	
	if (isNum) {
		return num;
	}

	// Everything else has been exhausted, token must be the name of a field
	return field;
}

Database::Parsed Database::parse(std::string _where) {
	Parsed parsed;

	while (_where != "") {
		switch (getToken(_where)) {
		case field:
			// Remove the field from the string
			break;
		case num:
			// Remove the num from the string
			break;
		// For all other cases, token has already been removed

		}
	}
}