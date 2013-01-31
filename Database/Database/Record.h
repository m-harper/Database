#pragma once
#include <list>
#include <string>

using namespace std;

class Record {

	list<string> tuple;
public:
	Record();
	~Record();

	string accessRecordEntry(int entry);
	void modifyRecordEntry(int entry, string newEntryValue);
	string retrieveRecordEntry(int entry);
};

