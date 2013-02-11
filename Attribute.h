///
///\class DBMS::Attribute Attribute.h Attribute.h
///\brief This class is used to build attribute objects of type string
///\file Attribute.h
///
///\author Patrick Swetz

#include <string>

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

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

namespace DBMS{

class  __declspec(dllexport) Attribute
{
    public:
        ///\brief constructor for Attribute objects
        ///\param[in] string the specific string to build an attribute with
        ///\return an attribute object
        Attribute(std::string);
        virtual ~Attribute();
        ///\brief returns the attribute stored in the object
        ///\return a string
        std::string getAttribute(){return attributeName;}
        ///\brief create a string from an integer
        ///\param[in] int an integer to convert
        ///\return the string representation of an int
        std::string fromInt(int);
        ///\brief create a string from a float
        ///\param[in] float a float to convert
        ///\return a string representation of an int
        std::string fromFloat(float);
        ///\brief create an int from a string
        ///\return the int value of an attribute
        int stringToInt();
        ///\brief create a float from a string
        ///\return the float value of an attribute
        float stringToFloat();
    protected:
    private:
        std::string attributeName;
};
}

#endif // ATTRIBUTE_H
