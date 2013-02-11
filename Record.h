///
///\class DBMS::Record Record.h Record.h
///\brief This class is used to create the records(tuples) that will go in the table.
///\author Patrick Swetz
///\file Record.h


#include "Attribute.h"
#include <vector>
#ifndef RECORD_H
#define RECORD_H

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

class  __declspec(dllexport) Record
{
    public:
        ///\brief Default constructor for record Object
        Record();
        virtual ~Record();
        ///\brief returns the string representation of an attribute from the record
        ///\param[in] int the index to the specific attribute
        ///\return a string representing the attribute
        std::string getAttrib(int);
        ///\brief returns the attribute from the record
        ///\param[in] int the index to the specific attribute
        ///\return the actual attribute itself
        DBMS::Attribute returnAttribute(int);
        ///\brief adds an attribute to the tuple of records.
        ///\param[in] s a string that is pushed into the records
        void addAttribute(std::string s) {attributes.push_back(DBMS::Attribute(s));}
        ///\brief removes an attribute from the tuple of records
        ///\param[in] int an index to the specific attribute to be removed
        void removeAttribute(int);
        ///\brief gets the current number of attributes
        ///\return an int that represents the size of the tuple
        int numberOfAttributes(){return attributes.size();}
    protected:
    private:
        std::vector<DBMS::Attribute> attributes;
};
}
#endif // RECORD_H
