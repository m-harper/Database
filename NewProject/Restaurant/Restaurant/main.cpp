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
#include "restaurant_reader.h"
#include "API.h"
#include <string>


// Returns an enumerated value for the user command input
unsigned int commandIndex(std::string a) {

	const char* commands[] = { "C", "R", "A", "B", "E" };

	// Adjust the numbers to match the numbers of entries in commands[]
	unsigned result = find(commands, commands + 5, a) - commands;
	if (result < 5) { return result; }
	else { return 6; }
}

int main() {
	Database db;
	Restaurant_Reader rr;

	rr.read_all(db);

	cout << "\n\n";
	cout << "Syntax:\n";
	cout << "C <userID>            : Prints info about customer.\n";
	cout << "R <Restaurant Name>   : Prints info about restaurant.\n";
	cout << "A <userID>            : Prints info about customer's ratings.\n";
	cout << "B <Restaurant Name>   : Prints info about restaurant's ratings.\n\n";

	// Matt's function should be called at this point.
	// Assume 3 tables are here in the database: customers, restaurants, ratings

	std::string input;

	while (true) {
		cout << ">> ";
		std::getline(std::cin, input);

		switch (commandIndex(input.substr(0,1))) {

		case 0: // Displays info about a customer. Syntax: C <Customer ID>
			try {

				cout << "\nPlease wait...";

				input.erase(0,2);

				if (input.length() != 5)
					throw 401;

				Table custProfile = db.query(vector<string>(), "User Profile", "");
				Table custCuisine = db.query(vector<string>(), "User Cuisine", "");
				Table custPayment = db.query(vector<string>(), "User Payment", "");
				printCustomerInfo(input, custProfile, custCuisine, custPayment);

			} catch (int e) {

				cout << "\nError: ";
				switch (e) {
				case 401:
					cout << "Invalid ID length.\n\n";
					break;
				case 402:
					cout << "Customer profile not found.\n\n";
					break;
				}
			}
			break;
		case 1: // Displays info about resturant. Syntax :  R <Resurant Name>
			try {

				cout << "\nPlease wait...";

				input.erase(0,2);

				Table restInfo = db.query(vector<string>(), "Restaurant Info", "");
				Table restAccepts = db.query(vector<string>(), "Restaurant Accepts", "");
				Table restCuisine = db.query(vector<string>(), "Restaurant Cuisine", "");
				Table restHours = db.query(vector<string>(), "Restaurant Hours", "");
				Table restParking = db.query(vector<string>(), "Restaurant Parking", "");

				printRestaurantInfo(input, restInfo, restAccepts, restCuisine, restHours, restParking);

			} catch (int e) {

				cout << "\nError: ";
				switch (e) {

				case 401:
					cout << "Restaurant main profile not found.\n\n";
					break;
				}
			}
			break;
		case 2: // Displays rating info for a customer, Stntax: A <Customer ID> 
			try {

				input.erase(0,2);

				if (input.length() != 5)
					throw 401;

				Table ratings = db.query(vector<string>(), "Ratings", "");
				Table restInfo = db.query(vector<string>(), "Restaurant Info", "");

				printRatingsForCustomer(input, ratings, restInfo);

			} catch (int e) {

				cout << "\nError: ";
				switch (e) {
				case 401:
					cout << "Invalid ID length.\n\n";
					break;
				case 402:
					cout << "Customer profile not found.\n\n";
					break;
				}
			}
			break;
		case 3: // Displays rating infor for a restaurant, Syntax: B <Restaurant Name>
			try {

				input.erase(0,2);

				Table restInfo = db.query(vector<string>(), "Restaurant Info", "");
				Table ratings = db.query(vector<string>(), "Ratings", "");

				// Use restaurant name and find matching placeID here.

				printRatingsForRestaurant(input, restInfo, ratings);
				// - Iterate through ratings and pull out all the ratings that match placeID.
			} catch (int e) {

				cout << "\nError: ";
				switch (e) {

				case 401:
					cout << "Restaurant main profile not found.\n\n";
					break;
				}
			}
			break;
		case 4: // Exit, Syntax: E
			return 0;
		default:
			cout << "\nInvalid expression.\n\n";
		}
		cout << "Done.\n\n";
	}
}
