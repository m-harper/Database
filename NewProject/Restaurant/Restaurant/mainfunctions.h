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
void printRestaurantInfo(std::string restaurantName);
void printRatingsForCustomer(string userID);
void printRatingsForRestaurant(std::string resturantName);