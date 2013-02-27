#ifndef _RESTAURANT_READER_H
#define _RESTAURANT_READER_H

#include <fstream>
#include "Database.h"

class Restaurant_Reader {
public:
	bool read_restaurant_accepts(Database&);
	bool read_all(Database&);
	bool read_one(const char* file_name, std::string table_name, Database&);
	std::string get_token(std::string&);
};


#endif