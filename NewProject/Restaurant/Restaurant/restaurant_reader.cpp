#include "restaurant_reader.h"
#include <iostream>

bool Restaurant_Reader::read_all(Database& _db) {
	vector<const char*> file_names;
	vector<string> table_names;
	file_names.push_back("data/chefmozaccepts.txt");
	table_names.push_back("Chef Accepts");
	file_names.push_back("data/chefmozcuisine.txt");
	table_names.push_back("Chef Cuisine");
	file_names.push_back("data/chefmozhours4.txt");
	table_names.push_back("Chef Hours");
	file_names.push_back("data/chefmozparking.txt");
	table_names.push_back("Chef Parking");
	file_names.push_back("data/usercuisine.txt");
	table_names.push_back("User Cuisine");
	file_names.push_back("data/userpayment.txt");
	table_names.push_back("User Payment");
	file_names.push_back("data/userprofile.txt");
	table_names.push_back("User Profile");
	file_names.push_back("data/rating_final.txt");
	table_names.push_back("Ratings");

	for (int i = 0; i < file_names.size(); i++) {
		if (! read_one(file_names[i], table_names[i], _db))
			return false;
	}
	cout << "Added tables ";
	vector<string> vec = _db.listTables();
	for (string s : vec) {
		cout << s << ", ";
	}
	cout << endl;
	return true;
}

bool Restaurant_Reader::read_one(const char* file_name, std::string table_name, Database& _db) {
	cout << "Attempting to open " << file_name << "...";

	// Open the file
	ifstream accepts;
	accepts.open(file_name);

	if (accepts.is_open()) {
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
	getline(accepts, atts);

	// Tokenize the attributes
	string attribute = get_token(atts);
	while (attribute != "") {
		table.addAttribute(attribute, AttributeList::STRING);
		//cout << attribute << endl;
		attribute = get_token(atts);
	}

	// Attributes have been added
	// Add the record information
	string line, token;
	while (true) {
		vector<string> vec;
		getline(accepts, line);
		if (line == "") {
			break;
		}
		while (true) {
			token = get_token(line);
			if (token == "") {
				break;
			}
			vec.push_back(token);
			//cout << token << '\t';
		}
		//cout << endl;
		Record record(vec);

		// Add the record to the table
		table.insert(record);
	}

	// Add the table to the database
	_db.addTable(table, table_name);

	accepts.close();
	return true;
}

std::string Restaurant_Reader::get_token(string& _line) {
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