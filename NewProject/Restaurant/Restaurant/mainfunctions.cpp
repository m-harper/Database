#include "mainfunctions.h"

void printCustomerInfo(string userID, Table custProfile, Table custCuisine, Table custPayment) {

	cout << "\n          -- Customer Details for userID: " << userID << " --\n";

	bool custInfoPrinted = false;
	int newLineTracker = 0;

	// Get attribute list from the customers table
	vector<AttributeList> attributeList1 = custProfile.getAttributes();
	vector<AttributeList> attributeList2 = custCuisine.getAttributes();
	vector<AttributeList> attributeList3 = custPayment.getAttributes();

	// -------------------------------------------------------------------------
	// custProfile
	// Find where userID attribute is
	int index = 0;
	while(index < attributeList1.size()) {
		if(attributeList1[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	//int size = custProfile.getSize();
	Table::TableIterator tableIterator = Table::TableIterator(0, &custProfile);
	Record record = tableIterator.get();
	for(int i = 0; i < custProfile.getSize(); i++) {
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 1; j < record.size(); j++){
				if (newLineTracker % 2 == 0) {
					std::cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record.getAt(j) << "   ";
					newLineTracker++;
				} else {
					std::cout << left << setw(16)  << attributeList1[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			custInfoPrinted = true;
			break;
		}
		if (i != (custProfile.getSize() -1))
			record = tableIterator.next();
	}

	// -------------------------------------------------------------------------------------------
	// custCuisine

	index = 0;

	while(index < attributeList2.size()){
		if(attributeList2[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	//size = custCuisine.getSize();
	tableIterator = Table::TableIterator(0, &custCuisine);
	record = tableIterator.get();
	for(int i = 0; i < custCuisine.getSize(); i++){
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 1; j < record.size(); j++){
				if (newLineTracker % 2 == 0) {
					std::cout << left << setw(16)  << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "   ";
					newLineTracker++;
				} else {
					std::cout << left << setw(16)  << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			custInfoPrinted = true;
		}
		if (i != (custCuisine.getSize() -1))
			record = tableIterator.next();
	}

	// ---------------------------------------------------------------------------------------
	// custPayment

	index = 0;
	while(index < attributeList3.size()){
		if(attributeList3[index].getName() == "userID")
			break;
		else
			++index;
	}

	// find matching userID from userID colunm.
	//size = custPayment.getSize();
	tableIterator = Table::TableIterator(0, &custPayment);
	record = tableIterator.get();
	for(int i = 0; i < custPayment.getSize(); i++){
		std::string value = record.getAt(index);

		if(value == userID) {
			for(int j = 1; j < record.size(); j++){
				if (newLineTracker % 2 == 0) {
					std::cout << left << setw(16)  << attributeList3[j].getName() << ": " << setw(11) << record.getAt(j) << "   ";
					newLineTracker++;
				} else {
					std::cout  << left << setw(16)  << attributeList3[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			custInfoPrinted = true;
		}
		if (i != (custPayment.getSize() -1))
			record = tableIterator.next();
	}

	if (!custInfoPrinted)
		cout << "No data found.\n\n";
	else
		cout << "\n";
}

void printRestaurantInfo(std::string restaurantName, Table restInfo, Table restAccpets, Table restCuisine, Table restHours, Table restParking) {

	cout << "\n       -- Restaurant Details for restaurantName: " << restaurantName << " --\n";

	bool restInfoPrinted = false;
	int newLineTracker = 0;

	// Get attribute list from the restaurant table
	vector<AttributeList> attributeList1 = restInfo.getAttributes();
	vector<AttributeList> attributeList2 = restAccpets.getAttributes();
	vector<AttributeList> attributeList3 = restCuisine.getAttributes();
	vector<AttributeList> attributeList4 = restHours.getAttributes();
	vector<AttributeList> attributeList5 = restParking.getAttributes();

	// ------------------------------------------------------------------------
	// restInfo
	// Search where restaurant name attribute is
	int nameIndex = 0;
	while(nameIndex < attributeList1.size()) {
		if(attributeList1[nameIndex].getName() == "name")
			break;
		else
			++nameIndex;
	}

	// Search where place ID attribute is
	int placeIndex = 0;
	while(placeIndex < attributeList1.size()) {
		if(attributeList1[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}

	// Search place ID for restaurantName
	string placeID;
	Table::TableIterator tableIterator = Table::TableIterator(0, &restInfo);
	Record record = tableIterator.get();
	for(int i = 0; i < restInfo.getSize(); i++){
		string value = record.getAt(nameIndex);

		if(value == restaurantName) {
			for(int j = 1; j < record.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record.getAt(j) << "    ";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}

			placeID = record.getAt(placeIndex);

			restInfoPrinted = true;
			break;
		}
		if (i != (restInfo.getSize() - 1))
			record = tableIterator.next();
	}

	if(!restInfoPrinted)
		throw 401;
	else
		cout << '\n';

	// -------------------------------------------------------------------------------------------
	// restAccepts

	placeIndex = 0;

	while(placeIndex < attributeList2.size()){
		if(attributeList2[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}

	tableIterator = Table::TableIterator(0, &restAccpets);
	record = tableIterator.get();

	for(int i = 0; i < restAccpets.getSize(); i++) {
		string value = record.getAt(placeIndex);

		if(value == placeID){
			for(int j = 1; j < record.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << left << setw(16) << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "    ";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			restInfoPrinted = true;
		}
		if(i != (restAccpets.getSize() - 1))
			record = tableIterator.next();
	}

	// ----------------------------------------------------------------------------------
	// restCuisine

	placeIndex = 0;

	while(placeIndex < attributeList3.size()){
		if(attributeList3[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}

	tableIterator = Table::TableIterator(0, &restCuisine);
	record = tableIterator.get();

	for(int i = 0; i < restCuisine.getSize(); i++) {
		string value = record.getAt(placeIndex);

		if(value == placeID){
			for(int j = 1; j < record.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << left << setw(16) << attributeList3[j].getName() << ": " << setw(11) << record.getAt(j) << "    ";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList3[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			restInfoPrinted = true;
		}
		if(i != (restCuisine.getSize() - 1))
			record = tableIterator.next();
	}


	// -----------------------------------------------------------------------------------
	// restHours

	placeIndex = 0;

	while(placeIndex < attributeList4.size()){
		if(attributeList4[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}

	tableIterator = Table::TableIterator(0, &restHours);
	record = tableIterator.get();

	for(int i = 0; i < restHours.getSize(); i++) {
		string value = record.getAt(placeIndex);

		if(value == placeID){
			for(int j = 1; j < record.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << '\n' <<left << setw(16) << attributeList4[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList4[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			restInfoPrinted = true;
		}
		if(i != (restHours.getSize() - 1))
			record = tableIterator.next();
	}


	// -----------------------------------------------------------------------------------
	// restParking

	placeIndex = 0;

	while(placeIndex < attributeList5.size()){
		if(attributeList5[placeIndex].getName() == "placeID")
			break;
		else
			++placeIndex;
	}

	tableIterator = Table::TableIterator(0, &restParking);
	record = tableIterator.get();

	for(int i = 0; i < restParking.getSize(); i++) {
		string value = record.getAt(placeIndex);

		if(value == placeID){
			for(int j = 1; j < record.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << left << setw(16) << attributeList5[j].getName() << ": " << setw(11) << record.getAt(j) << "    ";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList5[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
					newLineTracker++;
				}
			}
			restInfoPrinted = true;
		}
		if(i != (restParking.getSize() - 1))
			record = tableIterator.next();
	}
}

void printRatingsForCustomer(string userID, Table ratings, Table restInfo) {
	cout << "\n       -- Rating for userID: " << userID << " --\n";

	bool restInfoPrinted = false;
	int newLineTracker = 0;

	// Get attribute list from the restaurant table
	vector<AttributeList> attributeList1 = ratings.getAttributes();
	vector<AttributeList> attributeList2 = restInfo.getAttributes();

	// ------------------------------------------------------------------------
	// ratings
	// Search where userID attribute is in Table ratings
	int userIdIndex = 0;
	while(userIdIndex < attributeList1.size()) {
		if(attributeList1[userIdIndex].getName() == "userID")
			break;
		else
			++userIdIndex;
	}

	// Search where place ID attribute is in Table ratings
	int ratingPlaceIndex = 0;
	while(ratingPlaceIndex < attributeList1.size()) {
		if(attributeList1[ratingPlaceIndex].getName() == "placeID")
			break;
		else
			++ratingPlaceIndex;
	}


	// restInfo
	// Search where restaurant name attribute is in Table restInfo
	int nameIndex = 0;
	while(nameIndex < attributeList2.size()) {
		if(attributeList2[nameIndex].getName() == "name")
			break;
		else
			++nameIndex;
	}

	// Search where place ID attribute is in Table restInfo
	int restPlaceIndex = 0;
	while(restPlaceIndex < attributeList2.size()) {
		if(attributeList2[restPlaceIndex].getName() == "placeID")
			break;
		else
			++restPlaceIndex;
	}

	// Search place ID for restaurantName
	string placeID;
	Table::TableIterator tableIterator1 = Table::TableIterator(0, &ratings);
	Table::TableIterator tableIterator2 = Table::TableIterator(0, &restInfo);
	Record record1 = tableIterator1.get();
	Record record2 = tableIterator2.get();
	int theNumber = 1;

	for(int i = 0; i < ratings.getSize(); i++){
		string value = record1.getAt(userIdIndex);

		if(value == userID) {
			cout << "\n *******" << theNumber << "*******\n";
			placeID = record1.getAt(ratingPlaceIndex);

			for(int k = 0; k < restInfo.getSize(); k++){
				
				string restaurantName = record2.getAt(nameIndex);
				
				cout << "Restaurant Name is: " << restaurantName << endl;

			}

			for(int j = 1; j < record1.size(); j++){
				if(newLineTracker % 2 == 0) {
					cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record1.getAt(j) << "    ";
					newLineTracker++;
				} else {
					cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record1.getAt(j) << "\n";
					newLineTracker++;
				}
			}

			restInfoPrinted = true;
			++theNumber;
		}
		if (i != (ratings.getSize() - 1))
			record1 = tableIterator1.next();
	}

	// ------------------------------------------------------------------------------
	/*
	tableIterator = Table::TableIterator(0, &restInfo);
	record = tableIterator.get();

	for(int i = 0; i < restInfo.getSize(); i++) {
	string value = record.getAt(restPlaceIndex);

	if(value == placeID){
	string restaurantName = record.getAt(nameIndex);
	cout << "\n Restaurant Name is: " << restaurantName << endl;
	restInfoPrinted = true;
	}
	if(i != (restInfo.getSize() - 1))
	record = tableIterator.next();
	}
	*/
	if(!restInfoPrinted)
		throw 401;
	else
		cout << '\n';
}

void printRatingsForRestaurant(std::string resturantName, Table ratings) {

}