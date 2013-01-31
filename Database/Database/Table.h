#pragma once


#include "Record.h"

enum Type {INT, FLOAT, STRING, DATE};

class Table {

	list<Record> records;
public:
	Table();
	Table(list<string>*, list<Type>*);
	~Table();

	void addAttribute(string name, Type type);
	bool deleteAttribute(string name);
	void insertRecord(Record record);
	list<string> getAttributes(); // 'returns a list of the attributes AND types...' ????
	unsigned int getSize();
	bool renameAttribute(string oldName, string newName);
	Table crossJoin(Table firstTable, Table secondTable);
	
	float getSum(string attributeName);
	int getCount(string attributeName);
	float getMin(string attributeName);
	float getMax(string attributeName);
};

