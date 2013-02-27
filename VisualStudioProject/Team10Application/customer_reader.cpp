#include "customer_reader.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool Customer_Reader::read_customers(Database& _db) {
	const char* file_name = "data/userprofile.txt";

	// Open the file
	cout << "Attempting to open " << file_name << "...";

	ifstream users;
	users.open(file_name);
	if (users.is_open()) {
		cout << " Success!\n";
	}
	else {
		cout << " Error, unable to open file\n";
		return false;
	}

	// File has successfully been opened
	// Read in a line
	// The first line is the attributes for the table
	string attributes;
	getline(users, attributes);

	Table customers;

	string token = get_token(attributes);
	while (token != "") {
		customers.addAttribute(token, AttributeList::STRING);
		cout << token << endl;
		token = get_token(attributes);
	}

	// Read in the customers' data
	string customer;
	string info_token;

	// Loop over all of the customers
	while (true) {
		getline(users, customer);
		if (customer == "") {
			break;
		}
		vector<string> rec_vec;
		while (true) {
			// Get a token of info from the customer string
			info_token = get_token(customer);
			if (info_token == "")
				break;
			cout << info_token << '\t';
			// Add the info to a vector to initialize the record with
			rec_vec.push_back(info_token);
		}
		// Create a record
		Record record = Record(rec_vec);
		// Add the created record to the table
		customers.insert(record);
		cout << '\n';
	}
	// There should be EXACTLY 138 customers
	assert(customers.getSize() == 138);
	
	// Add the table to the database
	_db.addTable(customers, "Customers");

	users.close();
	return true;
}

bool Customer_Reader::read_customer_payments(Database& _db) {
	const char* file_name = "data/userpayment.txt";

	cout << "Attempting to open " << file_name << "...";

	// Open the file
	ifstream payments;
	payments.open(file_name);

	if (payments.is_open()) {
		cout << " Success!\n";
	}
	else {
		cout << " Error, unable to open file\n";
		return false;
	}

	// File has been successfully opened
	// Add attributes to the table
	Table table;
	string atts;
	getline(payments, atts);

	// Tokenize the attributes
	string attribute = get_token(atts);
	while (attribute != "") {
		table.addAttribute(attribute, AttributeList::STRING);
		cout << attribute << endl;
		attribute = get_token(atts);
	}

	// Loop through the payment info
	string pay, token;
	vector<string> rec_vec;
	while (true) {
		getline(payments, pay);
		if (pay == "") {
			break;
		}
		while (true) {
			token = get_token(pay);
			if (token == "") {
				break;
			}
			rec_vec.push_back(token);
			cout << token << '\t';
		}
		cout << endl;
		Record record = Record(rec_vec);
		// Add the record to the table
		table.insert(record);
	}
	// The table should have EXACTLY 138 records
	assert(table.getSize() == 138);
	// Add the table to the database
	_db.addTable(table, "Customer Payments");
	
	payments.close();
	return true;
}

bool Customer_Reader::read_customer_cuisine(Database& _db) {
	const char* file_name = "data/usercuisine.txt";
	
	cout << "Attempting to open " << file_name << "...";

	// Open the file
	ifstream infile;
	infile.open(file_name);

	if (infile.is_open()) {
		cout << " Success!\n";
	}
	else {
		cout << " Error, unable to open file\n";
		return false;
	}
	
	// File has been successfully opened
	// Add attributes to the table
	Table table;
	string atts;
	getline(infile, atts);

	// Tokenize the attributes
	string attribute = get_token(atts);
	while (attribute != "") {
		table.addAttribute(attribute, AttributeList::STRING);
		cout << attribute << endl;
		attribute = get_token(atts);
	}
	
	// Loop through the cuisine info
	string cuisine, token;
	vector<string> rec_vec;
	while (true) {
		getline(infile, cuisine);
		if (cuisine == "") {
			break;
		}
		while (true) {
			token = get_token(cuisine);
			if (token == "") {
				break;
			}
			rec_vec.push_back(token);
			cout << token << '\t';
		}
		cout << endl;
		Record record = Record(rec_vec);
		// Add the record to the table
		table.insert(record);
	}
	// The table should have EXACTLY 138 records
	assert(table.getSize() == 138);

	// Add the table to the database
	_db.addTable(table, "Cuisine");
	
	infile.close();
	return true;
}

std::string Customer_Reader::get_token(string& _line) {
	long index = _line.find('\t');
	if (index == -1) {
		string line = _line;
		_line = "";
		return line;
	}	

	std::string token = _line.substr(0, index);
	_line = _line.substr(index + 1);
	return token;
}
