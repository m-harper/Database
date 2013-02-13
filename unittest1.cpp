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
		TEST_METHOD(TestMerhod2)
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
		TEST_METHOD(TestMerhod3)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.tableSize();

			Assert::AreEqual(0, i);
		}
		TEST_METHOD(TestMerhod4)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			int i = table.getAttributesPlace("Name");
			int j = table.getAttributesPlace("UIN");

			Assert::AreEqual(0, i);
			Assert::AreEqual(1, j);
			Assert::AreNotEqual(i, j);
		}
		TEST_METHOD(TestMerhod5)
		{
			// TODO
			DBMS::AttributeInfo attr1 = DBMS::AttributeInfo("Name", "string");
			DBMS::AttributeInfo attr2 = DBMS::AttributeInfo("UIN", "int");
			std::vector<DBMS::AttributeInfo> v;
			v.push_back(attr1);
			v.push_back(attr2);
			DBMS::Table table = DBMS::Table(v, "Default AttributeInfo");

			table.deleteAttribute("UIN");

			int i = table.getAttributesPlace("UIN");

			Assert::AreNotEqual(1, i);
		}
		TEST_METHOD(TestMerhod6)
		{
			// TODO
		}
	};
}