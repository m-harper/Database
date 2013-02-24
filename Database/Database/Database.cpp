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
		else if(vectorString[i] == "="){
			Database::Token t(TOKEN_KIND_OP, eq);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "!="){
			Database::Token t(TOKEN_KIND_OP, neq);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "<"){
			Database::Token t(TOKEN_KIND_OP, lt);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "<="){
			Database::Token t(TOKEN_KIND_OP, lte);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == ">"){
			Database::Token t(TOKEN_KIND_OP, gt);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == ">="){
			Database::Token t(TOKEN_KIND_OP, gte);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "AND"){
			Database::Token t(TOKEN_KIND_LOG, and);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "OR"){
			Database::Token t(TOKEN_KIND_LOG, or);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "NOT"){
			Database::Token t(TOKEN_KIND_LOG, not);
			vectorToken.push_back(t);
		}
		else{
			// attribute token
			Database::Token t(TOKEN_KIND_ATT, vectorString[i]);
			vectorToken.push_back(t);
		}

	}

	// Finally going through records and pulling out the ones where
	// the condition from _where matches.
	std::list<Record> oldRecords = oldTable.getRecords();

	for(std::list<Record>::iterator i = oldRecords.begin(); i != oldRecords.end(); i++){
		Record oldRecord = *i;
		bool result;

		result = doesRecordPass(oldTable.getAttributes(), oldRecord, vectorToken);


		if (result == true)
			newTable.insertRecord(oldRecord);
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

	Table theTable = *it;

	// In the table, delete the record defined by the where statement
	// parsing _where

	// vector for storing word parsed from _where
	std::vector<std::string> vectorString;

	std::string::iterator it1 = _where.begin();

	while(it1 != _where.end()){
		std::string word = "";
		while((it1 != _where.end()) && (*it1 != ' ')){
			word += *it1;
			++it1;
		}
		if(it1 != _where.end()){
			++it1;
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
		else if(vectorString[i] == "="){
			Database::Token t(TOKEN_KIND_OP, eq);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "!="){
			Database::Token t(TOKEN_KIND_OP, neq);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "<"){
			Database::Token t(TOKEN_KIND_OP, lt);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "<="){
			Database::Token t(TOKEN_KIND_OP, lte);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == ">"){
			Database::Token t(TOKEN_KIND_OP, gt);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == ">="){
			Database::Token t(TOKEN_KIND_OP, gte);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "AND"){
			Database::Token t(TOKEN_KIND_LOG, and);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "OR"){
			Database::Token t(TOKEN_KIND_LOG, or);
			vectorToken.push_back(t);
		}
		else if(vectorString[i] == "NOT"){
			Database::Token t(TOKEN_KIND_LOG, not);
			vectorToken.push_back(t);
		}
		else{
			// attribute token
			Database::Token t(TOKEN_KIND_ATT, vectorString[i]);
			vectorToken.push_back(t);
		}
	}

	// Finally going through records and pulling out the ones where
	// the condition from _where matches.
	std::list<Record> theRecords = theTable.getRecords();

	for(std::list<Record>::iterator i = theRecords.begin(); i != theRecords.end(); i++){
		Record theRecord = *i;
		bool result = doesRecordPass(theTable.getAttributes(), theRecord, vectorToken);

		if (result)
			theRecords.erase(i);
	}
}

double Database::stringToDouble(std::string _string) {
	std::stringstream ss(_string);
	double result;
	ss >> result;
	return result;
}

bool Database::doesRecordPass(std::list<std::string> attributes, Record record, std::vector<Token> vectorToken){
	for(int i = 0; i < vectorToken.size(); i++){
		Token token = vectorToken[i];
		std::vector<Token> newVectorToken;
		switch(token.kind) {
		case '(':
			{
				newVectorToken.clear();
				int parenthesisTracker = 0;
				for (int j = i + 1; i < vectorToken.size(); j++) {

					// If there is another opening parenthesis nested within our case.
					if (vectorToken[j].kind == '(') {
						parenthesisTracker++;
						newVectorToken.push_back(vectorToken[j]);
					}
					// If we encounter a closing parenthesis in our case.
					else if (vectorToken[j].kind == ')') {
						parenthesisTracker--;
						// If the closing parenthesis is not nested, execute what's within the parentheisis.
						if (parenthesisTracker == 0) {
							bool result1 = doesRecordPass(attributes, record, newVectorToken);
							j++;
							// If there is more past closing parenthesis
							if (j < vectorToken.size()) {
								Token logicToken = vectorToken[j];
								j++;
								newVectorToken.clear();
								while(j < vectorToken.size()) {
									newVectorToken.push_back(vectorToken[j]);
									j++;
								}
								bool result2 = doesRecordPass(attributes, record, newVectorToken);
								bool finalResult;
								switch (logicToken.op) {
								case token::and:
									finalResult = (result1 && result2);
									break;
								case token::or:
									finalResult = (result1 || result2);
									break;
								}
								return finalResult;							
							} 
							// If not, just return result from parenthesis.
							else {
								return result1;
							}
						}
						// If the closing parenthesis is nested. (parenthesisTracker != 0)
						else
							newVectorToken.push_back(vectorToken[j]);
					}
					// Otherwise, it's any other token
					else {
						vectorToken.push_back(vectorToken[j]);
					}
				}
			}
			break;
		case TOKEN_KIND_ATT:
			{
				int index = 0;
				for (std::list<std::string>::iterator attIter = attributes.begin(); attIter != attributes.end(); attIter++) {
					// Attributes are of the form "type name"
					// Extract the name only
					std::string name = (*attIter).substr((*attIter).find(" ") + 1);
					if (name == token.name) {
						break;
					} else{
						++index;
					}
				}

				std::string recordValue = record.retrieveRecordEntry(index);

				Token tokenOp = vectorToken[i+1];
				Token tokenValue = vectorToken[i+2];

				std::string stringValue = tokenValue.name;

				bool isNum = true;
				double d1 = stringToDouble(recordValue);
				double d2 = stringToDouble(stringValue);
				if(!isdigit(d1) && !isdigit(d2)){
					isNum = false;
				}

				if(isNum){ 
					switch (tokenOp.op) {
					case token::eq:
						return (d1 == d2);
						break;
					case token::neq:
						return (d1 != d2);
						break;
					case token::lt:
						return (d1 < d2);
						break;
					case token::lte:
						return (d1 <= d2);
						break;
					case token::gt:
						return (d1 > d2);
						break;
					case token::gte:
						return (d1 >= d2);
						break;
					default:
						// You shouldn't be here.
						break;
					}
				} else {
					switch (tokenOp.op) {
					case token::eq:
						return (recordValue == stringValue);
						break;
					case token::neq:
						return (recordValue != stringValue);
						break;
					case token::lt:
						return (recordValue < stringValue);
						break;
					case token::lte:
						return (recordValue <= stringValue);
						break;
					case token::gt:
						return (recordValue > stringValue);
						break;
					case token::gte:
						return (recordValue >= stringValue);
						break;
					default:
						// You shouldn't be here.
						break;
					}
				}
			}
			break;
		case TOKEN_KIND_LOG:
			{
				newVectorToken.clear();
				i++;
				Token token = vectorToken[i];
				switch (token.kind) {
				case '(':
					{
						newVectorToken.push_back('(');
						int parenthesisTracker = 1;
						i++;
						while(parenthesisTracker != 0){
							if(vectorToken[i].kind == '(')
								parenthesisTracker++;
							else if(vectorToken[i].kind == ')')
								parenthesisTracker--;
							newVectorToken.push_back(vectorToken[i]);
							i++;
						}
						bool result1 = !doesRecordPass(attributes, record, newVectorToken);

						if (i < vectorToken.size()) {
							Token logicToken = vectorToken[i];
							i++;
							newVectorToken.clear();
							while(i < vectorToken.size()) {
								newVectorToken.push_back(vectorToken[i]);
								i++;
							}
							bool result2 = doesRecordPass(attributes, record, newVectorToken);
							bool finalResult;
							switch (logicToken.op) {
							case token::and:
								finalResult = (result1 && result2);
								break;
							case token::or:
								finalResult = (result1 || result2);
								break;
							}
							return finalResult;							
						} 
						// If not, just return result from parenthesis.
						else {
							return result1;
						}
					}
					break;

				case TOKEN_KIND_ATT:
					{
						newVectorToken.clear();
						newVectorToken.push_back(vectorToken[i]);
						newVectorToken.push_back(vectorToken[i+1]);
						newVectorToken.push_back(vectorToken[i+2]);
						i += 3;
						bool result1 = !doesRecordPass(attributes, record, newVectorToken);

						if (i < vectorToken.size()) {
							Token logicToken = vectorToken[i];
							i++;
							newVectorToken.clear();
							while(i < vectorToken.size()) {
								newVectorToken.push_back(vectorToken[i]);
								i++;
							}
							bool result2 = doesRecordPass(attributes, record, newVectorToken);
							bool finalResult;
							switch (logicToken.op) {
							case token::and:
								finalResult = (result1 && result2);
								break;
							case token::or:
								finalResult = (result1 || result2);
								break;
							}
							return finalResult;							
						} 
						// If not, just return result from parenthesis.
						else {
							return result1;
						}
					}
					break;
				}
			}
			break;
		default:
			break;
		}
	}
}