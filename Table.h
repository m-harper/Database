///
///\class DBMS::Table Table.h Table.h
///\brief This class is used to build table objects for the database
///\author Patrick Swetz
///\file Table.h
#include "AttributeInfo.h"
#include "Date.h"
#include <vector>
#include "Record.h"
#ifndef TABLE_H
#define TABLE_H

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

class __declspec(dllexport) Table
{
    public:
        ///\brief Default constructor- makes an empty table
        Table(std::string);
        virtual ~Table();
        ///\brief constructor to take a list of table attributes and make the table
        ///\param[in] vector<AttributeInfo>& the list of attributes to make a table with
        ///\return the table
        Table(std::vector<DBMS::AttributeInfo> &, std::string);
        ///\brief finds the column that a particular attribute is in
        ///\param[in] string the name of the attribute to find
        ///\return int where the attribute is (0->size(table)-1) and -1 will be returned if not in table
        int getAttributesPlace(std::string);
        ///\brief removes an attribute from the table and from all records in the table
        ///\param[in] string the attribute to be deleted
        void deleteAttribute(std::string);
        ///\brief insert a new record into the end of the table
        ///\param[in] DBMS::Record the record to be inserted
        void insertRecord(DBMS::Record r){records.push_back(r);}
        ///\brief get the number of records in a table
        ///\return an int representing the number of records in the table
        int tableSize(){return records.size();}
        ///\brief rename an existing attribute in the table
        ///\param[in] string the existing name that is to be changed
        ///\param[in] string the new name that it is to be changed to
        void renameAttributeInTable(std::string, std::string);
        ///\brief sum up all of the entries of a specific attribute
        ///\param[in] string the attribute to be summed
        ///\return a float representing the sum of the entries
        float sum(std::string);
        ///\brief add a new attribute into the table, all existing records in the table get "NULL" for the attribute
        ///\param[in] string the name of the new attribute
        ///\param[in] string the type of the new attribute
        void addNewAttribute(std::string, std::string);
        ///\brief add an attributes info to the tables attribute information
        ///\param[in] string the name of the new attribute
        ///\param[in] string the type of the new attribute
        void insertAttributeInfo(std::string, std::string);
        ///\brief get an individual record back from the table
        ///\param[in] int the index to the individual record in the table(0->table.size()-1)
        ///\return the Record from the table
        DBMS::Record individualRecord(int i){return records[i];}
        std::string getTableName(){return tableName;}
        void changeTableName(std::string newName) {tableName = newName;}
        void attributeTypeInfo(std::vector<std::string> &attributeList, std::vector<DBMS::AttributeInfo> &returnList);
        int attributeInfoIndex(std::string);
        void attributesToDelete(std::vector<std::string> &attributeList, std::vector<std::string> &returnList);
        int attributeInfoSize(){return attributeInfo.size();}
    protected:
    private:
        std::vector<DBMS::AttributeInfo> attributeInfo;
        std::vector<DBMS::Record> records;
        void deleteAttributeInfo(int);
        std::string tableName;
};
}

#endif // TABLE_H
