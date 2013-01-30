#pragma once

#include <list>
#include <string>
#include "Record.h"

enum type {INT, FLOAT, STRING, DATE);

class Table {
public:
	Table();
	Table(std::list<std::string>*, std::list<type>*);

	void add(std::string, type);
	bool remove(std::string);
	void insert(Record);
	std::list<std::string> get_attributes();
	unsigned get_size();
	bool rename_attribute(std::string, std::string);
	void specify_key(std::list<std::string>*);
	Table cross_join(Table, Table);
	

	~Table();
};

