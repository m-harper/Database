#include "mainfunctions.h"

void printCustomerInfo(int userID, Table customers) {
	// Get attribute list from the customers table
	vector<AttributeList> attributeList = customers.getAttributes();

	// ?? do we assume userID is first attribute in table? or we do not know it?
	// If we do not know where userID attribute is
	int index = 0;
	while(index < attributeList.size()){
		if(attributeList[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	// Then print out a record
}
void printRestaurantInfo(std::string restaurantName, Table restaurants) {
	
}

void printRatingsForCustomer(int userID, Table ratings) {
	
}

void printRatingsForRestaurant(std::string resturantName, Table ratings) {
	
}