//
// ODBCTestSuite.cpp
//
// $Id: //poco/Main/Data/ODBC/testsuite/src/ODBCTestSuite.cpp#2 $
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "ODBCTestSuite.h"
#include "ODBCDB2Test.h"
#include "ODBCMySQLTest.h"
#include "ODBCOracleTest.h"
#include "ODBCPostgreSQLTest.h"
#include "ODBCSQLiteTest.h"
#if defined(POCO_OS_FAMILY_WINDOWS)
#include "ODBCAccessTest.h"
#endif
#include "ODBCSQLServerTest.h"


CppUnit::Test* ODBCTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ODBCTestSuite");

	// WARNING!
	// On Win XP Pro:
	//
	// 1) The PostgreSQL connection fails if attempted after DB2 w/ following error:
	// 
	// sqlState="IM003" 
	// message="Specified driver could not be loaded due to system error  127 (PostgreSQL ANSI)." 
	// nativeError=160 
	// System error 127 is "The specified procedure could not be found."
	//
	// 2) When Oracle test is loaded after DB2, the test application does not exit cleanly.
	//    All tests pass, though.
	//
	// Workaround is to connect to DB2 after connecting to PostgreSQL and Oracle.
	// The reason causing these errors is not known.

	addTest(pSuite, ODBCOracleTest::suite());
	addTest(pSuite, ODBCPostgreSQLTest::suite());
	addTest(pSuite, ODBCDB2Test::suite());
	addTest(pSuite, ODBCMySQLTest::suite());
	addTest(pSuite, ODBCSQLiteTest::suite());
	addTest(pSuite, ODBCSQLServerTest::suite());
#if defined(POCO_OS_FAMILY_WINDOWS)
	addTest(pSuite, ODBCAccessTest::suite());
#endif

	return pSuite;
}


void ODBCTestSuite::addTest(CppUnit::TestSuite* pSuite, CppUnit::Test* pT)
{
	if (pSuite && pT) pSuite->addTest(pT);
}
