#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include "API.h"
#include "Database.h"

void printCustomerInfo(string userID, Table custProfile, Table custCuisine, Table custPayment);
void printRestaurantInfo(string restName, Table restInfo, Table restAccpets, Table restCuisine, Table restHours, Table restParking);
void printRatingsForCustomer(string userID, Table ratings, Table restInfo);
void printRatingsForRestaurant(std::string resturantName);