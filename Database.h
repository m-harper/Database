///\class DBMS::Database Database.h Database.h
///\brief This is the class to create and manage databases
///\author Patrick Swetz
///\file Database.h

#include "Table.h"
#ifndef DATABASE_H
#define DATABASE_H

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

class  __declspec(dllexport) Database
{
    public:
        ///\brief This is used to create and get the instance of the database
	///\return Database the one and only database that can be created
	Database &getInstance();
	///\brief addTable takes a table and a name and adds it to the database
	///\param[in] DBMS::Table the table to add to the database
	///\param[in] string the name of the table
        void addTable(DBMS::Table, std::string);
        ///\brief Gets the index of a particular table in the database
        ///\param[in] string the table to find
        ///\return Int that represents the index
        int tableIndex(std::string);
        ///\brief Delete a table from the database
        ///\param[in] string the table name to delete
        void dropTable(std::string);
        ///\brief Return all of the tables in the database
        ///\param vector<*DBMS::Table> the vector to return tables to
        void getTables(std::vector<DBMS::Table> &);
        ///\brief Return all of names of tables in the database
        ///\param vector<string> the vector to return names to
        void listTable(std::vector<std::string>);
	///\brief Get a table from the database 
	///\param[in] string Name of table to get
	///\return Table with given name
        DBMS::Table &getSingleTable(std::string);
	///\brief Query a Table in the form Select, From, Where
	///\param[in] vector<string>& the list of attributes to keep, empty list means keep all
	///\param[in] string the table to use 
	///\param[in] string the comparisons used to compare attributes
	///\return The table from these different operations
        DBMS::Table Query(std::vector<std::string> &, std::string, std::string);
	///\brief used to remove tuples from the table
	///\param[in] vector<string>& the list of attributes to keep
	///\param[in] string the name of the table to use
        void deleteTuples(std::vector<std::string>& SELECT, std::string FROM);
    protected:
    private:
        Database();
        virtual ~Database();
        Database(const Database &);
        const Database &operator=(const Database &);
        std::vector<DBMS::Table> tables;
};
}
#endif // DATABASE_H
//jeb0405@tamu.edu
