///
///\class DBMS::Date Date.h Date.h
///\brief This class is used to create, convert, and compare date objects
/**
*\file Date.h
*
*
*
*\author Patrick Swetz
*
*/

#include <string>
#ifndef DATE_H
#define DATE_H

/*
#ifdef _WIN32
#ifdef DLL_EXPORTING
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else
#define DLL_API
#endif
*/

namespace DBMS {

class  __declspec(dllexport) Date
{
    public:
        ///\brief default constructor
        ///\return Date object
        Date();
        ///\brief constructor with 3 parameters
        ///\param[in] y an int to represent the year
        ///\param[in] m an int to represent the month
        ///\param[in] d an int to represent the day
        ///\return a date object
        Date(int y, int m, int d)
            :year(y), month(m), day(d) {}
        virtual ~Date();
        ///\brief a get function
        ///\return the day part of a date
        int getDay() const {return day;}
        ///\return the month part of a date
        int getMonth() const {return month;}
        ///\return the year part of a date
        int getYear() const {return year;}
        ///\brief convert a date object to a string
        ///\return a date represented as a string
        std::string dateToString();
        ///\brief convert a string to an int
        ///\param[in] string the string to be converted
        ///\return integer value
        int makeIntFromString(std::string);
        ///\brief convert a date represented as a string to a date object
        ///\param[in] string the string to be converted should be in "YYYY/MM/DD" format
        ///\return a date object
        Date makeDateFromString(std::string);
        ///\brief convert an int to a string
        ///\param[in] int the int to be converted
        ///\return returns a string representaion of the int input
        std::string intToString(int);
    protected:
    private:
        int day, month, year;

};

/// \brief two date objects can be compared with the following operations:
///\brief ==, <=, >=, <, >, !=
///
 __declspec(dllexport) bool operator==(const Date& a, const Date& b);
 __declspec(dllexport) bool operator<=(const Date& a, const Date& b);
 __declspec(dllexport) bool operator>=(const Date& a, const Date& b);
 __declspec(dllexport) bool operator!=(const Date& a, const Date& b);
 __declspec(dllexport) bool operator<(const Date& a, const Date& b);
 __declspec(dllexport) bool operator>(const Date& a, const Date& b);
}

#endif // DATE_H
