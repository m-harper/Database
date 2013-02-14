#include "stdafx.h"
#include "CppUnitTest.h"
#include "Database.h"
#include "Table.h"
#include "Record.h"
#include "Attribute.h"
#include "AttributeInfo.h"
#include "Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace DBMS;

namespace T27UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// Table.h

		TEST_METHOD(tableSizeDefaultTable)
		{
			DBMS::Table test = DBMS::Table("Hello");
			int i = test.tableSize();
			int j = test.tableSize();

			Assert::AreEqual(0,j);

		}
		TEST_METHOD(tableSizeDefaultAttributeInfo)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo();
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo();
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.tableSize();

			Assert::AreEqual(0, i);
		}
		TEST_METHOD(tableSize)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.tableSize();

			Assert::AreEqual(0, i);
		}
		TEST_METHOD(getAttributesPlace)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(0, i);
			Assert::AreEqual(1, j);
			Assert::AreNotEqual(i, j);
		}
		TEST_METHOD(deleteAttribute)
		{
			// deleteAttribute
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.deleteAttribute("UIN");

			int i = table.getAttributesPlace("UIN");
			int j = table.getAttributesPlace("Age");

			Assert::AreNotEqual(1, i);
			Assert::AreEqual(j, -1);			// control error (there is not "Age' attributeInfo and trying to find it. Error => result is -1
		}
		TEST_METHOD(insertRecord)
		{
			// TODO
			DBMS::Record r = DBMS::Record();
			DBMS::Table test = DBMS::Table("Hello");
			test.insertRecord(r);

			int i = test.tableSize();
			Assert::AreEqual(1, i);
		}
		TEST_METHOD(renameAttributeInTable)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.renameAttributeInTable("UIN", "ID number");

			int i = table.getAttributesPlace("ID number");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(i, 1);
			Assert::AreEqual(j, -1);
		}
		TEST_METHOD(sum)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			//float g = (float)0;
			Assert::AreEqual(f, (float)-1);
		}
		TEST_METHOD(addNewAttribute)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.addNewAttribute("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreEqual(i, 2);
		}
		TEST_METHOD(insertAttributeInfo)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.insertAttributeInfo("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreEqual(i, 2);
		}
		TEST_METHOD(individualRecord)
		{
			// ** need modify **
			/*DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.individualRecord(1);*/
		}
		TEST_METHOD(getTableName)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			std::string s = table.getTableName();
			std::string ss = "Student";
			Assert::AreEqual(s, ss);
		}
		TEST_METHOD(changeTableName)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.changeTableName("TAMU Student");

			std::string s = table.getTableName();
			std::string ss = "TAMU Student";
			std::string sss = "Student";

			Assert::AreEqual(s, ss);
			Assert::AreNotEqual(s, sss);
		}
		TEST_METHOD(attributeTypeInfo)
		{
			//** need modify **//

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> va;
			va.push_back(attr1);
			va.push_back(attr2);
			std::string s1 = "Name";
			std::string s2 = "UIN";
			std::vector<std::string> vs;
			vs.push_back(s1);
			vs.push_back(s2);
			DBMS::Table table = DBMS::Table(va, "Student");

			table.attributeTypeInfo(vs, va);

			// I want to check 'attributeTypeInfo' function. However, the return type is void
			// How can I check?
		}
		TEST_METHOD(attributeInfoIndex)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoIndex("Name");
			int j = table.attributeInfoIndex("UIN");

			Assert::AreEqual(i, 0);
			Assert::AreEqual(j, 1);
		}
		TEST_METHOD(attributesToDelete)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			std::vector<std::string> va;
			std::vector<std::string> vs;
			va.push_back(attr1.getAttributeName());
			va.push_back(attr2.getAttributeName());
			vs.push_back(attr1.getAttributeType());
			vs.push_back(attr2.getAttributeType());

			DBMS::Table table = DBMS::Table(v, "Student");

			table.attributesToDelete(va, vs);

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			int k = table.tableSize();

			Assert::AreEqual(i, -1);
			Assert::AreEqual(j, -1);
			Assert::AreEqual(k, 0);
		}
		TEST_METHOD(attributeInfoSize)
		{
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoSize();

			Assert::AreEqual(i, 2);
		}

		//------------------------------------------------------------------------------

		// Record

		TEST_METHOD(addAttributeANDgetAttrib)
		{
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = "UIN";
			Assert::AreEqual(s, ex);
		}
		TEST_METHOD(returnAttribute)
		{
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(2);
			std::string s = attr1.getAttribute();
			std::string ss = "Major";

			Assert::AreEqual(s, ss);
		}
		TEST_METHOD(numberOfAttributes)
		{
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			int i = record.numberOfAttributes();

			record.removeAttribute(2);

			int j = record.numberOfAttributes();

			Assert::AreNotEqual(i, j);
			Assert::AreEqual(i-1, j);
		}

		//----------------------------------------------------------------

		// Database

		TEST_METHOD(addTableANDtableIndex)
		{
			// ** modify **

			// I don't know how to initialize Database

			// DBMS::Database database;

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v1;
			v1.push_back(attr1);
			v1.push_back(attr2);
			DBMS::Table studentTable = DBMS::Table(v1, "Student");

			DBMS::AttributeInfo attr3 = DBMS::AttributeInfo("Class", "string");
			DBMS::AttributeInfo attr4 = DBMS::AttributeInfo("Average", "int");
			DBMS::AttributeInfo attr5 = DBMS::AttributeInfo("Professor", "string");
			std::vector<DBMS::AttributeInfo> v2;
			v2.push_back(attr3);
			v2.push_back(attr4);
			v2.push_back(attr5);
			DBMS::Table gradeTable = DBMS::Table(v2, "Grade");

			DBMS::AttributeInfo attr6 = DBMS::AttributeInfo("Major", "string");
			DBMS::AttributeInfo attr7 = DBMS::AttributeInfo("Student", "string");
			std::vector<DBMS::AttributeInfo> v3;
			v3.push_back(attr6);
			v3.push_back(attr7);
			DBMS::Table deptTable = DBMS::Table(v3, "Department");

			std::vector<DBMS::Table> vectorTable;
			vectorTable.push_back(studentTable);
			vectorTable.push_back(gradeTable);
			vectorTable.push_back(deptTable);

			DBMS::AttributeInfo attr8 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr9 = DBMS::AttributeInfo("What", "int");
			std::vector<DBMS::AttributeInfo> v4;
			v4.push_back(attr8);
			v4.push_back(attr9);
			DBMS::Table petTable = DBMS::Table(v4, "Pet");

			// database.addTable(petTable, "Pet");
			// int i = database.tableIndex("Pet");
			// int j = 3;

			// Assert::AreEqual(i, j);
			
		}
		TEST_METHOD(dropTable)
		{
			// ** modify **
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v1;
			v1.push_back(attr1);
			v1.push_back(attr2);
			DBMS::Table studentTable = DBMS::Table(v1, "Student");

			DBMS::AttributeInfo attr3 = DBMS::AttributeInfo("Class", "string");
			DBMS::AttributeInfo attr4 = DBMS::AttributeInfo("Average", "int");
			DBMS::AttributeInfo attr5 = DBMS::AttributeInfo("Professor", "string");
			std::vector<DBMS::AttributeInfo> v2;
			v2.push_back(attr3);
			v2.push_back(attr4);
			v2.push_back(attr5);
			DBMS::Table gradeTable = DBMS::Table(v2, "Grade");

			DBMS::AttributeInfo attr6 = DBMS::AttributeInfo("Major", "string");
			DBMS::AttributeInfo attr7 = DBMS::AttributeInfo("Student", "string");
			std::vector<DBMS::AttributeInfo> v3;
			v3.push_back(attr6);
			v3.push_back(attr7);
			DBMS::Table deptTable = DBMS::Table(v3, "Department");

			std::vector<DBMS::Table> vectorTable;
			vectorTable.push_back(studentTable);
			vectorTable.push_back(gradeTable);
			vectorTable.push_back(deptTable);

			// database.dropTable("Grade");
		}
		TEST_METHOD(getTables)
		{
			// To do
		}
		TEST_METHOD(listTable)
		{
			// To do
		}
		TEST_METHOD(deleteTuples)
		{
			// To do
		}
	};
}