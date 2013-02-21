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
	
	// Access the old table based on _tableName
	Table oldTable;
	std::list<Table>::iterator tableIterator = tables.begin();
	for (std::list<std::string>::iterator nameIterator = tableNames.begin(); nameIterator != tableNames.end(); nameIterator++) {
		if (_tableName == *nameIterator)
			break;
		// Also increment table iterator
		tableIterator++;
	}
	oldTable = *tableIterator;

	// Construct a new table with the needs attributes based on _tableAttributes
	Table newTable;

	// Get attributes needed for new table
	std::list<std::list<std::string>::iterator> neededAttributes;
	for (std::list<std::string>::iterator paramIter = _tableAttributes.begin(); paramIter != _tableAttributes.end(); paramIter++) {
		std::list<std::string> attributes = oldTable.getAttributes();
		for (std::list<std::string>::iterator attIter = attributes.begin(); attIter != attributes.end(); attIter++) {
			// Attributes are of the form "type name"
			// Extract the name only
			std::string name = (*attIter).substr((*attIter).find(" ") + 1);
			if (name == *paramIter) {
				neededAttributes.push_back(attIter);
			}
		}
	}

	// Add attributes to new table
	for (std::list<std::list<std::string>::iterator>::iterator it = neededAttributes.begin(); it != neededAttributes.end(); it++) {
		std::string attribute = **it;
		// Attribute is of form "type name"
		// Break the string into type and name
		std::string typeStr = attribute.substr(0, attribute.find(" "));
		Table::Type type;
		if (typeStr == "0")
			type = Table::INT;
		if (typeStr == "1")
			type = Table::FLOAT;
		if (typeStr == "2")
			type = Table::string;
		if (typeStr == "3")
			type = Table::DATE;

		std::string name = attribute.substr(attribute.find(" ") + 1);

		// Add the attribute to the new table
		newTable.addAttribute(name, type);
	}

	// New table is correctly constructed
	// Loop through records of old table and extract records whose condition matches
	// First, get the entry number of the attribute in the record
	// TODO
	
	// parsing _where

	// vector for storing word parsed from _where
	std::vector<std::string> vectorString;

	std::string::iterator it = _where.begin();

	while(it != _where.end()){
		std::string word = "";
		while((it != _where.end()) && (*it != ' ')){
			word += *it;
			++it;
		}
		if(it != _where.end()){
			++it;
		}
		vectorString.push_back(word);
	}

	// Convert from word to Token
	for(int i = 0; i < vectorString.size(); i++){
		
		// parentheses
		if(vectorString[i] == "(")
			vectorToken.push_back('(');
		else if(vectorString[i] == ")")
			vectorToken.push_back(')');

		// op Token
		else if(vectorString[i] == "=")
			vectorToken.push_back('o', eq);
		else if(vectorString[i] == "!=")
			vectorToken.push_back('o', neq);
		else if(vectorString[i] == "<")
			vectorToken.push_back('o', lt);
		else if(vectorString[i] == "<=")
			vectorToken.push_back('o', lte);
		else if(vectorString[i] == ">")
			vectorToken.push_back('o', gt);
		else if(vectorString[i] == ">=")
			vectorToken.push_back('o', gte);
		else if(vectorString[i] == "AND")
			vectorToken.push_back('o', and);
		else if(vectorString[i] == "OR")
			vectorToken.push_back('o', or);
		else if(vectorString[i] == "NOT")
			vectorToken.push_back('o', not);

		// number token
		else if(isdigit(vectorString[i])){
			double d = stringToDouble(vectorString[i]);
			vectorToken.push_back('8', d);
		}

		// attribute token
		else{
			vectorToken.push_back('a', vectorString[i]);
		}
	}

	/*	std::string attName = // attribute name from _where
		int index = 0;
		for (std::list<std::string>::iterator it = oldTable.getAttributes().begin(); it != oldTable.getAttributes().end(); it++) {
			// Attributes are of the form "type name"
			// Extract the name only
			std::string name = (*it).substr((*it).find(" ") + 1);
			if (name == attName) {
				// Found the correct entry number
				break;
			}
			index++;
		}
	
		// The operation from _where is stored in a token called op
		Token op; // TODO assign based on parsing

		// Now we know the entry number, begin comparing to condition from _where
		for (std::list<Record>::iterator recordIter = oldTable.getRecords().begin(); recordIter != oldTable.getRecords.end(); recordIter++) {
			std::string entry = (*recordIter).retrieveRecordEntry(index);
			switch (op) {
			case eq:
				if (entry == // TODO value from where) {

				}
				break;
			case neq:
				if (entry != // TODO value from where) {

				}
				break;
			case lt:
				if (stringToDouble(entry) < stringToDouble(// TODO value from where)) {

				}
				break;
			case lte:
				if (stringToDouble(entry) <= stringToDouble(// TODO value from where)) {

				}
				break;
			case gt:
				if (stringToDouble(entry) > stringToDouble(// TODO value from where)) {

				}
				break;
			case gte:
				if (stringToDouble(entry) >= stringToDouble(// TODO value from where)) {

				}
				break;
			}
		}
		*/
	

	return newTable;
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

