#ifndef _CUSTOMER_READER_H
#define _CUSTOMER_READER_H

#include <fstream>

class Customer_Reader {
public:
	bool read_customers();
	bool read_customer_payments();
	bool read_customer_cuisine();
	std::string get_token(std::string&);
};

#endif
