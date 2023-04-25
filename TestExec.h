// TestExec.h
// License: Apache 2.0
// Copyright: 2023 Saurabh Suman <saurabh.smn@gmail.com>
// Info: You are free to use and modify the content as per
//       condition of Apache 2.0 licensing terms.
//       See LICENSE file for details

#include "../BigInt.h"

namespace SmnTest {
class BigIntTest {
public:
  BigIntTest(std::string name);
  virtual ~BigIntTest() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) = 0;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) = 0;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& e) = 0;
  virtual void Test(Smn::BigInt&, int) = 0;
  virtual void TestIt(long long v1, long long v2, long long e);
  virtual void TestIt(std::string v1, std::string v2, std::string e);
  virtual void TestIt(long long v1, long long v2, bool e);
  virtual void TestIt(std::string v1, std::string v2, bool e);
  virtual void TestIt(long long v, long long e);
  virtual void TestIt(std::string v, std::string e);

  void Print();
protected:
  virtual void CheckResult( const Smn::BigInt& actual,
                            const Smn::BigInt& expected);
  virtual void CheckResult( bool actual,
                            bool expected,
                            std::string tag = "");
private:
  std::string testName;
  unsigned int testCount;
  unsigned int testPassed;
  unsigned int testFailed;
};

class TestBinaryOperations : public BigIntTest {
public:
  TestBinaryOperations(std::string name);
  virtual ~TestBinaryOperations() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& e) override;
  virtual void Test(Smn::BigInt&, int) override;
protected:
  void Print( Smn::BigInt& n1,
              Smn::BigInt& n2,
              std::string opStr);
  void PrintResult( Smn::BigInt& n1,
                    Smn::BigInt& n2,
                    Smn::BigInt& r,
                    Smn::BigInt& ex,
                    std::string opStr);
};

class TestAddition : public TestBinaryOperations {
public:
  TestAddition();
  virtual ~TestAddition() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestSubstration : public TestBinaryOperations {
public:
  TestSubstration();
  virtual ~TestSubstration() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestMultiplication : public TestBinaryOperations {
public:
  TestMultiplication();
  virtual ~TestMultiplication() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestDivision : public TestBinaryOperations {
public:
  TestDivision();
  virtual ~TestDivision() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestModulus : public TestBinaryOperations {
public:
  TestModulus();
  virtual ~TestModulus() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestUnaryOperation : public BigIntTest {
public:
  TestUnaryOperation(std::string name, bool pre);
  virtual ~TestUnaryOperation() = default;
  virtual void Test(Smn::BigInt&, Smn::BigInt&, Smn::BigInt&) override;
  virtual void Test(Smn::BigInt&, Smn::BigInt&, bool) override;
  virtual void Test(Smn::BigInt&, Smn::BigInt&) override;
  virtual void Test(Smn::BigInt&, int) override;
protected:
  void CheckResult(Smn::BigInt& n, Smn::BigInt& nex, Smn::BigInt& r, Smn::BigInt& rex);
  void Print( Smn::BigInt& n,
              std::string opStr);
  void PrintResult( Smn::BigInt& o,
                    Smn::BigInt& n,
                    Smn::BigInt& nex,
                    Smn::BigInt& r,
                    Smn::BigInt& rex,
                    std::string opStr);
  void PrintResult( Smn::BigInt& n,
                    Smn::BigInt& r,
                    Smn::BigInt& ex,
                    std::string opStr);

  bool isPre;
};

class TestPreIncrement : public TestUnaryOperation {
public:
  TestPreIncrement();
  virtual ~TestPreIncrement() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestPostIncrement : public TestUnaryOperation {
public:
  TestPostIncrement();
  virtual ~TestPostIncrement() = default;
  virtual void Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) override;
};

class TestPreDecrement : public TestUnaryOperation {
public:
  TestPreDecrement();
  virtual ~TestPreDecrement() = default;
  virtual void Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) override;
};

class TestPostDecrement : public TestUnaryOperation {
public:
  TestPostDecrement();
  virtual ~TestPostDecrement() = default;
  virtual void Test(Smn::BigInt& v, Smn::BigInt& ne, Smn::BigInt& re) override;
};

class TestComparision : public BigIntTest {
public:
  TestComparision(std::string name);
  virtual ~TestComparision() = default;
  virtual void Test(Smn::BigInt&, Smn::BigInt&, Smn::BigInt&) override;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& e) override;
  virtual void Test(Smn::BigInt& n, int e) override;
protected:
  void PrintResult( Smn::BigInt& n1,
                    Smn::BigInt& n2,
                    bool r,
                    bool ex,
                    std::string opStr);
};

class TestGreaterThan : public TestComparision {
public:
  TestGreaterThan();
  virtual ~TestGreaterThan() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestGreaterThanEqual : public TestComparision {
public:
  TestGreaterThanEqual();
  virtual ~TestGreaterThanEqual() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestSmallerThan : public TestComparision {
public:
  TestSmallerThan();
  virtual ~TestSmallerThan() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestSmallerThanEqual : public TestComparision {
public:
  TestSmallerThanEqual();
  virtual ~TestSmallerThanEqual() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestEqual : public TestComparision {
public:
  TestEqual();
  virtual ~TestEqual() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestNotEqual : public TestComparision {
public:
  TestNotEqual();
  virtual ~TestNotEqual() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, bool e) override;
};

class TestNegation : public TestUnaryOperation {
public:
  TestNegation();
  virtual ~TestNegation() = default;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& ex) override;
};

class TestNegative : public TestUnaryOperation {
public:
  TestNegative();
  virtual ~TestNegative() = default;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& ex) override;
};

class TestBitwiseAnd : public TestBinaryOperations {
public:
  TestBitwiseAnd();
  virtual ~TestBitwiseAnd() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestBitwiseOr : public TestBinaryOperations {
public:
  TestBitwiseOr();
  virtual ~TestBitwiseOr() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestBitwiseXor : public TestBinaryOperations {
public:
  TestBitwiseXor();
  virtual ~TestBitwiseXor() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestBitwiseLeftShift : public TestBinaryOperations {
public:
  TestBitwiseLeftShift();
  virtual ~TestBitwiseLeftShift() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestBitwiseRightShift : public TestBinaryOperations {
public:
  TestBitwiseRightShift();
  virtual ~TestBitwiseRightShift() = default;
  virtual void Test(Smn::BigInt& n1, Smn::BigInt& n2, Smn::BigInt& ex) override;
};

class TestBitwiseNegation : public TestUnaryOperation {
public:
  TestBitwiseNegation();
  virtual ~TestBitwiseNegation() = default;
  virtual void Test(Smn::BigInt& n, Smn::BigInt& ex) override;
};

}