#include "TestExec.h"
#include <iostream>
#include <iomanip>

namespace SmnTest {
BigIntTest::BigIntTest(std::string name)
  : testName(name)
  , testCount(0)
  , testPassed(0)
  , testFailed(0) {
}
void BigIntTest::TestIt(long long v1, long long v2, long long e) {
  Smn::BigInt n1(v1);
  Smn::BigInt n2(v2);
  Smn::BigInt ex(e);
  Test(n1, n2, ex);
}
void BigIntTest::TestIt(std::string v1, std::string v2, std::string e) {
  Smn::BigInt n1(v1);
  Smn::BigInt n2(v2);
  Smn::BigInt ex(e);
  Test(n1, n2, ex);
}
void BigIntTest::TestIt(long long v1, long long v2, bool e) {
  Smn::BigInt n1(v1);
  Smn::BigInt n2(v2);
  Test(n1, n2, e);
}
void BigIntTest::TestIt(std::string v1, std::string v2, bool e) {
  Smn::BigInt n1(v1);
  Smn::BigInt n2(v2);
  Test(n1, n2, e);
}
void BigIntTest::TestIt(long long v, long long e) {
  Smn::BigInt n(v);
  Smn::BigInt ex(e);
  Test(n, ex);
}
void BigIntTest::TestIt(std::string v, std::string e) {
  Smn::BigInt n(v);
  Smn::BigInt ex(e);
  Test(n, ex);
}
void BigIntTest::Print() {
  std::string name = std::string("[") + testName + std::string("]");
  std::cout << std::setw(32) << std::left << name <<
              " Total:  " << std::setw(10) << std::left << testCount << 
              " Passed: " << std::setw(10) << std::left << testPassed << 
              " Failed: " << std::setw(10) << std::left << testFailed << std::endl;
}

void BigIntTest::CheckResult(const Smn::BigInt& actual, const Smn::BigInt& expected) {
  testCount++;
  if (actual == expected) {
    testPassed++;
  } else {
    testFailed++;
  }
  std::cout << "  " << ((actual == expected) ? "[PASSED]" : "*****[FAILED]");
  std::cout << " [Expected:" << expected.getBigRep() << "]" << 
               " [Actual:" << actual.getBigRep() << "]" << std::endl;
}
void BigIntTest::CheckResult(bool actual, bool expected, std::string tag) {
  testCount++;
  if (actual == expected) {
    testPassed++;
  } else {
    testFailed++;
  }
  std::cout << "  " << tag << ((actual == expected) ? "[PASSED]" : "*****[FAILED]");
  std::cout << " [Expected:" << (expected ? "YES" : "NO") << "]" << 
               " [Actual:" << (actual ? "YES" : "NO") << "]" << std::endl;
}

TestBinaryOperations::TestBinaryOperations(std::string name) : BigIntTest(name) {
}
void TestBinaryOperations::Test(Smn::BigInt&, Smn::BigInt&, bool) {
}
void TestBinaryOperations::Test(Smn::BigInt&, Smn::BigInt&) {
}
void TestBinaryOperations::Test(Smn::BigInt&, int) {
}

void TestBinaryOperations::Print(Smn::BigInt& n1, Smn::BigInt& n2, std::string opStr) {
  std::cout << n1.getBigRep() << " " << opStr << " " << n2.getBigRep() << std::endl;
}
void TestBinaryOperations::PrintResult(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& r, Smn::BigInt& ex, std::string opStr) {
  Print(n1, n2, opStr);
  CheckResult(r, ex);
}

TestAddition::TestAddition() : TestBinaryOperations("Addition") {
}
void TestAddition::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r += n2;
  PrintResult(n1, n2, r, ex, "+=");
  r = n1 + n2;
  PrintResult(n1, n2, r, ex, "+");
}

TestSubstration::TestSubstration() : TestBinaryOperations("Substration") {
}
void TestSubstration::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r -= n2;
  PrintResult(n1, n2, r, ex, "-=");
  r = n1 - n2;
  PrintResult(n1, n2, r, ex, "-");
}

TestMultiplication::TestMultiplication() : TestBinaryOperations("Multiplication") {
}
void TestMultiplication::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r *= n2;
  PrintResult(n1, n2, r, ex, "*=");
  r = n1 * n2;
  PrintResult(n1, n2, r, ex, "*");
}

TestDivision::TestDivision() : TestBinaryOperations("Division") {
}
void TestDivision::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  try {
    Smn::BigInt r(n1);
    r /= n2;
    PrintResult(n1, n2, r, ex, "/=");
    CheckResult(false, (n2 == 0), "Exception Test");
    r = n1 / n2;
    PrintResult(n1, n2, r, ex, "/");
    CheckResult(false, (n2 == 0), "Exception Test");
  } catch(...) {
    Print(n1, n2, "/=");
    CheckResult(true, (n2 == 0), "Exception Test");
  }
}

TestModulus::TestModulus() : TestBinaryOperations("Modulus") {
}
void TestModulus::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  try {
    Smn::BigInt r(n1);
    r %= n2;
    PrintResult(n1, n2, r, ex, "%=");
    CheckResult(false, (n2 == 0), "Exception Test");
    r = n1 % n2;
    PrintResult(n1, n2, r, ex, "%");
    CheckResult(false, (n2 == 0), "Exception Test");
  } catch(...) {
    Print(n1, n2, "/=");
    CheckResult(true, (n2 == 0), "Exception Test");
  }
}

TestUnaryOperation::TestUnaryOperation(std::string name, bool pre)
  : BigIntTest(name)
  , isPre(pre) {
}
void TestUnaryOperation::CheckResult(Smn::BigInt& n, Smn::BigInt& nex, Smn::BigInt& r, Smn::BigInt& rex) {
  std::cout << "ORIGINAL ::";
  BigIntTest::CheckResult(n, nex);
  std::cout << "RESULTANT::";
  BigIntTest::CheckResult(r, rex);
}
void TestUnaryOperation::Test(Smn::BigInt&, Smn::BigInt&, Smn::BigInt&) {
}
void TestUnaryOperation::Test(Smn::BigInt&, Smn::BigInt&, bool) {
}
void TestUnaryOperation::Test(Smn::BigInt&, Smn::BigInt&) {
}
void TestUnaryOperation::Test(Smn::BigInt&, int) {
}
void TestUnaryOperation::Print(Smn::BigInt& n, std::string opStr) {
  if (isPre) {
    std::cout << opStr << n.getBigRep() << std::endl;
  } else {
    std::cout << n.getBigRep() << opStr << std::endl;
  }
}
void TestUnaryOperation::PrintResult(Smn::BigInt& o, Smn::BigInt& n, Smn::BigInt& nex, Smn::BigInt& r, Smn::BigInt& rex, std::string opStr) {
  Print(o, opStr);
  CheckResult(n, nex, r, rex);
}
void TestUnaryOperation::PrintResult(Smn::BigInt& n, Smn::BigInt& r, Smn::BigInt& ex, std::string opStr) {
  Print(n, opStr);
  BigIntTest::CheckResult(r, ex);
}

TestPreIncrement::TestPreIncrement() : TestUnaryOperation("PreIncrement", true) {
}
void TestPreIncrement::Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) {
  Smn::BigInt n(v);
  Smn::BigInt b(n);
  Smn::BigInt r(n);
  Smn::BigInt nex(ne);
  Smn::BigInt rex(re);
  r = ++n;
  PrintResult(b, n, nex, r, rex, "++");
}

TestPostIncrement::TestPostIncrement() : TestUnaryOperation("PostIncrement", false) {
}
void TestPostIncrement::Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) {
  Smn::BigInt n(v);
  Smn::BigInt b(n);
  Smn::BigInt r(n);
  Smn::BigInt nex(ne);
  Smn::BigInt rex(re);
  r = n++;
  PrintResult(b, n, nex, r, rex, "++");
}

TestPreDecrement::TestPreDecrement() : TestUnaryOperation("PreDecrement", true) {
}
void TestPreDecrement::Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) {
  Smn::BigInt n(v);
  Smn::BigInt b(n);
  Smn::BigInt r(n);
  Smn::BigInt nex(ne);
  Smn::BigInt rex(re);
  r = --n;
  PrintResult(b, n, nex, r, rex, "--");
}

TestPostDecrement::TestPostDecrement() : TestUnaryOperation("PostDecrement", false) {
}
void TestPostDecrement::Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) {
  Smn::BigInt n(v);
  Smn::BigInt b(n);
  Smn::BigInt r(n);
  Smn::BigInt nex(ne);
  Smn::BigInt rex(re);
  r = n--;
  PrintResult(b, n, nex, r, rex, "--");
}

TestComparision::TestComparision(std::string name) : BigIntTest(name) {
}
void TestComparision::Test(Smn::BigInt&, Smn::BigInt&, Smn::BigInt&) {
}
void TestComparision::Test(Smn::BigInt&, Smn::BigInt&) {
}
void TestComparision::Test(Smn::BigInt&, int) {
}
void TestComparision::PrintResult(Smn::BigInt& n1, Smn::BigInt& n2, bool r, bool ex, std::string opStr) {
  std::cout << n1.getBigRep() << " " << opStr << " " << n2.getBigRep() << std::endl;
  CheckResult(r, ex);
}

TestGreaterThan::TestGreaterThan() : TestComparision("GreaterThan") {
}
void TestGreaterThan::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 > n2);
  PrintResult(n1, n2, r, e, ">");
}

TestGreaterThanEqual::TestGreaterThanEqual() : TestComparision("GreaterThanEqual") {
}
void TestGreaterThanEqual::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 >= n2);
  PrintResult(n1, n2, r, e, ">=");
}

TestSmallerThan::TestSmallerThan() : TestComparision("SmallerThan") {
}
void TestSmallerThan::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 < n2);
  PrintResult(n1, n2, r, e, "<");
}

TestSmallerThanEqual::TestSmallerThanEqual() : TestComparision("SmallerThanEqual") {
}
void TestSmallerThanEqual::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 <= n2);
  PrintResult(n1, n2, r, e, "<=");
}

TestEqual::TestEqual() : TestComparision("Equal") {
}
void TestEqual::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 == n2);
  PrintResult(n1, n2, r, e, "==");
}

TestNotEqual::TestNotEqual() : TestComparision("NotEqual") {
}
void TestNotEqual::Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) {
  bool r = (n1 != n2);
  PrintResult(n1, n2, r, e, "!=");
}

TestNegation::TestNegation() : TestUnaryOperation("Negation", true) {
}
void TestNegation::Test(Smn::BigInt& n, Smn::BigInt& ex) {
  Smn::BigInt r1 = !n;
  PrintResult(n, r1, ex, "!");

  Smn::BigInt r2 = !r1;
  Smn::BigInt ex1(1);
  if (ex != 0) {
    ex1 = 0;
  }
  PrintResult(r1, r2, ex1, "Counter !");
}

TestNegative::TestNegative() : TestUnaryOperation("Negative", true) {
}
void TestNegative::Test(Smn::BigInt& n, Smn::BigInt& ex) {
  Smn::BigInt r1 = -n;
  PrintResult(n, r1, ex, "(-)");

  Smn::BigInt r2 = -r1;
  PrintResult(r1, r2, n, "Counter (-)");
}

TestBitwiseAnd::TestBitwiseAnd() : TestBinaryOperations("AND") {
}
void TestBitwiseAnd::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r = n1 & n2;
  PrintResult(n1, n2, r, ex, "&");
}

TestBitwiseOr::TestBitwiseOr() : TestBinaryOperations("OR") {
}
void TestBitwiseOr::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r = n1 | n2;
  PrintResult(n1, n2, r, ex, "|");
}

TestBitwiseXor::TestBitwiseXor() : TestBinaryOperations("XOR") {
}
void TestBitwiseXor::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r(n1);
  r = n1 ^ n2;
  PrintResult(n1, n2, r, ex, "^");
}

TestBitwiseLeftShift::TestBitwiseLeftShift() : TestBinaryOperations("LeftShift") {
}
void TestBitwiseLeftShift::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r = n1 << n2.getInt();
  PrintResult(n1, n2, r, ex, "<<");
}

TestBitwiseRightShift::TestBitwiseRightShift() : TestBinaryOperations("RightShift") {
}
void TestBitwiseRightShift::Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) {
  Smn::BigInt r = n1 >> n2.getInt();
  PrintResult(n1, n2, r, ex, ">>");
}

TestBitwiseNegation::TestBitwiseNegation() : TestUnaryOperation("BitwiseNegation", true) {
}
void TestBitwiseNegation::Test(Smn::BigInt& n, Smn::BigInt& ex) {
  Smn::BigInt r = ~n;
  PrintResult(n, r, ex, "~");
}

}
