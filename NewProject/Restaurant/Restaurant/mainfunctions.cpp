#include "mainfunctions.h"

void printCustomerInfo(string userID, Table custProfile, Table custCuisine, Table custPayment) {
	// Get attribute list from the customers table
	vector<AttributeList> attributeList1 = custProfile.getAttributes();
	vector<AttributeList> attributeList2 = custCuisine.getAttributes();
	vector<AttributeList> attributeList3 = custPayment.getAttributes();

	// ?? do we assume userID is first attribute in table? or we do not know it?
	// If we do not know where userID attribute is
	int index = 0;
	while(index < attributeList1.size()) {
		if(attributeList1[index].getName() == "userID")
			break;
		else
			++index;
	}

	cout << index;

	// find matching userID from userID colunm.
	int size = custProfile.getSize();
	Table::TableIterator tableIterator = Table::TableIterator(0, &custProfile);
	Record record = tableIterator.get();
	for(int i = 0; i < custProfile.getSize(); i++) {
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 0; j < record.size(); j++){
				std::cout << record.getAt(j) << '\n';
			}
			break;
		}
		if (i != custProfile.getSize() -1)
			record = tableIterator.next();
	}

	index = 0;

	while(index < attributeList2.size()){
		if(attributeList2[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	size = custCuisine.getSize();
	tableIterator = Table::TableIterator(0, &custCuisine);
	record = tableIterator.get();
	for(int i = 0; i < custCuisine.getSize(); i++){
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 0; j < record.size(); j++){
				std::cout << record.getAt(j) << '\n';
			}
		}
		if (i != custCuisine.getSize() -1)
			record = tableIterator.next();
	}

	index = 0;
	while(index < attributeList3.size()){
		if(attributeList3[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	size = custPayment.getSize();
	tableIterator = Table::TableIterator(0, &custPayment);
	record = tableIterator.get();
	for(int i = 0; i < custPayment.getSize(); i++){
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 0; j < record.size(); j++){
				std::cout << record.getAt(j) << '\n';
			}
		}
		if (i != custPayment.getSize() -1)
			record = tableIterator.next();
	}

	// Then print out a record


}
void printRestaurantInfo(std::string restaurantName, Table restaurants) {

}

void printRatingsForCustomer(string userID, Table ratings) {

}

void printRatingsForRestaurant(std::string resturantName, Table ratings) {

}