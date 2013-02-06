#pragma once
#include <list>
#include <string>

/*  
	You should have a separate record class that is used to store an individual record (tuple).  
	A record should consist of an ordered set of strings.  Note that the record should be strings, 
	though those strings might represent an integer, floating point number, date, or time.   
	That is, a record on its own has no “knowledge” of what its entries mean, but sees them all 
	as strings.  Note that strings can be implemented as character arrays or using the string class.  
	Also, how the record itself is implemented is up to you (e.g. it could be an array, it could 
	be a container).  The routines that need to be provided for records include:
		A constructor that allows creation and initialization of an arbitrary number of entries
        An accessor that allows access to an individual entry in the record
        Routines (if not provided by the accessor) for modifying (by specifying a new string) 
			and retrieving (as a string) an entry in the record.
*/

class Record {
public:
	Record();
	Record(const Record &in);
	Record(int _entries, std::list<std::string>* _initialValues);
	~Record();

   std::string* accessRecordEntry(int entry);
   void modifyRecordEntry(int entry, std::string newEntryValue);
   std::string retrieveRecordEntry(int entry) const;
   unsigned getNumEntries() const;
   
private:
	std::list<std::string> tuple;
};
