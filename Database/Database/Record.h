#pragma once
#include <list>
#include <string>

class Record {

	std::list<std::string> tuple;
public:
	Record();
	Record(const Record &in);
	~Record();

	std::string accessRecordEntry(int entry);
	std::string retrieveRecordEntry(int entry, std::string newEntryValue);
	void modifyRecordEntry(int entry);
};
