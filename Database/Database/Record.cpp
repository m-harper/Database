#include "Record.h"

using namespace std;

Record::Record() {
	// Intentionally left empty
}

Record::Record(const Record &in) {
	// Copy all the entries from the record into my tuple
	for (int i = 0; i < in.getNumEntries(); i++) {
		tuple.push_back(in.retrieveRecordEntry(i));
	}
}

Record::Record(std::list<std::string>* _initialValues) {
	for (list<string>::iterator it = _initialValues->begin(); it != _initialValues->end(); it++) {
		tuple.push_back(*it);
	}
}

Record::~Record() {
	// Intentionally left empty
}

// Returns a pointer to the string in the tuple
std::string* Record::accessRecordEntry(int _entry)  {
	int index = 0;
	for (list<string>::iterator it = tuple.begin();	it != tuple.end();	it++) {
		if (index == _entry){
			return &(*it);
		}
		index++;
	}
	return NULL;
}

// Changes an entry in the tuple at index _entry to _newEntryValue
void Record::modifyRecordEntry(int _entry, std::string _newEntryValue) {
	string* str = accessRecordEntry(_entry);

	// Exit if the entry was not found or is out of bounds
	if (str == NULL)
		return;

	// Assign the new value
	*str = _newEntryValue;
}

// Returns the string of an entry in the tuple
std::string Record::retrieveRecordEntry(int _entry) const {
	int index = 0;
	for (list<string>::const_iterator it = tuple.begin(); it != tuple.end(); it++) {
		if (index == _entry) {
			return *it;
		}
		index++;
	}

	// Return null if entry not found
	return NULL;
}

// Returns the number of entries in the tuple
unsigned Record::getNumEntries() const {
	return tuple.size();
}

