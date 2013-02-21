#include "Table.h"

using namespace std;

Table::Table() {
	// Intentionally left empty
}

Table::Table(const Table& _table) {
	// Need to copy in records, fields, and types
	// Copy records
	for (list<Record>::iterator it = _table.getRecords().begin(); it != _table.getRecords().end(); it++) {
		records.push_back(*it);
	}

	// Copy fields
	for (list<std::string>::iterator it = _table.getFields().begin(); it != _table.getFields().end(); it++) {
		fields.push_back(*it);
	}

	// Copy types
	for (list<Type>::iterator it = _table.getTypes().begin(); it != _table.getTypes().end(); it++) {
		types.push_back(*it);
	}
}

Table::Table(std::list<std::string>* _field, std::list<Type>* _type) {
	// Here be dragons
	list<Type>::iterator lit = _type->begin();
	for (list<std::string>::iterator it = _field->begin(); it != _field->end(); it++) {
		fields.push_back(*it);
		types.push_back(*lit);

		// Increment the type iterator as well
		lit++;
	}
}

Table::~Table() {
	// Intentionally left empty
}

void Table::addAttribute(std::string _name, Type _type) {
	fields.push_back(_name);
	types.push_back(_type);
}

bool Table::deleteAttribute(std::string _name) {
	bool success = false;
	list<Type>::iterator lit = types.begin();
	for (list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (_name == *it) {
			// Found the correctly named field
			// Remove the field and type
			fields.erase(it);
			types.erase(lit);
			success = true;
			break;
		}
		// Increment the type iterator as well
		lit++;
	}

	return success;
}

void Table::insertRecord(Record _record) {
	records.push_back(_record);
}

std::list<std::string> Table::getAttributes() {
	std::string combined;
	std::list<std::string> attributes;
	std::list<Type>::iterator tit = types.begin();
	for (std::list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		combined = (*tit) + " " + (*it);
		attributes.push_back(combined);

		// Also increment type iterator
		tit++;
	}

	return attributes;
}

unsigned Table::getSize() {
	return records.size();
}

bool Table::renameAttribute(std::string _oldName, std::string _newName) {
	bool success = false;
	for (list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (*it == _oldName) {
			*it = _newName;
			success = true;
			break;
		}
	}
	return success;
}

Table Table::crossJoin(Table _firstTable, Table _secondTable) {
	// Copy constructor takes care of fields and types for both tables
	Table table = Table(_firstTable);
	for (list<Record>::iterator it = _secondTable.getRecords().begin(); it != _secondTable.getRecords().end(); it++) {
		table.insertRecord(*it);
	}
	return table;
}

std::list<Record> Table::getRecords() const {
	return records;
}

std::list<std::string> Table::getFields() const {
	return fields;
}

std::list<Table::Type> Table::getTypes() const {
	return types;
}

float Table::getSum(std::string _attributeName) {
	float sum = 0;

	// Find the position of the field
	int index = 0;
	for (list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (*it == _attributeName) {
			break;
		}
		index++;
	}

	// Sum the data in the records at the correct entry (index)
	for (list<Record>::iterator it = records.begin(); it != records.end(); it++) {
		sum += stringToDouble(it->retrieveRecordEntry(index));
	}
	return sum;
}

int Table::getCount(std::string _attributeName) {
	unsigned count = 0;

	// Find the position of the field
	int index = 0;
	for (list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (*it == _attributeName) {
			break;
		}
		index++;
	}

	for (list<Record>::iterator it = records.begin(); it != records.end(); it++) {
		if ( "" != it->retrieveRecordEntry(index))
			count++;
	}

	return count;
}

float Table::getMin(std::string _attributeName) {
	// First check type to make sure type is numerical
	// Find the index of the attribute (to be able to check type)
	int index = 0;
	for (std::list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (*it == _attributeName) 
			break;
		index++;
	}
	std::list<Type>::iterator it = types.begin(); 
	for (int i = 0; i < index; i++) {
		it++;
	}

	float min = pow(2.0, 32) - 1; // Max 32 bit int. May need to change to 64
	if (*it == INT || *it == FLOAT) {
		// We can get min
		for (std::list<Record>::iterator rit = records.begin(); rit != records.end(); rit++) {
			if (stringToDouble(rit->retrieveRecordEntry(index)) < min)
				min = stringToDouble(rit->retrieveRecordEntry(index));
		}
	}

	return min;
}

float Table::getMax(std::string _attributeName) {
	// First check type to make sure type is numerical
	// Find the index of the attribute (to be able to check type)
	int index = 0;
	for (std::list<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
		if (*it == _attributeName) 
			break;
		index++;
	}
	std::list<Type>::iterator it = types.begin(); 
	for (int i = 0; i < index; i++) {
		it++;
	}

	float max = pow(2.0, 31) + 1; // Min 32 bit int. May need to change to 64
	if (*it == INT || *it == FLOAT) {
		// We can get min
		for (std::list<Record>::iterator rit = records.begin(); rit != records.end(); rit++) {
			if (stringToDouble(rit->retrieveRecordEntry(index)) < max)
				max = stringToDouble(rit->retrieveRecordEntry(index));
		}
	}

	return max;
}

double Table::stringToDouble(std::string _string) {
	stringstream ss(_string);
	double result;
	ss >> result;
	return result;
}