#pragma once
#include <list>
#include <string>

class Record {

	std::list<std::string> tuple;
public:
	Record();
	~Record();

	std::string accessRecordEntry(int entry);
	void modifyRecordEntry(int entry, std::string newEntryValue);
	std::string retrieveRecordEntry(int entry);
};