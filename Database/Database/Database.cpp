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
		attIndex = 0;
	}

	// We now have the correct table and the indicies of the requested fields
	// We assume that _where is of the form "attribute op value"
	std::string where = _where;
	std::string attribute = where.substr(0, where.find(" "));
	where = where.substr(where.find(" ") + 1);
	std::string opStr = where.substr(0, where.find(" "));
	where = where.substr(where.find(" ") + 1);
	std::string valueString = where;
	double value = stringToDouble(valueString);

	// Convert the op string to a token
	token op;
	if (opStr == "=")
		op = eq;
	if (opStr == "!=")
		op = neq;
	if (opStr == "<")
		op = lt;
	if (opStr == "<=")
		op = lte;
	if (opStr == ">")
		op = gt;
	if (opStr == ">=")
		op = gte;

	// Now we have the needed information
	// Make a new table with the desired qualities
	Table newTable = Table();

	// Add the attributes to the table
	// Get the list of all the attributes of the table
	std::list<std::string> atts = table.getAttributes();
	// Loop to only select attributes the match the wanted indicies
	for (std::list<int>::iterator iit = indices.begin(); iit != indices.end(); iit++) {
		std::string name, fullAtt;
		Table::Type type; 
		std::list<std::string>::iterator it = atts.begin();
		for (int j = 0; j < atts.size(); j++) {
			if (*iit == j) {
				// We match a wanted index
				// Add this attribute to the new table
				fullAtt = *it;
				std::string typeStr = fullAtt.substr(0, fullAtt.find(" "));
				if (typeStr == "0")
					type = Table::INT;
				if (typeStr == "1")
					type = Table::FLOAT;
				if (typeStr == "3")
					type = Table::string;
				if (typeStr == "4")
					type = Table::DATE;

				name = fullAtt.substr(fullAtt.find(" ") + 1);
				newTable.addAttribute(name, type);
			}
			it++;
		}
		// Reset the attribute iterator
		it = atts.begin();
	}

	// All the correct attributes have been added
	// Get the index of the _where attribute in the record/table
	int recInd = 0;
	for (std::list<std::string>::iterator it = table.getAttributes().begin(); it != table.getAttributes().end(); it++) {
		// Split the attribute into type and name, attribute is of form "type name"
		// All we need is name
		std::string name = (*it).substr((*it).find(" ") + 1);
		if (attribute == name) {
			// Found the required attribute
			break;
		}
		recInd++;
	}

	// Now add the records that match the condition
	// Loop through the records of the original table
	for (std::list<Record>::iterator it = table.getRecords().begin(); it != table.getRecords().end(); it++) {
		std::string recordEntry = (*it).retrieveRecordEntry(recInd);
		// Check if the record entry meets the condition
		switch (op) {
		case eq:
			if (recordEntry == valueString) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		case neq:
			if (recordEntry != valueString) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		case lt:
			if (stringToDouble(recordEntry) < stringToDouble(valueString)) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		case lte:
			if (stringToDouble(recordEntry) <= stringToDouble(valueString)) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		case gt:
			if (stringToDouble(recordEntry) > stringToDouble(valueString)) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		case gte:
			if (stringToDouble(recordEntry) >= stringToDouble(valueString)) {
				// Condition met, add record to new table
				// WE PROBABLY NEED TO MATCH UP WITH THE ATTRIBUTES ALREADY IN THE TABLE, LOOK HERE IF SOMETHING BREAKS
				std::list<std::string>* initialValues = new std::list<std::string>();
				initialValues->push_back(recordEntry);
				newTable.insertRecord(Record(initialValues));
				delete initialValues;
			}
			break;
		}
	}


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

