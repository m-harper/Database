#ifndef _CUSTOMER_READER_H
#define _CUSTOMER_READER_H

#include <fstream>
#include "Database.h"

class Customer_Reader {
public:
	bool read_customers(Database&);
	bool read_customer_payments(Database&);
	bool read_customer_cuisine(Database&);
	std::string get_token(std::string&);
};

#endif
