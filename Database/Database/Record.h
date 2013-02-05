#pragma once
#include <list>
#include <string>

class Record {
public:
	Record();
	Record(const Record &in);
	~Record();

   std::string accessRecordEntry(int entry);
   void modifyRecordEntry(int entry, std::string newEntryValue);
   std::string retrieveRecordEntry(int entry);

private:
	std::list<std::string> tuple;
};
