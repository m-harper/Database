#include "mainfunctions.h"

void printCustomerInfo(string userID, Table custProfile, Table custCuisine, Table custPayment) {

	cout << "\r";
	cout << "       -- Customer Details for userID: " << userID << " --\nPlease wait...";
	cout << "\r";

	bool custInfoPrinted = false;
	bool custItemFound = false;
	bool custItemFinish = false;

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
			for(int j = 0; j < record.size(); j++) {
				if(attributeList1[j].getName() != "userID"){
					string tempString = attributeList1[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			custInfoPrinted = true;
			break;
		}

		if (i != (custProfile.getSize() -1))
			record = tableIterator.next();
	}

	// If customer not found, then throw error message.
	if (!custInfoPrinted)
		throw 402;
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList2[j].getName() != "userID"){
					string tempString = attributeList2[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			custItemFound = true;
		}

		while (custItemFound == true) {
			if (i != (custCuisine.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(index);
				if(value == userID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList2[j].getName() != "userID"){
							string tempString = attributeList2[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					custItemFound = false;
					custItemFinish = true;
				}
			} else custItemFound = false;
		}

		if (custItemFinish)
			break;

		if(i != (custCuisine.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Cuisine (" << i << "/331)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	custItemFound = false;
	custItemFinish = false;
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList3[j].getName() != "userID"){
					string tempString = attributeList3[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			custItemFound = true;
		}

		while (custItemFound == true) {
			if (i != (custPayment.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(index);
				if(value == userID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList3[j].getName() != "userID"){
							string tempString = attributeList3[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					custItemFound = false;
					custItemFinish = true;
				}
			} else custItemFound = false;
		}

		if (custItemFinish)
			break;

		if(i != (custPayment.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Payment (" << i << "/178)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	cout << "\n\n";
}

void printRestaurantInfo(std::string restaurantName, Table restInfo, Table restAccpets, Table restCuisine, Table restHours, Table restParking) {

	cout << "\r";
	cout << "       -- Restaurant Details for restaurantName: " << restaurantName << " --\nPlease wait...";
	cout << "\r";

	bool restInfoPrinted = false;
	bool restItemFound = false;
	bool restItemFinish = false;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList1[j].getName() != "name"){
					string tempString = attributeList1[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						if (j == 3)
							cout << "\n";
						else;
						newLineTracker++;
					} else {
						if (j == 3) {
							cout << "\n" << left << setw(28) << tempString << "\n";
							newLineTracker++;
						} else {
							cout << left << setw(28) << tempString << "\n";
							newLineTracker++;
						}
					}
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
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++) {
				if(attributeList2[j].getName() != "placeID"){
					string tempString = attributeList2[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			restItemFound = true;
		}


		while (restItemFound == true) {
			if (i != (restAccpets.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(placeIndex);
				if(value == placeID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList2[j].getName() != "placeID"){
							string tempString = attributeList2[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					restItemFound = false;
					restItemFinish = true;
				}
			} else restItemFound = false;
		}

		if (restItemFinish)
			break;

		if(i != (restAccpets.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Payment (" << i << "/1315)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	restItemFound = false;
	restItemFinish = false;
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList3[j].getName() != "placeID"){
					string tempString = attributeList3[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			restItemFound = true;
		}

		while (restItemFound == true) {
			if (i != (restCuisine.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(placeIndex);
				if(value == placeID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList3[j].getName() != "placeID"){
							string tempString = attributeList3[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					restItemFound = false;
					restItemFinish = true;
				}
			} else restItemFound = false;
		}

		if (restItemFinish)
			break;


		if(i != (restCuisine.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Cuisine (" << i << "/917)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	restItemFound = false;
	restItemFinish = false;
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList4[j].getName() != "placeID"){
					string tempString = attributeList4[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			restItemFound = true;
		}

		while (restItemFound == true) {
			if (i != (restHours.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(placeIndex);
				if(value == placeID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList4[j].getName() != "placeID"){
							string tempString = attributeList4[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					restItemFound = false;
					restItemFinish = true;
				}
			} else restItemFound = false;
		}

		if (restItemFinish)
			break;

		if(i != (restHours.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Hours (" << i << "/2340)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	restItemFound = false;
	restItemFinish = false;
	if (newLineTracker % 2 == 0)
		cout << "\n";
	else
		cout << "\n\n";
	newLineTracker = 0;

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
			for(int j = 0; j < record.size(); j++){
				if(attributeList5[j].getName() != "placeID"){
					string tempString = attributeList5[j].getName() + ": " + record.getAt(j);
					if (newLineTracker % 2 == 0) {
						cout << left << setw(28) << tempString << "   ";
						newLineTracker++;
					} else {
						cout << left << setw(28) << tempString << "\n";
						newLineTracker++;
					}
				}
			}
			restItemFound = true;
		}

		while (restItemFound == true) {
			if (i != (restParking.getSize() - 1) ) {
				record = tableIterator.next();
				value = record.getAt(placeIndex);
				if(value == placeID) {
					for(int j = 0; j < record.size(); j++) {
						if(attributeList2[j].getName() != "placeID"){
							string tempString = attributeList5[j].getName() + ": " + record.getAt(j);
							if (newLineTracker % 2 == 0) {
								cout << left << setw(28) << tempString << "   ";
								newLineTracker++;
							} else {
								cout << left << setw(28) << tempString << "\n";
								newLineTracker++;
							}
						}
					}
				} else {
					restItemFound = false;
					restItemFinish = true;
				}
			} else restItemFound = false;
		}

		if (restItemFinish)
			break;

		if(i != (restParking.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Parking (" << i << "/703)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	cout << "\n\n";
}

void printRatingsForCustomer(string userID, Table ratings, Table restInfo) {
	
	cout << "\r";
	cout << "       -- Ratings for userID: " << userID << " --\nPlease wait...";
	cout << "\r";

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
	string placeID, id, restaurantName;
	Table::TableIterator tableIterator1 = Table::TableIterator(0, &ratings);
	Record record1 = tableIterator1.get();
	int theNumber = 1;

	for(int i = 0; i < ratings.getSize(); i++){
		string value = record1.getAt(userIdIndex);

		if(value == userID) {
			cout << "       ***********   " << theNumber << "   ***********\n";
			placeID = record1.getAt(ratingPlaceIndex);
			Table::TableIterator tableIterator2 = Table::TableIterator(0, &restInfo);
			Record record2 = tableIterator2.get();

			for(int k = 0; k < restInfo.getSize(); k++){
				id = record2.getAt(restPlaceIndex);
				if(id == placeID){
					restaurantName = record2.getAt(nameIndex);

					cout << "Restaurant Name: " << restaurantName << endl;
					break;
				}
				if(k != (restInfo.getSize() - 1))
					record2 = tableIterator2.next();
			}

			for(int j = 0; j < record1.size(); j++){
				if(attributeList1[j].getName() != "userID"){
					if(newLineTracker % 2 == 0) {
						cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record1.getAt(j) << "    ";
						newLineTracker++;
					} else {
						cout << left << setw(16) << attributeList1[j].getName() << ": " << setw(11) << record1.getAt(j) << "\n";
						newLineTracker++;
					}
				}
			}

			restInfoPrinted = true;
			++theNumber;
		}

		if(i != (ratings.getSize() - 1)) {
			record1 = tableIterator1.next();
			cout << "Searching: Ratings (" << i << "/1162)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}

	if(!restInfoPrinted)
		throw 402;
	else
		cout << '\n';
}

void printRatingsForRestaurant(std::string restName, Table restInfo, Table ratings) {

	cout << "\r";
	cout << "       -- Ratings for restaurantName: " << restName << " --\nPlease wait...";
	cout << "\r";

	bool restInfoPrinted = false;
	int newLineTracker = 0;

	// Get attribute list from the restaurant table
	vector<AttributeList> attributeList1 = restInfo.getAttributes();
	vector<AttributeList> attributeList2 = ratings.getAttributes();

	// ------------------------------------------------------------------------
	// restInfo
	// Search where restaurant name attribute is in Table restInfo
	int nameIndex = 0;
	while(nameIndex < attributeList1.size()) {
		if(attributeList1[nameIndex].getName() == "name")
			break;
		else
			++nameIndex;
	}

	// Search where place ID attribute is in Table restInfo
	int restPlaceIndex = 0;
	while(restPlaceIndex < attributeList1.size()) {
		if(attributeList1[restPlaceIndex].getName() == "placeID")
			break;
		else
			++restPlaceIndex;
	}


	// ratings
	// Search where userID attribute is in Table ratings
	int userIdIndex = 0;
	while(userIdIndex < attributeList2.size()) {
		if(attributeList2[userIdIndex].getName() == "userID")
			break;
		else
			++userIdIndex;
	}

	// Search where place ID attribute is in Table ratings
	int ratingPlaceIndex = 0;
	while(ratingPlaceIndex < attributeList2.size()) {
		if(attributeList2[ratingPlaceIndex].getName() == "placeID")
			break;
		else
			++ratingPlaceIndex;
	}

	// -------------------------------------------------------------------

	// Search place ID for restaurantName
	string placeID;
	Table::TableIterator tableIterator = Table::TableIterator(0, &restInfo);
	Record record = tableIterator.get();
	for(int i = 0; i < restInfo.getSize(); i++){
		string value = record.getAt(nameIndex);

		if(value == restName){
			placeID = record.getAt(restPlaceIndex);
			cout << "Restaurant ID: " << placeID << endl;
			break;
		}
		if (i != (restInfo.getSize() - 1))
			record = tableIterator.next();
	}

	tableIterator = Table::TableIterator(0, &ratings);
	record = tableIterator.get();

	for(int i = 0; i < ratings.getSize(); i++) {
		string value = record.getAt(ratingPlaceIndex);

		if(value == placeID){
			for(int j = 0; j < record.size(); j++){
				if(attributeList2[j].getName() != "placeID"){
					if(newLineTracker % 2 == 0) {
						cout << left << setw(16) << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "    ";
						newLineTracker++;
					} else {
						cout << left << setw(16) << attributeList2[j].getName() << ": " << setw(11) << record.getAt(j) << "\n";
						newLineTracker++;
					}
				}
			}
			restInfoPrinted = true;
		}

		if(i != (ratings.getSize() - 1)) {
			record = tableIterator.next();
			cout << "Searching: Ratings (" << i << "/1162)";
			cout << "\r";
		} else {
			// Clear the line.
			cout << "                                                  ";
		}
	}
	cout << "\n\n";
	if (!restInfoPrinted) {
		throw 401;
	}
}