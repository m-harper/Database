#include "Table.h"

Table::Table() {
}

Table::Table(std::list<std::string>* _field, std::list<Type>* _type) {

}

Table::~Table() {
}

void Table::addAttribute(std::string _name, Type _type) {

}

bool Table::deleteAttribute(std::string _name) {
	return false;
}

void Table::insertRecord(Record _record) {

}

std::list<std::string>* Table::getAttributes() { 
	return NULL;
}

unsigned Table::getSize() {
	return 0;
}

bool Table::renameAttribute(std::string _oldName, std::string _newName) {
	return false;
}

Table Table::crossJoin(Table _firstTable, Table _secondTable) {
	return Table();
}

float Table::getSum(std::string _attributeName) {
	return 0;
}

int Table::getCount(std::string _attributeName) {
	return 0;
}

float Table::getMin(std::string _attributeName) {
	return 0;
}

float Table::getMax(std::string _attributeName) {
	return 0;
}