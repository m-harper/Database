#include "mainfunctions.h"

void printCustomerInfo(string userID, Table custProfile, Table custCuisine, Table custPayment) {
	// Get attribute list from the customers table
	vector<AttributeList> attributeList1 = custProfile.getAttributes();
	vector<AttributeList> attributeList2 = custCuisine.getAttributes();
	vector<AttributeList> attributeList3 = custPayment.getAttributes();

	// Find where userID attribute is
	int index = 0;
	while(index < attributeList1.size()) {
		if(attributeList1[index].getName() == "userID")
			break;
		else
			++index;
	}


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
}
void printRestaurantInfo(std::string restaurantName, Table restInfo, Table restAccpets, Table restCuisine, Table restHours, Table restParking) {
	// Get attribute list from the restaurant table
	vector<AttributeList> attributeList1 = restInfo.getAttributes();
	vector<AttributeList> attributeList2 = restAccpets.getAttributes();
	vector<AttributeList> attributeList3 = restCuisine.getAttributes();
	vector<AttributeList> attributeList4 = restHours.getAttributes();
	vector<AttributeList> attributeList5 = restParking.getAttributes();

	// Find where restaurant name attribute is
	int nameIndex = 0;
	while(nameIndex < attributeList1.size()) {
		if(attributeList1[nameIndex].getName() == "name")
			break;
		else
			++nameIndex;
	}

	// Find where place ID attribute is
	int placeIndex = 0;
	while(placeIndex < attributeList1.size()) {
		if(attributeList1[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}


}

void printRatingsForCustomer(string userID, Table ratings) {

}

void printRatingsForRestaurant(std::string resturantName, Table ratings) {

}