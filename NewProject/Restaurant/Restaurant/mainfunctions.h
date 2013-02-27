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

void printCustomerInfo(int userID);
void printRestaurantInfo(std::string restaurantName);
void printRatingsForCustomer(int userID);
void printRatingsForRestaurant(std::string resturantName);