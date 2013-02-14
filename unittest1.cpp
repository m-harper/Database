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
		
		TEST_METHOD(TestMethod1)
		{
			DBMS::Table test = DBMS::Table("Hello");
			int i = test.tableSize();
			int j = test.tableSize();

			Assert::AreEqual(0,j);

		}
		TEST_METHOD(TestMethod2)
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
		TEST_METHOD(TestMethod3)
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
		TEST_METHOD(TestMethod4)
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
		TEST_METHOD(TestMethod6)
		{
			// TODO
			DBMS::Record r = DBMS::Record();
			DBMS::Table test = DBMS::Table("Hello");
			test.insertRecord(r);

			int i = test.tableSize();
			Assert::AreEqual(1, i);
		}
		TEST_METHOD(TestMethod7)
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
		TEST_METHOD(TestMethod8)
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
		TEST_METHOD(TestMethod9)
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
		TEST_METHOD(TestMethod10)
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
		TEST_METHOD(TestMethod11)
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
		TEST_METHOD(TestMethod12)
		{

		}
		TEST_METHOD(TestMethod13)
		{

		}
		TEST_METHOD(TestMethod14)
		{

		}
		TEST_METHOD(TestMethod15)
		{

		}
		TEST_METHOD(TestMethod16)
		{

		}
		TEST_METHOD(TestMethod17)
		{

		}
		TEST_METHOD(TestMethod18)
		{

		}
		TEST_METHOD(TestMethod19)
		{

		}
		TEST_METHOD(TestMethod20)
		{

		}
	};
}