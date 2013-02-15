#include "stdafx.h"
#include "CppUnitTest.h"
#include "Database.h"
#include "Table.h"
#include "Record.h"
#include "Attribute.h"
#include "AttributeInfo.h"
#include "Date.h"

// Note, available assert types:
// AreEqual, AreNotEqual, AreSame, AreNotSame, Fail
// IsFalse, IsTrue, IsInstanceOfType, IsNotInstanceOfType, IsNull, IsNotNull,
// 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace T27UnitTest {

	TEST_CLASS(UnitTest1) {

	public:
		
		// Table.h

		TEST_METHOD(tableSizeDefaultTable1) {

			DBMS::Table test1 = DBMS::Table("Hello");

			int i = test1.tableSize();
			Assert::AreEqual(i,0);

			

		}

		TEST_METHOD(tableSizeDefaultTable2) {

			DBMS::Table test1 = DBMS::Table("Hello");

			std::string i = test1.getTableName();
			std::string j = "Hello";
			Assert::AreEqual(i,j);

		}

		TEST_METHOD(tableSizeDefaultTable3) {

			DBMS::Table test1 = DBMS::Table("Hello");
			DBMS::Table test2 = DBMS::Table("World");

			int i = test1.tableSize();
			int j = test2.tableSize();
			Assert::AreEqual(i,j);

		}

		TEST_METHOD(tableSizeDefaultTable4) {

			DBMS::Table test1 = DBMS::Table("Hello");
			DBMS::Table test2 = DBMS::Table("World");

			std::string k = test1.getTableName();
			std::string l = test2.getTableName();
			Assert::AreNotEqual(k,l);

		}

		TEST_METHOD(tableSizeDefaultAttributeInfo1) {
			
			DBMS::AttributeInfo attr = DBMS::AttributeInfo();
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr);

			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.tableSize();
			Assert::AreEqual(0, i);
		}

		TEST_METHOD(tableSizeDefaultAttributeInfo2) {
			
			DBMS::AttributeInfo attr = DBMS::AttributeInfo();
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr);

			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.tableSize();
			int j = table.tableSize();
			Assert::AreEqual(i, j);
		}

		TEST_METHOD(tableSizeDefaultAttributeInfo3) {
			
			DBMS::AttributeInfo attr = DBMS::AttributeInfo();
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr);

			DBMS::Table table1 = DBMS::Table(v, "Default AttributeInfo");
			DBMS::Table table2 = DBMS::Table(v, "Another AttributeInfo");

			int i = table1.tableSize();
			int j = table2.tableSize();
			Assert::AreEqual(i, j);
		}

		TEST_METHOD(tableSizeDefaultAttributeInfo4) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo();
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo();
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);

			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.tableSize();
			Assert::AreEqual(0, i);
		}

		TEST_METHOD(tableSize1) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.tableSize();

			Assert::AreEqual(0, i);
		}

		TEST_METHOD(tableSize2) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.tableSize();
			int j = table.tableSize();

			Assert::AreEqual(i, j);
		}

		TEST_METHOD(tableSize3) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table1 = DBMS::Table(v, "Student");
			DBMS::Table table2 = DBMS::Table(v, "Student");

			int i = table1.tableSize();
			int j = table2.tableSize();

			Assert::AreEqual(i, j);
		}

		TEST_METHOD(tableSize4) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table1 = DBMS::Table(v, "Student");

			DBMS::AttributeInfo attr3 = DBMS::AttributeInfo("Profession", "string");
			DBMS::AttributeInfo attr4 = DBMS::AttributeInfo("Department", "int");
			std::vector<DBMS::AttributeInfo> w;
			w.push_back(attr3);
			w.push_back(attr4);
			DBMS::Table table2 = DBMS::Table(w, "Professor");

			int i = table1.tableSize();
			int j = table2.tableSize();

			Assert::AreEqual(0, i);
		}

		TEST_METHOD(getAttributesPlace1) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(0, i);
		}

		TEST_METHOD(getAttributesPlace2) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(1, j);
		}

		TEST_METHOD(getAttributesPlace3) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(getAttributesPlace4) {
			
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreNotEqual(1, i);
		}

		TEST_METHOD(deleteAttribute1) {

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
		}

		TEST_METHOD(deleteAttribute2) {

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

			// control error (there is not "Age' attributeInfo and trying to find it. Error => result is -1
			Assert::AreEqual(j, -1);
		}

		TEST_METHOD(deleteAttribute3) {

			// deleteAttribute
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.deleteAttribute("UIN");

			int i = table.getAttributesPlace("UIN");
			int j = table.getAttributesPlace("Name");

			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(deleteAttribute4) {

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

			Assert::AreNotEqual(j, 1);
		}

		TEST_METHOD(insertRecord1) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Table test = DBMS::Table("Hello");
			test.insertRecord(r);

			int i = test.tableSize();
			Assert::AreNotEqual(0, i);
		}

		TEST_METHOD(insertRecord2) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Table test = DBMS::Table("Hello");
			test.insertRecord(r);

			int i = test.tableSize();
			Assert::AreEqual(1, i);
		}

		TEST_METHOD(insertRecord3) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Table test1 = DBMS::Table("Hello");
			test1.insertRecord(r);

			DBMS::Table test2 = DBMS::Table("Hello");
			test2.insertRecord(r);

			int i = test1.tableSize();
			int j = test2.tableSize();
			Assert::AreEqual(i, j);
		}

		TEST_METHOD(insertRecord4) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Table test1 = DBMS::Table("Hello");
			test1.insertRecord(r);

			DBMS::Record s = DBMS::Record();
			DBMS::Table test2 = DBMS::Table("Hello");
			test2.insertRecord(s);

			int i = test1.tableSize();
			int j = test2.tableSize();
			Assert::AreEqual(i, j);
		}

		TEST_METHOD(insertRecord5) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Table test1 = DBMS::Table("Hello");
			test1.insertRecord(r);

			DBMS::Record s = DBMS::Record();
			DBMS::Table test2 = DBMS::Table("Hello");
			test2.insertRecord(r);
			test2.insertRecord(s);

			int i = test1.tableSize();
			int j = test2.tableSize();
			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(insertRecord6) {
			
			DBMS::Record r = DBMS::Record();
			DBMS::Record s = DBMS::Record();
			DBMS::Table test1 = DBMS::Table("Hello");
			test1.insertRecord(r);
			test1.insertRecord(s);

			DBMS::Table test2 = DBMS::Table("Hello");
			test2.insertRecord(r);
			test2.insertRecord(s);

			int i = test1.tableSize();
			int j = test2.tableSize();
			Assert::AreEqual(i, j);
		}

		TEST_METHOD(renameAttributeInTable1) {
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
		}

		TEST_METHOD(renameAttributeInTable2) {
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.renameAttributeInTable("UIN", "ID number");

			int i = table.getAttributesPlace("ID number");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(j, -1);
		}

		TEST_METHOD(renameAttributeInTable3) {
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.renameAttributeInTable("Name", "ID number");

			int i = table.getAttributesPlace("ID number");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(i, 0);
		}

		TEST_METHOD(renameAttributeInTable4) {
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.renameAttributeInTable("Name", "ID number");

			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(j, 1);
		}

		TEST_METHOD(sum1) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			Assert::AreEqual(f, (float) -1);
		}

		TEST_METHOD(sum2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			float g = 0;
			Assert::AreNotEqual(f, g);
		}

		TEST_METHOD(sum3) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			float g = -1;
			Assert::AreEqual(f, g);
		}

		TEST_METHOD(sum4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("UIN");
			Assert::AreEqual(f, (float) 0);
		}

		TEST_METHOD(sum5) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr2);
			v.push_back(attr1);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			Assert::AreEqual(f, (float)-1);
		}

		TEST_METHOD(sum6) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr2);
			v.push_back(attr1);
			DBMS::Table table = DBMS::Table(v, "Student");

			float f = table.sum("Name");
			float g = 0;
			Assert::AreNotEqual(f, g);
		}

		TEST_METHOD(addNewAttribute1) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.addNewAttribute("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 0);
		}

		TEST_METHOD(addNewAttribute2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.addNewAttribute("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 1);
		}

		TEST_METHOD(addNewAttribute3) {

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

		TEST_METHOD(addNewAttribute4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.addNewAttribute("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 3);
		}

		TEST_METHOD(insertAttributeInfo1) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.insertAttributeInfo("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 0);
		}

		TEST_METHOD(insertAttributeInfo2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.insertAttributeInfo("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 1);
		}

		TEST_METHOD(insertAttributeInfo3) {

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

		TEST_METHOD(insertAttributeInfo4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.insertAttributeInfo("Major", "string");

			int i = table.getAttributesPlace("Major");

			Assert::AreNotEqual(i, 3);
		}

		TEST_METHOD(getTableName1) {

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

		TEST_METHOD(getTableName2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			std::string s = table.getTableName();
			std::string ss = "Professor";
			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(getTableName3) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			std::string s = table.getTableName();
			std::string ss = table.getTableName();
			Assert::AreEqual(s, ss);
		}

		TEST_METHOD(getTableName4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table1 = DBMS::Table(v, "Student");
			DBMS::Table table2 = DBMS::Table(v, "Student");

			std::string s = table1.getTableName();
			std::string ss = table2.getTableName();
			Assert::AreEqual(s, ss);
		}

		TEST_METHOD(changeTableName1) {

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
		}

		TEST_METHOD(changeTableName2) {

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

			Assert::AreNotEqual(s, sss);
		}

		TEST_METHOD(changeTableName3) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.changeTableName("Student");

			std::string s = table.getTableName();
			std::string sss = "Student";

			Assert::AreEqual(s, sss);
		}

		TEST_METHOD(changeTableName4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			table.changeTableName("TAMU Student");

			std::string s = table.getTableName();
			std::string ss = table.getTableName();

			Assert::AreEqual(s, ss);
		}

		TEST_METHOD(attributeTypeInfo1) {
			
			// TODO
			// There is no explanation of how this function works.
			// You may need to write a test for this yourselves.

			Assert::Fail();
		}

		TEST_METHOD(attributeTypeInfo2) {
			
			// TODO
			// There is no explanation of how this function works.
			// You may need to write a test for this yourselves.

			Assert::Fail();
		}

		TEST_METHOD(attributeTypeInfo3) {
			
			// TODO
			// There is no explanation of how this function works.
			// You may need to write a test for this yourselves.

			Assert::Fail();
		}

		TEST_METHOD(attributeTypeInfo4) {
			
			// TODO
			// There is no explanation of how this function works.
			// You may need to write a test for this yourselves.

			Assert::Fail();
		}
		
		TEST_METHOD(attributeInfoIndex1) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoIndex("Name");
			int j = table.attributeInfoIndex("UIN");

			Assert::AreEqual(i, 0);
		}

		TEST_METHOD(attributeInfoIndex2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoIndex("Name");
			int j = table.attributeInfoIndex("UIN");

			Assert::AreEqual(j, 1);
		}

		TEST_METHOD(attributeInfoIndex3) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoIndex("Name");
			int j = table.attributeInfoIndex("UIN");

			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(attributeInfoIndex4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoIndex("Name");
			int j = table.attributeInfoIndex("Name");

			Assert::AreEqual(i, j);
		}

		TEST_METHOD(attributesToDelete1) {

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
		}

		TEST_METHOD(attributesToDelete2) {

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

			Assert::AreEqual(j, -1);
		}

		TEST_METHOD(attributesToDelete3) {

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

			Assert::AreEqual(k, 0);
		}

		TEST_METHOD(attributesToDelete4) {

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

			Assert::AreNotEqual(i, k);
		}

		TEST_METHOD(attributeInfoSize1) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoSize();

			Assert::AreNotEqual(i, 0);
		}

		TEST_METHOD(attributeInfoSize2) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoSize();

			Assert::AreNotEqual(i, 1);
		}

		TEST_METHOD(attributeInfoSize3) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoSize();

			Assert::AreEqual(i, 2);
		}

		TEST_METHOD(attributeInfoSize4) {

			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Student");

			int i = table.attributeInfoSize();

			Assert::AreNotEqual(i, 3);
		}

		//------------------------------------------------------------------------------

		// Record

		TEST_METHOD(addAttributeANDgetAttrib1) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = "Name";
			Assert::AreNotEqual(s, ex);
		}

		TEST_METHOD(addAttributeANDgetAttrib2) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = "UIN";
			Assert::AreEqual(s, ex);
		}

		TEST_METHOD(addAttributeANDgetAttrib3) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = "Major";
			Assert::AreNotEqual(s, ex);
		}

		TEST_METHOD(addAttributeANDgetAttrib4) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = "Minor";
			Assert::AreNotEqual(s, ex);
		}

		TEST_METHOD(addAttributeANDgetAttrib5) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(0);
			std::string ex = record.getAttrib(1);
			Assert::AreNotEqual(s, ex);
		}

		TEST_METHOD(addAttributeANDgetAttrib6) {
			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			std::string s = record.getAttrib(1);
			std::string ex = record.getAttrib(1);
			Assert::AreEqual(s, ex);
		}

		TEST_METHOD(returnAttribute1) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(2);
			std::string s = attr1.getAttribute();
			std::string ss = "Name";

			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(returnAttribute2) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(2);
			std::string s = attr1.getAttribute();
			std::string ss = "UIN";

			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(returnAttribute3) {

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

		TEST_METHOD(returnAttribute4) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(2);
			std::string s = attr1.getAttribute();
			std::string ss = "Minor";

			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(returnAttribute5) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(0);
			std::string s = attr1.getAttribute();
			std::string ss = "Major";

			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(returnAttribute6) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			DBMS::Attribute attr1 = record.returnAttribute(1);
			std::string s = attr1.getAttribute();
			std::string ss = "Major";

			Assert::AreNotEqual(s, ss);
		}

		TEST_METHOD(numberOfAttributes1) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			int i = record.numberOfAttributes();

			record.removeAttribute(2);

			int j = record.numberOfAttributes();

			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(numberOfAttributes2) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			int i = record.numberOfAttributes();

			record.removeAttribute(2);

			int j = record.numberOfAttributes();

			Assert::AreEqual(i-1, j);
		}

		TEST_METHOD(numberOfAttributes3) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			int i = record.numberOfAttributes();

			record.removeAttribute(2);
			record.removeAttribute(0);

			int j = record.numberOfAttributes();

			Assert::AreNotEqual(i, j);
		}

		TEST_METHOD(numberOfAttributes4) {

			DBMS::Record record = DBMS::Record();
			record.addAttribute("Name");
			record.addAttribute("UIN");
			record.addAttribute("Major");
			record.addAttribute("Minor");

			int i = record.numberOfAttributes();

			record.removeAttribute(2);
			record.removeAttribute(0);

			int j = record.numberOfAttributes();

			Assert::AreEqual(i-2, j);
		}

		//----------------------------------------------------------------

		// Database

		TEST_METHOD(addTableANDtableIndex1) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier.
			//-------------------------------------------------------------------
			// database.addTable(petTable, "Pet");
			// int i = database.tableIndex("Pet");
			// int j = 1;
			// Assert::AreNotEqual(i, j);
			//-------------------------------------------------------------------

			// Be sure to remove the following or the test will always fail.
			Assert::Fail();
			
		}

		TEST_METHOD(addTableANDtableIndex2) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier.
			//-------------------------------------------------------------------
			// database.addTable(petTable, "Pet");
			// int i = database.tableIndex("Pet");
			// int j = 2;
			// Assert::AreNotEqual(i, j);
			//-------------------------------------------------------------------

			// Be sure to remove the following or the test will always fail.
			Assert::Fail();
			
		}

		TEST_METHOD(addTableANDtableIndex3) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier.
			//-------------------------------------------------------------------
			// database.addTable(petTable, "Pet");
			// int i = database.tableIndex("Pet");
			// int j = 3;
			// Assert::AreEqual(i, j);
			//-------------------------------------------------------------------

			// Be sure to remove the following or the test will always fail.
			Assert::Fail();
			
		}

		TEST_METHOD(addTableANDtableIndex4) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier.
			//-------------------------------------------------------------------
			// database.addTable(petTable, "Pet");
			// int i = database.tableIndex("Pet");
			// int j = 4;
			// Assert::AreNotEqual(i, j);
			//-------------------------------------------------------------------

			// Be sure to remove the following or the test will always fail.
			Assert::Fail();
			
		}

		TEST_METHOD(dropTable1) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");

			// database.dropTable("Grade");

			// i = database.tableIndex("Department");
			// Assert::AreEqual(1, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(dropTable2) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");

			// database.dropTable("Grade");
			// database.dropTable("Student");

			// i = database.tableIndex("Department");
			// Assert::AreEqual(0, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(dropTable3) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// int i = database.tableIndex("Department");
			// Assert::AreEqual(2, i);

			// database.dropTable("Department");

			// i = database.tableIndex("Department");
			// Assert::AreEqual(-1, i); // We're guessing it returns -1 if not found?
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(dropTable4) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// int i = database.tableIndex("Department");
			// Assert::AreEqual(2, i);

			// database.dropTable("Student");

			// i = database.tableIndex("Student");
			// Assert::AreEqual(-1, i); // We're guessing it returns -1 if not found?
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(getTables1) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// getTables(vectorTable);

			// int i = vectorTables.size();
			// Assert::AreEqual(3, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(getTables2) {

			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.
			
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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// getTables(vectorTable);

			// int i = vectorTables.size();
			// Assert::AreNotEqual(2, i);
			// Assert::AreNotEqual(1, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(getTables3) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.
			
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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// getTables(vectorTable);

			// database.dropTable("Student");

			// getTables(vectorTable);

			// int i = vectorTables.size();
			// Assert::AreNotEqual(3, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(getTables4) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.
			
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

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// getTables(vectorTable);

			// database.dropTable("Student");

			// getTables(vectorTable);

			// int i = vectorTables.size();
			// Assert::AreEqual(2, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(listTable1) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			std::vector<std::string> stringTable;

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// listTables(stringTable);

			// int i = stringTables.size();
			// Assert::AreEqual(3, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(listTable2) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			std::vector<std::string> stringTable;

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// listTables(stringTable);

			// int i = stringTables.size();
			// Assert::AreNotEqual(2, i);
			// Assert::AreNotEqual(1, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(listTable3) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			std::vector<std::string> stringTable;

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// listTables(stringTable);

			// database.dropTable("Student");

			// listTables(stringTable);

			// int i = stringTables.size();
			// Assert::AreNotEqual(3, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

		TEST_METHOD(listTable4) {
			
			//TODO
			// We don't know how to initialize the database.
			// Please initialize the database here and then
			//    uncomment the items at the end of the test.

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

			std::vector<std::string> stringTable;

			// After initializing the database, uncomment the following and refer
			//    to 'database' as the database you initilized earlier:
			//-------------------------------------------------------------------
			// database.addTable(v1, "Student");
			// database.addTable(v2, "Grade");
			// database.addTable(v3, "Department");
			
			// listTables(stringTable);

			// database.dropTable("Student");

			// listTables(stringTable);

			// int i = stringTables.size();
			// Assert::AreEqual(2, i);
			//-------------------------------------------------------------------

			// Remove the following or else the test will always fail.
			Assert::Fail();
		}

	};
}