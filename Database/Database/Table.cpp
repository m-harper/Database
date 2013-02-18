#include "Table.h"

using namespace std;

Table::Table() {
	// Intentionally left empty
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

Table::Table(std::list<Record>* _records) {

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

std::list<std::string>* Table::getAttributes() {
	// TODO
	return NULL;
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
	// TODO
	return Table();
}

std::list<Record> Table::getRecords() const {
	return records;
}

std::list<std::string> Table::getFields() const {
	return fields;
}

std::list<Type> Table::getTypes() const {
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
	// TODO
	return 0;
}

float Table::getMax(std::string _attributeName) {
	// TODO
	return 0;
}

double stringToDouble(std::string _string) {
	stringstream ss(_string);
	double result;
	ss >> result;
	return result;
}