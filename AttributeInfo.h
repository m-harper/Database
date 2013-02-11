///
///\class DBMS::AttributeInfo AttributeInfo.h AttributeInfo.h
///\brief This class is used to store the name and type of an attribute
///\author Patrick Swetz
///\file AttributeInfo.h

#include <string>
#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H

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

class  __declspec(dllexport) AttributeInfo
{
    public:
        ///\brief default constructor
        AttributeInfo();
        ///\brief constructor, used to take a name and type
        ///\param[in] name a string representing the name of an attribute
        ///\param[in] type a string representing the type of an attribute
        AttributeInfo(std::string name, std::string type);
        virtual ~AttributeInfo();
        ///\brief a getter function for an attribute's name
        ///\return the string representing the name
        std::string getAttributeName(){return attributeName;}
        ///\brief a getter function for an attribute's type
        ///\return the string representing the type
        std::string getAttributeType(){return attributeType;}
        ///\brief change the name field of a certain attribute
        ///\param[in] string the name to change the attribute to
        void renameAttribute(std::string);
    protected:
    private:
        std::string attributeName;
        std::string attributeType;
};
}
#endif // ATTRIBUTEINFO_H
