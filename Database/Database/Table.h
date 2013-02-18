#pragma once

#include "Record.h"
#include <sstream>

enum Type {INT, FLOAT, string, DATE};

class Table {	
public:
	Table();
	Table(const Table &in);
	Table(std::list<std::string>*, std::list<Type>*);
	Table(std::list<Record>*);
	~Table();

	void addAttribute(std::string name, Type type);
	bool deleteAttribute(std::string name);
	void insertRecord(Record record);
	std::list<std::string>* getAttributes(); // 'returns a std::list of the attributes AND types...' ????
	unsigned int getSize();
	bool renameAttribute(std::string oldName, std::string newName);
	Table crossJoin(Table firstTable, Table secondTable);
	std::list<Record> getRecords() const;
	std::list<std::string> getFields() const;
	std::list<Type> getTypes() const;

	float getSum(std::string attributeName);
	int getCount(std::string attributeName);
	float getMin(std::string attributeName);
	float getMax(std::string attributeName);

private:
	std::list<std::string> fields;
	std::list<Record> records;
	std::list<Type> types; // Used to keep track of the data types of records
};
