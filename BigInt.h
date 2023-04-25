// BigInt.h
// License: Apache 2.0
// Copyright: 2023 Saurabh Suman <saurabh.smn@gmail.com>
// Info: You are free to use and modify the content as per
//       condition of Apache 2.0 licensing terms.
//       See LICENSE file for details

#include <string>
#include <vector>

namespace Smn {

class BigInt {
public:
  BigInt(std::string val);
  BigInt(long long val = 0);
  BigInt(int val);
  BigInt(const BigInt& other);
  BigInt(const BigInt&& other);
  unsigned int size();
  BigInt& operator=(const BigInt& other);
  BigInt& operator=(const BigInt&& other);
  BigInt& operator=(long long num);
  BigInt& operator=(int num);
  BigInt& operator+=(const BigInt& other);
  BigInt& operator+=(long long num);
  BigInt& operator+=(int num);
  BigInt& operator*=(const BigInt& other);
  BigInt& operator*=(long long num);
  BigInt& operator*=(int num);
  BigInt& operator-=(const BigInt& other);
  BigInt& operator-=(long long num);
  BigInt& operator-=(int num);
  BigInt& operator/=(const BigInt& other);
  BigInt& operator/=(long long num);
  BigInt& operator/=(int num);
  BigInt& operator%=(const BigInt& other);
  BigInt& operator%=(long long num);
  BigInt& operator%=(int num);
  BigInt& operator++();
  BigInt operator++(int);
  BigInt& operator--();
  BigInt operator--(int);
  BigInt operator-() const;
  BigInt operator!() const;
  bool operator<(const BigInt& other) const;
  bool operator<(long long num) const;
  bool operator<(int num) const;
  bool operator<=(const BigInt& other) const;
  bool operator<=(long long num) const;
  bool operator<=(int num) const;
  bool operator>(const BigInt& other) const;
  bool operator>(long long num) const;
  bool operator>(int num) const;
  bool operator>=(const BigInt& other) const;
  bool operator>=(long long num) const;
  bool operator>=(int num) const;
  bool operator==(const BigInt& other) const;
  bool operator==(long long num) const;
  bool operator==(int num) const;
  bool operator!=(const BigInt& other) const;
  bool operator!=(long long num) const;
  bool operator!=(int num) const;
  BigInt operator&(const BigInt& other) const;
  BigInt operator&(long long num) const;
  BigInt operator&(int num) const;
  BigInt operator|(const BigInt& other) const;
  BigInt operator|(long long num) const;
  BigInt operator|(int num) const;
  BigInt operator^(const BigInt& other) const;
  BigInt operator^(long long num) const;
  BigInt operator^(int num) const;
  BigInt operator<<(int num) const;
  BigInt operator>>(int num) const;
  BigInt operator~() const;

  friend BigInt operator+(const BigInt& self, const BigInt& other);
  friend BigInt operator+(const BigInt& self, long long num);
  friend BigInt operator+(const BigInt& self, int num);
  friend BigInt operator*(const BigInt& self, const BigInt& other);
  friend BigInt operator*(const BigInt& self, long long num);
  friend BigInt operator*(const BigInt& self, int num);
  friend BigInt operator-(const BigInt& self, const BigInt& other);
  friend BigInt operator-(const BigInt& self, long long num);
  friend BigInt operator-(const BigInt& self, int num);
  friend BigInt operator/(const BigInt& self, const BigInt& other);
  friend BigInt operator/(const BigInt& self, long long num);
  friend BigInt operator/(const BigInt& self, int num);
  friend BigInt operator%(const BigInt& self, const BigInt& other);
  friend BigInt operator%(const BigInt& self, long long num);
  friend BigInt operator%(const BigInt& self, int num);

  long long getInt() const;
  std::string getBigRep() const;
private:
  typedef std::vector<unsigned char> BigDigits;
  bool positive;
  unsigned int byteSize;
  BigDigits digits;

  void init(long long val);
  void makeZero();
  void unsignedAddition(const BigInt& other);
  void unsignedSubstraction(const BigInt& other);
  void unsignedMultiplication(const BigInt& other);
  void unsignedDivision(const BigInt& other);
  void unsignedModulus(const BigInt& other);
  bool unsignedSmaller(const BigInt& other) const;
  bool unsignedBigger(const BigInt& other) const;
  bool unsignedSmallerOrEqual(const BigInt& other, bool& equal) const;
  bool unsignedSmallerOrEqual(const BigInt& other) const;
  bool unsignedBiggerOrEqual(const BigInt& other, bool& equal) const;
  bool unsignedBiggerOrEqual(const BigInt& other) const;
  bool unsignedEqual(const BigInt& other) const;
  void unsignedDivisionHelper(const BigInt& other, BigDigits& result, BigDigits& remainder) const;
  BigDigits decToBin() const;
  BigInt binToDec(BigDigits const& binStr) const;
};

}
