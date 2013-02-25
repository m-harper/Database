#include "customer_reader.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

//  Database db;

int main(int argc, char** argv) {
	Customer_Reader cr;
	//cr.read_customers();
	//cr.read_customer_payments();
	cr.read_customer_cuisine();
	return 0;
}

bool Customer_Reader::read_customers() {
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

	// Table customers;

	string token = get_token(attributes);
	while (token != "") {
		// customers.add_attribute(token, string);
		cout << token << endl;
		token = get_token(attributes);
	}

	// Read in the customers' data
	string customer;
	string info_token;
	// Record record;
	// Loop over all of the customers
	while (true) {
		getline(users, customer);
		if (customer == "") {
			break;
		}
		while (true) {
			// Get a token of info from the customer string
			info_token = get_token(customer);
			if (info_token == "")
				break;
			cout << info_token << '\t';
			// Add the info to a table record
			// record.add_entry(info);
		}
		// Add the created record to the table
		// table.add_record(record)
		// Reset the temporary record
		// record = Record();
		cout << '\n';
	}
	// There should be EXACTLY 138 customers
	// assert(table.num_records() == 138);
	
	// Add the table to the database
	// db.add_table(table, "Customers");

	users.close();
	return true;
}

bool Customer_Reader::read_customer_payments() {
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
	// Table table;
	// Add attributes to the table
	string atts;
	getline(payments, atts);
	// Tokenize the attributes
	string attribute = get_token(atts);
	while (attribute != "") {
		// table.add_attribute(attribute);
		cout << attribute << endl;
		attribute = get_token(atts);
	}

	// Loop through the payment info
	string pay, token;
	// Record record;
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
			// record.add_entry(token);
			cout << token << '\t';
		}
		cout << endl;
		// Add the record to the table
		// table.add_record(record);
		// Reset the temp record
		// record = Record();
	}
	// The table should have EXACTLY 138 records
	// assert(table.num_records() == 138);
	// Add the table to the database
	// db.add_table(table);
	
	payments.close();
	return true;
}

bool Customer_Reader::read_customer_cuisine() {
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
	// Table table;
	// Add attributes to the table
	string atts;
	getline(infile, atts);
	// Tokenize the attributes
	string attribute = get_token(atts);
	while (attribute != "") {
		// table.add_attribute(attribute);
		cout << attribute << endl;
		attribute = get_token(atts);
	}
	
	// Loop through the cuisine info
	string cuisine, token;
	// Record record;
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
			// record.add_entry(token);
			cout << token << '\t';
		}
		cout << endl;
		// Add the record to the table
		// table.add_record(record);
		// Reset the temp record
		// record = Record();
	}
	// The table should have EXACTLY 138 records
	// assert(table.num_records() == 138);
	// Add the table to the database
	// db.add_table(table);
	
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
