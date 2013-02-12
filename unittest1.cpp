#include "stdafx.h"
#include "CppUnitTest.h"
#include "Database.h"
#include "Table.h"
#include "Record.h"
#include "Attribute.h"
#include "AttributeInfo.h"
#include "Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DBMS;

namespace T27UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Table test = Table("Hello");
			int i = test.tableSize();
			int j = test.tableSize();

			Assert::AreEqual(i,j);

			// TODO: Your test code here
		}

	};
}