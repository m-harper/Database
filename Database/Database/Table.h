#pragma once

#include "Record.h"

enum Type {INT, FLOAT, string, DATE};

class Table {

	std::list<Record> records;
public:
	Table();
	Table(const Table &in);
	Table(std::list<std::string>*, std::list<Type>*);
	~Table();

	void addAttribute(std::string name, Type type);
	bool deleteAttribute(std::string name);
	void insertRecord(Record record);
	std::list<std::string>* getAttributes(); // 'returns a std::list of the attributes AND types...' ????
	unsigned int getSize();
	bool renameAttribute(std::string oldName, std::string newName);
	Table crossJoin(Table firstTable, Table secondTable);

	float getSum(std::string attributeName);
	int getCount(std::string attributeName);
	float getMin(std::string attributeName);
	float getMax(std::string attributeName);
};
