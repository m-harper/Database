// Input Data Info:
// userprofile: Contains userID and various info about customer.
// userpayment: Conatins userID and customer's payment type. 
// usercuisine: Contains userID and cuisine preference.

// rating_final: Contains userID and user's ratings for restuarants.

// geoplaces2: Contains placeID, and various info about resturant.
// chefmozparking: Contains placeID, and parking info aobut resturant.
// chefmozhours4: Contains placeID, and hours of operation for resturant.
// chefmozcuisine: Contains placeID, and cuisine type of restaurant.
// chefmozaccepts: Contains placeID, and types of payments that resturant accepts.

#include "mainfunctions.h"
#include "API.h"

// Returns an enumerated value for the user command input
unsigned int commandIndex(std::string a) {

	const char* commands[] = { "C", "R", "A", "B", "E" };

	unsigned result = find(commands, commands + 5, a) - commands;
	if (result < 5) { return result; }
	else { return 6; }
}

int main() {
	// Assume 3 tables in database: customers, restaurants, ratings
	// Call Matt's funciton here. Somehow.

	ifstream ifs("input.txt");
	std::string input;

	while(ifs) {

		getline(ifs, input);

		switch (commandIndex(input.substr(0,1))) {

		case 0: // Displays info about a customer. Syntax: C <Customer ID>
			try {
			
				// Get customer info from customer table.
				printCustomerInfo(int userID, /*Table customers*/);
			} catch (int e) {

				cout << "\nError: Part " << e - 400 << " of student info entered incorrectly.\n";
				switch (e) {

				case 401:
					// This is a case of catching an specific error.
					// Simple use cout to display an error message.
					break;
				}
			}
			break;
		case 1: // Displays info about resturant. Syntax :  R <Resurant Name>
			try {

				// Get customer info from restaurant table.
				printRestaurantInfo(string restaurantName, /*Table restaurant*/);
			} catch (int e) {

				cout << "\nError: Part " << e - 400 << " of department info entered incorrectly.\n";
				switch (e) {

				case 401:
					// This is a case of catching an specific error.
					// Simple use cout to display an error message.
					break;
				}
			}
			break;
		case 2: // Displays rating info for a customer, Stntax: A <Customer ID> 
			try {
			
				printRatingsForCustomer(int userID, /*Table ratings*/);
				// - Iterates through ratings and prints ratings that match userID.
			} catch (int e) {

				cout << "\nError: Part " << e - 400 << " of fine info entered incorrectly.\n";
				switch (e) {

				case 401:
					cout << "  -- Student ID (9-digits)\n\n";
					break;
				}
			break;
		case 3: // Displays rating infor for a restaurant, Syntax: B <Restaurant Name>
			try {

				// Use restaurant name and find matching placeID;
				printRatingsForRestaurant(int placeID, /*Table ratings*/);
				// - Iterate through ratings and pull out all the ratings that match placeID.
			} catch (int e) {

				cout << "\nError: Part " << e - 400 << " of department info entered incorrectly.\n";
				switch (e) {

				case 401:
					// This is a case of catching an specific error.
					// Simple use cout to display an error message.
					break;
				}
			}
			break;
		case 4: // Exit, Syntax: E
			return 0;
		default:
			cout << "\nInvalid expression.\n\n";
		}
	}
	cout << "Done.\n";
	cin >> input;
}
