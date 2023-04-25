// Test.cpp
// License: Apache 2.0
// Copyright: 2023 Saurabh Suman <saurabh.smn@gmail.com>
// Info: You are free to use and modify the content as per
//       condition of Apache 2.0 licensing terms.
//       See LICENSE file for details

#include "TestExec.h"
#include <iostream>
#include <memory>
#include <vector>

std::unique_ptr<SmnTest::BigIntTest> TestAddition()
{
  auto tester = std::make_unique<SmnTest::TestAddition>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)100, (long long)101, (long long)201);
  tester->TestIt((long long)678, (long long)876, (long long)1554);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591195, (long long)-58365605339182390);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, (long long)0);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, (long long)20000000000000000);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775807"), std::string("18446744073709551614"));
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775807"), std::string("18446744073709551614"));
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), std::string("199989223372036854775807"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestSubstration()
{
  auto tester = std::make_unique<SmnTest::TestSubstration>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)100, (long long)101, (long long)-1);
  tester->TestIt((long long)101, (long long)100, (long long)1);
  tester->TestIt((long long)678, (long long)876, (long long)-198);
  tester->TestIt((long long)876, (long long)678, (long long)198);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591195, (long long)0);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591195, (long long)0);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, (long long)-58365605339182390);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, (long long)58365605339182390);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, (long long)-78365605339182390);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, (long long)20000000000000000);
  tester->TestIt(std::string("9223372036854775807"), std::string("-9223372036854775807"), std::string("18446744073709551614"));
  tester->TestIt(std::string("9223372036854775807"), std::string("-9223372036854775807"), std::string("18446744073709551614"));
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775807"), std::string("0"));
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), std::string("199989223372036854775807"));
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), std::string("9223372036854775807"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestMultiplication()
{
  auto tester = std::make_unique<SmnTest::TestMultiplication>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)100, (long long)101, (long long)10100);
  tester->TestIt((long long)876, (long long)678, (long long)593928);
  tester->TestIt(std::string("933866418"), std::string("987654321000"), std::string("922337202974492178000"));
  tester->TestIt(std::string("9338664180000000000000000"), std::string("987654321000000000000000000"), std::string("9223372029744921780000000000000000000000000000000000"));
  tester->TestIt((long long)876, (long long)-678, (long long)-593928);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestDivision()
{
  auto tester = std::make_unique<SmnTest::TestDivision>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)987654321000, (long long)256, (long long)3858024691);
  tester->TestIt((long long)100, (long long)101, (long long)0);
  tester->TestIt((long long)876, (long long)678, (long long)1);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591195, (long long)1);
  tester->TestIt(-(long long)29182802669591195, (long long)-1, (long long)29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)1, (long long)-29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, (long long)-1);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, (long long)-1);
  tester->TestIt(-(long long)29182802669591195, (long long)14591401334795597, (long long)-2);
  tester->TestIt((long long)29182802669591195, (long long)-14591401334795597, (long long)-2);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, (long long)0);
  tester->TestIt((long long)58365605339182390, (long long)29182802669591195, (long long)2);
  tester->TestIt(std::string("92233720297449217800000"), std::string("933866418"), std::string("98765432100000"));
  tester->TestIt(std::string("92233720297449217800000"), std::string("9876543210"), std::string("9338664180000"));
  tester->TestIt(std::string("92233720297449217800000"), std::string("0"), std::string("0"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestModulus()
{
  auto tester = std::make_unique<SmnTest::TestModulus>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)987654321000, (long long)256, (long long)104);
  tester->TestIt((long long)100, (long long)101, (long long)100);
  tester->TestIt((long long)876, (long long)678, (long long)198);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591195, (long long)0);
  tester->TestIt(-(long long)29182802669591195, (long long)-1, (long long)29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)1, (long long)29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, (long long)0);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, (long long)0);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, (long long)29182802669591195);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, (long long)20000000000000000);
  tester->TestIt(std::string("92233720297449217800100"), std::string("933866418"), std::string("100"));
  tester->TestIt(std::string("92233720297449217800010"), std::string("9876543210"), std::string("10"));
  tester->TestIt(std::string("92233720297449217800000"), std::string("0"), std::string("0"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestPreIncrement()
{
  auto tester = std::make_unique<SmnTest::TestPreIncrement>();
  tester->TestIt((long long)0, (long long)1, (long long)1);
  tester->TestIt(-(long long)1, (long long)0, (long long)0);
  tester->TestIt((long long)100, (long long)101, (long long)101);
  tester->TestIt((long long)678, (long long)679, (long long)679);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, (long long)29182802669591196);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591194, (long long)-29182802669591194);
  tester->TestIt(std::string("92233720297449217800100000"), std::string("92233720297449217800100001"), std::string("92233720297449217800100001"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestPostIncrement()
{
  auto tester = std::make_unique<SmnTest::TestPostIncrement>();
  tester->TestIt((long long)0, (long long)1, (long long)0);
  tester->TestIt(-(long long)1, (long long)0, (long long)-1);
  tester->TestIt((long long)100, (long long)101, (long long)100);
  tester->TestIt((long long)678, (long long)679, (long long)678);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, (long long)29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591194, (long long)-29182802669591195);
  tester->TestIt(std::string("92233720297449217800100000"), std::string("92233720297449217800100001"), std::string("92233720297449217800100000"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestPreDecrement()
{
  auto tester = std::make_unique<SmnTest::TestPreDecrement>();
  tester->TestIt((long long)1, (long long)0, (long long)0);
  tester->TestIt((long long)0, (long long)-1, (long long)-1);
  tester->TestIt(-(long long)1, (long long)-2, (long long)-2);
  tester->TestIt((long long)100, (long long)99, (long long)99);
  tester->TestIt((long long)678, (long long)677, (long long)677);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591194, (long long)29182802669591194);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591196, (long long)-29182802669591196);
  tester->TestIt(std::string("92233720297449217800100000"), std::string("92233720297449217800099999"), std::string("92233720297449217800099999"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestPostDecrement()
{
  auto tester = std::make_unique<SmnTest::TestPostDecrement>();
  tester->TestIt((long long)1, (long long)0, (long long)1);
  tester->TestIt((long long)0, (long long)-1, (long long)0);
  tester->TestIt(-(long long)1, (long long)-2, (long long)-1);
  tester->TestIt((long long)100, (long long)99, (long long)100);
  tester->TestIt((long long)678, (long long)677, (long long)678);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591194, (long long)29182802669591195);
  tester->TestIt(-(long long)29182802669591195, (long long)-29182802669591196, (long long)-29182802669591195);
  tester->TestIt(std::string("92233720297449217800100000"), std::string("92233720297449217800099999"), std::string("92233720297449217800100000"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestGreaterThan()
{
  auto tester = std::make_unique<SmnTest::TestGreaterThan>();
  tester->TestIt((long long)0, (long long)0, false);
  tester->TestIt((long long)100, (long long)101, false);
  tester->TestIt((long long)101, (long long)100, true);
  tester->TestIt((long long)678, (long long)876, false);
  tester->TestIt((long long)876, (long long)678, true);
  tester->TestIt((long long)678, (long long)-876, true);
  tester->TestIt(-(long long)876, (long long)678, false);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, false);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, false);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, true);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, false);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, true);
  tester->TestIt((long long)9223372036854775807, (long long)-9223372036854775800, true);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775807"), true);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), true);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestGreaterThanEqual()
{
  auto tester = std::make_unique<SmnTest::TestGreaterThanEqual>();
  tester->TestIt((long long)0, (long long)0, true);
  tester->TestIt((long long)100, (long long)101, false);
  tester->TestIt((long long)101, (long long)100, true);
  tester->TestIt((long long)678, (long long)876, false);
  tester->TestIt((long long)678, (long long)678, true);
  tester->TestIt((long long)876, (long long)678, true);
  tester->TestIt((long long)876, (long long)876, true);
  tester->TestIt((long long)876, (long long)-876, true);
  tester->TestIt(-(long long)678, (long long)678, false);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, false);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, false);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, true);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, false);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, true);
  tester->TestIt((long long)9223372036854775807, (long long)-9223372036854775800, true);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775807"), true);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), true);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestSmallerThan()
{
  auto tester = std::make_unique<SmnTest::TestSmallerThan>();
  tester->TestIt((long long)0, (long long)0, false);
  tester->TestIt((long long)100, (long long)101, true);
  tester->TestIt((long long)101, (long long)100, false);
  tester->TestIt((long long)678, (long long)876, true);
  tester->TestIt((long long)876, (long long)678, false);
  tester->TestIt((long long)678, (long long)-876, false);
  tester->TestIt(-(long long)876, (long long)678, true);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, true);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, true);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, false);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, true);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, false);
  tester->TestIt((long long)9223372036854775807, (long long)-9223372036854775800, false);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775807"), false);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), false);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestSmallerThanEqual()
{
  auto tester = std::make_unique<SmnTest::TestSmallerThanEqual>();
  tester->TestIt((long long)0, (long long)0, true);
  tester->TestIt((long long)100, (long long)101, true);
  tester->TestIt((long long)101, (long long)100, false);
  tester->TestIt((long long)678, (long long)876, true);
  tester->TestIt((long long)678, (long long)678, true);
  tester->TestIt((long long)876, (long long)678, false);
  tester->TestIt((long long)876, (long long)876, true);
  tester->TestIt((long long)876, (long long)-876,false);
  tester->TestIt(-(long long)678, (long long)678, true);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, true);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, true);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, false);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, true);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, false);
  tester->TestIt((long long)9223372036854775807, (long long)-9223372036854775800, false);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775807"), false);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99990000000000000000000"), false);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestEqual()
{
  auto tester = std::make_unique<SmnTest::TestEqual>();
  tester->TestIt((long long)0, (long long)0, true);
  tester->TestIt((long long)100, (long long)101, false);
  tester->TestIt((long long)101, (long long)100, false);
  tester->TestIt((long long)678, (long long)876, false);
  tester->TestIt((long long)876, (long long)678, false);
  tester->TestIt((long long)678, (long long)-678, false);
  tester->TestIt((long long)678, (long long)678, true);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, false);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591195, true);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, false);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, false);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, false);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, false);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775800"), true);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), false);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99999223372036854775807"), true);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestNotEqual()
{
  auto tester = std::make_unique<SmnTest::TestNotEqual>();
  tester->TestIt((long long)0, (long long)0, false);
  tester->TestIt((long long)100, (long long)101, true);
  tester->TestIt((long long)101, (long long)100, true);
  tester->TestIt((long long)678, (long long)876, true);
  tester->TestIt((long long)876, (long long)678, true);
  tester->TestIt((long long)678, (long long)-678, true);
  tester->TestIt((long long)678, (long long)678, false);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591196, true);
  tester->TestIt((long long)29182802669591195, (long long)29182802669591195, false);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195, true);
  tester->TestIt((long long)29182802669591195, (long long)-29182802669591195, true);
  tester->TestIt(-(long long)29182802669591195, (long long)49182802669591195, true);
  tester->TestIt((long long)49182802669591195, (long long)29182802669591195, true);
  tester->TestIt(std::string("-9223372036854775800"), std::string("-9223372036854775800"), false);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775800"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99990000000000000000000"), true);
  tester->TestIt(std::string("99999223372036854775807"), std::string("99999223372036854775807"), false);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestNegation()
{
  auto tester = std::make_unique<SmnTest::TestNegation>();
  tester->TestIt((long long)0, (long long)1);
  tester->TestIt((long long)100, (long long)0);
  tester->TestIt((long long)101, (long long)0);
  tester->TestIt((long long)678, (long long)0);
  tester->TestIt((long long)29182802669591195, (long long)0);
  tester->TestIt(std::string("99999223372036854775807"), std::string("0"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestNegative()
{
  auto tester = std::make_unique<SmnTest::TestNegative>();
  tester->TestIt((long long)0, (long long)0);
  tester->TestIt((long long)100, (long long)-100);
  tester->TestIt(-(long long)101, (long long)101);
  tester->TestIt((long long)678, (long long)-678);
  tester->TestIt(-(long long)29182802669591195, (long long)29182802669591195);
  tester->TestIt(std::string("99999223372036854775807"), std::string("-99999223372036854775807"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseAnd()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseAnd>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)38589, (long long)23350, (long long)4660);
  tester->TestIt((long long)100, (long long)101, (long long)100);
  tester->TestIt((long long)876, (long long)678, (long long)548);
  tester->TestIt((long long)933866418, (long long)987654321000, (long long)881369888);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775801"), std::string("9223372036854775801"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseOr()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseOr>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)38589, (long long)23350, (long long)57279);
  tester->TestIt((long long)100, (long long)101, (long long)101);
  tester->TestIt((long long)876, (long long)678, (long long)1006);
  tester->TestIt((long long)933866418, (long long)987654321000, (long long)987706817530);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775801"), std::string("9223372036854775807"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseXor()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseXor>();
  tester->TestIt((long long)0, (long long)0, (long long)0);
  tester->TestIt((long long)38589, (long long)23350, (long long)52619);
  tester->TestIt((long long)100, (long long)101, (long long)1);
  tester->TestIt((long long)876, (long long)678, (long long)458);
  tester->TestIt((long long)933866418, (long long)987654321000, (long long)986825447642);
  tester->TestIt(std::string("9223372036854775807"), std::string("9223372036854775801"), std::string("6"));
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseLeftShift()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseLeftShift>();
  tester->TestIt((long long)8388826, (long long)1, (long long)436);
  tester->TestIt((long long)8388826, (long long)15, (long long)7143424);
  tester->TestIt((long long)22205, (long long)1, (long long)44410);
  tester->TestIt((long long)1, (long long)22205, (long long)0);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseRightShift()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseRightShift>();
  tester->TestIt((long long)8388826, (long long)1, (long long)4194413);
  tester->TestIt((long long)8388826, (long long)15, (long long)256);
  tester->TestIt((long long)22205, (long long)1, (long long)11102);
  tester->TestIt((long long)1, (long long)22205, (long long)0);
  return std::move(tester);
}
std::unique_ptr<SmnTest::BigIntTest> TestBitwiseNegation()
{
  auto tester = std::make_unique<SmnTest::TestBitwiseNegation>();
  tester->TestIt((long long)0, (long long)255);
  tester->TestIt((long long)38589, (long long)26946);
  tester->TestIt((long long)100, (long long)155);
  tester->TestIt((long long)876, (long long)64659);
  tester->TestIt((long long)933866418, (long long)3361100877);
  return std::move(tester);
}

int main() {
  std::vector<std::unique_ptr<SmnTest::BigIntTest>> testers;
  testers.push_back(TestAddition());
  testers.push_back(TestSubstration());
  testers.push_back(TestMultiplication());
  testers.push_back(TestDivision());
  testers.push_back(TestModulus());
  testers.push_back(TestPreIncrement());
  testers.push_back(TestPostIncrement());
  testers.push_back(TestPreDecrement());
  testers.push_back(TestPostDecrement());
  testers.push_back(TestGreaterThan());
  testers.push_back(TestGreaterThanEqual());
  testers.push_back(TestSmallerThan());
  testers.push_back(TestSmallerThanEqual());
  testers.push_back(TestEqual());
  testers.push_back(TestNotEqual());
  testers.push_back(TestNegative());
  testers.push_back(TestNegation());
  testers.push_back(TestBitwiseAnd());
  testers.push_back(TestBitwiseOr());
  testers.push_back(TestBitwiseXor());
  testers.push_back(TestBitwiseLeftShift());
  testers.push_back(TestBitwiseRightShift());
  testers.push_back(TestBitwiseNegation());

  for (auto& tester: testers) {
    tester->Print();
  }
  return 0;
 }
