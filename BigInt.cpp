#include "BigInt.h"
#include <vector>
#include <exception>
#include <cassert>
#include <iostream>

namespace Smn {
BigInt::BigInt(std::string val) {
  digits = {};
  if (val.empty()) {
    makeZero();
  } else {
    if (val[0] == '-') {
      positive = false;
    } else {
      positive = true;
    }

    if ((val[0] == '-') || (val[0] == '+')) {
      val = val.substr(1);
    }

    if ((val.empty()) || (std::string::npos != val.find_first_not_of("0123456789"))) {
      throw("Invalid value in initialization");
    }

    size_t firstNonZero = val.find_first_not_of('0');
    if (std::string::npos == firstNonZero) {
      makeZero();
    } else {
      val = val.substr(firstNonZero);
      for (int i = val.size() - 1; i >= 0; i--) {
        digits.push_back(val[i] - '0');
      }
    }
  }
}
BigInt::BigInt(long long val) {
  init(val);
}
BigInt::BigInt(int val) {
  //long lval = val;
  init(val);
}
BigInt::BigInt(const BigInt& other) {
  positive = other.positive;
  digits = other.digits;
}
BigInt::BigInt(const BigInt&& other) {
  positive = other.positive;
  digits = other.digits;
}
unsigned int BigInt::size() {
  return digits.size();
}
BigInt& BigInt::operator=(const BigInt& other) {
  positive = other.positive;
  digits.clear();
  digits = other.digits;
  return (*this);
}
BigInt& BigInt::operator=(const BigInt&& other) {
  positive = other.positive;
  digits.clear();
  digits = other.digits;
  return (*this);
}
BigInt& BigInt::operator=(long long num) {
  BigInt other(num);
  *this = other;
  return *this;
}
BigInt& BigInt::operator=(int num) {
  BigInt other(num);
  *this = other;
  return *this;
}
BigInt& BigInt::operator+=(const BigInt& other) {
  if (positive == other.positive) {
    unsignedAddition(other);
  } else if (unsignedEqual(other)) {
    this->makeZero();
  } else if (unsignedBigger(other)) {
    unsignedSubstraction(other);
  } else {
    BigInt temp(other);
    temp.unsignedSubstraction(*this);
    positive = temp.positive;
    digits.clear();
    digits = temp.digits;
  }
  return (*this);
}
BigInt& BigInt::operator+=(long long num) {
  BigInt other(num);
  *this += other;
  return (*this);
}
BigInt& BigInt::operator+=(int num) {
  BigInt other(num);
  *this += other;
  return (*this);
}
BigInt& BigInt::operator-=(const BigInt& other) {
  if (positive != other.positive) {
    unsignedAddition(other);
  } else if (unsignedEqual(other)) {
    this->makeZero();
  } else if (unsignedBigger(other)) {
    unsignedSubstraction(other);
  } else {
    BigInt temp(other);
    temp.unsignedSubstraction(*this);
    positive = !other.positive;
    digits.clear();
    digits = temp.digits;
  }
  return (*this);
}
BigInt& BigInt::operator-=(long long num) {
  BigInt other(num);
  *this -= other;
  return (*this);
}
BigInt& BigInt::operator-=(int num) {
  BigInt other(num);
  *this -= other;
  return (*this);
}
BigInt& BigInt::operator*=(const BigInt& other) {
  if (*this != 0) {
    if (other == 0) {
      makeZero();
    } else {
      unsignedMultiplication(other);
      positive = (positive == other.positive);
    }
  }
  return (*this);
}
BigInt& BigInt::operator*=(long long num) {
  BigInt other(num);
  *this *= other;
  return (*this);
}
BigInt& BigInt::operator*=(int num) {
  BigInt other(num);
  *this *= other;
  return (*this);
}
BigInt& BigInt::operator/=(const BigInt& other) {
  if (other == 0) {
    throw("Divide by zero");
  } else if (unsignedSmaller(other)) {
    makeZero();
  } else {
    unsignedDivision(other);
    positive = (positive == other.positive);
  }
  return (*this);
}
BigInt& BigInt::operator/=(long long num) {
  BigInt other(num);
  *this /= other;
  return (*this);
}
BigInt& BigInt::operator/=(int num) {
  BigInt other(num);
  *this /= other;
  return (*this);
}
BigInt& BigInt::operator%=(const BigInt& other) {
  if (other == 0) {
    throw("Divide by zero");
  } else if (unsignedEqual(other)) {
    makeZero();
  } else if (unsignedBiggerOrEqual(other)) {
    unsignedModulus(other);
  }
  positive = true;
  return (*this);
}
BigInt& BigInt::operator%=(long long num) {
  BigInt other(num);
  *this %= other;
  return (*this);
}
BigInt& BigInt::operator%=(int num) {
  BigInt other(num);
  *this %= other;
  return (*this);
}
BigInt& BigInt::operator++() {
  *this += 1;
  return *this;
}
BigInt BigInt::operator++(int) {
  BigInt temp(*this);
  *this += 1;
  return temp;
}
BigInt& BigInt::operator--() {
  *this -= 1;
  return *this;
}
BigInt BigInt::operator--(int) {
  BigInt temp(*this);
  *this -= 1;
  return temp;
}
BigInt BigInt::operator-() const {
  BigInt temp = *this;
  if (temp != 0) {
    temp.positive = !temp.positive;
  }
  return temp;
}
BigInt BigInt::operator!() const {
  BigInt temp = *this;
  if (temp == 0) {
    temp = 1;
  } else {
    temp = 0;
  }
  return temp;
}
bool BigInt::operator<(const BigInt& other) const {
  bool ret = false;
  if ((!positive) && (other.positive)) {
    ret = true;
  } else if (positive == other.positive) {
    ret = unsignedSmaller(other);
    if (!positive) {
      ret = !ret;
    }
  }
  return ret;
}
bool BigInt::operator<(long long num) const {
  BigInt other(num);
  return (*this < other);
}
bool BigInt::operator<(int num) const {
  BigInt other(num);
  return (*this < other);
}
bool BigInt::operator>(const BigInt& other) const {
  bool ret = false;
  if ((positive) && (!other.positive)) {
    ret = true;
  } else if (positive == other.positive) {
    ret = unsignedBigger(other);
    if (digits.size() > other.digits.size()) {
      ret = true;
    } else if (digits.size() == other.digits.size()) {
      int i = digits.size() - 1;
      while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
      if ((i >= 0) && (digits[i] > other.digits[i])) {
        ret = true;
      }
    }
    if (!positive) {
      ret = !ret;
    }
  }
  return ret;
}
bool BigInt::operator>(long long num) const {
  BigInt other(num);
  return (*this > other);
}
bool BigInt::operator>(int num) const {
  BigInt other(num);
  return (*this > other);
}
bool BigInt::operator<=(const BigInt& other) const {
  bool ret = false;
  if ((!positive) && (other.positive)) {
    ret = true;
  } else if (positive == other.positive) {
    bool equal = false;
    ret = unsignedSmallerOrEqual(other, equal);
    if ((!positive) && (!equal)) {
      ret = !ret;
    }
  }
  return ret;
}
bool BigInt::operator<=(long long num) const {
  BigInt other(num);
  return (*this <= other);
}
bool BigInt::operator<=(int num) const {
  BigInt other(num);
  return (*this <= other);
}
bool BigInt::operator>=(const BigInt& other) const {
  bool ret = false;
  if ((positive) && (!other.positive)) {
    ret = true;
  } else if (positive == other.positive) {
    bool equal = false;
    ret = unsignedBiggerOrEqual(other, equal);
    if ((!positive) && (!equal)) {
      ret = !ret;
    }
  }
  return ret;
}
bool BigInt::operator>=(long long num) const {
  BigInt other(num);
  return (*this >= other);
}
bool BigInt::operator>=(int num) const {
  BigInt other(num);
  return (*this >= other);
}
bool BigInt::operator==(const BigInt& other) const {
  bool ret = false;
  if ((positive == other.positive) && (digits.size() == other.digits.size())) {
    ret = unsignedEqual(other);
  }
  return ret;
}
bool BigInt::operator==(long long num) const {
  BigInt other(num);
  return (*this == other);
}
bool BigInt::operator==(int num) const {
  BigInt other(num);
  return (*this == other);
}
bool BigInt::operator!=(const BigInt& other) const {
  bool ret = true;
  if ((positive == other.positive) && (digits.size() == other.digits.size())) {
    ret = !unsignedEqual(other);
  }
  return ret;
}
bool BigInt::operator!=(long long num) const {
  BigInt other(num);
  return (*this != other);
}
bool BigInt::operator!=(int num) const {
  BigInt other(num);
  return (*this != other);
}
BigInt BigInt::operator&(const BigInt& other) const {
  const BigDigits query1 = decToBin();
  const BigDigits query2 = other.decToBin();
  BigDigits result;
  for (int pos = 0; (pos < query1.size()) && (pos < query2.size()); pos++) {
    result.push_back(query1[pos] & query2[pos]);
  }
  return binToDec(result);
}
BigInt BigInt::operator&(long long num) const {
  BigInt other(num);
  return (*this & other);
}
BigInt BigInt::operator&(int num) const {
  BigInt other(num);
  return (*this & other);
}
BigInt BigInt::operator|(const BigInt& other) const {
  const BigDigits query1 = decToBin();
  const BigDigits query2 = other.decToBin();
  BigDigits result;
  int pos = 0;
  for (; (pos < query1.size()) && (pos < query2.size()); pos++) {
    result.push_back(query1[pos] | query2[pos]);
  }
  if (pos < query1.size()) {
    result.push_back(query1[pos]);
    pos++;
  } else if (pos < query2.size()) {
    result.push_back(query2[pos]);
    pos++;
  }
  return binToDec(result);
}
BigInt BigInt::operator|(long long num) const {
  BigInt other(num);
  return (*this | other);
}
BigInt BigInt::operator|(int num) const {
  BigInt other(num);
  return (*this | other);
}
BigInt BigInt::operator^(const BigInt& other) const {
  const BigDigits query1 = decToBin();
  const BigDigits query2 = other.decToBin();
  BigDigits result;
  int pos = 0;
  for (; (pos < query1.size()) && (pos < query2.size()); pos++) {
    result.push_back(query1[pos] ^ query2[pos]);
  }
  if (pos < query1.size()) {
    result.push_back(query1[pos]);
    pos++;
  } else if (pos < query2.size()) {
    result.push_back(query2[pos]);
    pos++;
  }
  return binToDec(result);
}
BigInt BigInt::operator^(long long num) const {
  BigInt other(num);
  return (*this ^ other);
}
BigInt BigInt::operator^(int num) const {
  BigInt other(num);
  return (*this ^ other);
}
BigInt BigInt::operator<<(int num) const {
  BigDigits result;
  const BigDigits query = decToBin();
  if (query.size() < (num / 8)) {
    result.push_back(0);
  } else {
    int bitsShift = num % 8;
    int carryShift = 8 - bitsShift;
    int bytePos = 0;
    int shiftByte = 0;
    unsigned char carryOnVal = 0;
    for (; bytePos < (num / 8); bytePos++) {
      result.push_back(0);
    }
    for (; bytePos < query.size(); bytePos++, shiftByte++) {
      result.push_back((query[shiftByte] << bitsShift) | carryOnVal);
      carryOnVal = query[shiftByte] >> carryShift;
    }
  }
  return binToDec(result);
}
BigInt BigInt::operator>>(int num) const {
  BigDigits result;
  const BigDigits query = decToBin();
  if (query.size() < (num / 8)) {
    result.push_back(0);
  } else {
    int bitsShift = num % 8;
    int carryShift = 8 - bitsShift;
    int bytePos = query.size() - 1;
    int shiftByte = query.size() - 1;
    unsigned char carryOnVal = 0;
    for (; bytePos > (query.size() - 1 - (num / 8)); bytePos--) {
      result.push_back(0);
    }
    for (; bytePos >= 0; bytePos--, shiftByte--) {
      result.insert(result.begin(), (query[shiftByte] >> bitsShift) | carryOnVal);
      carryOnVal = query[shiftByte] << carryShift;
    }
  }
  return binToDec(result);
}
BigInt BigInt::operator~() const {
  const BigDigits query = decToBin();
  BigDigits result;
  if (query.empty()) {
    result.push_back((~0) & 0xFF);
  } else {
    for (int pos = 0; pos < query.size(); pos++) {
      result.push_back(~query[pos] & 0xFF);
    }
  }
  return binToDec(result);
}

long long BigInt::getInt() const {
  long long iVal = 0;
  long long tens = 1;
  for (int i = 0; (i < (sizeof(long long) - 1) && i < digits.size()); i++) {
    iVal += (digits[i] * tens);
    tens *= 10;
  }
  if (!positive) {
    iVal = -iVal;
  }
  return iVal;
}
std::string BigInt::getBigRep() const {
  std::string sRep;
  if (!positive) {
    sRep.push_back('-');
  }
  for (int i = digits.size() - 1; i >= 0; i--) {
    sRep.push_back(digits[i] + '0');
  }

  return sRep;
}
void BigInt::init(long long val) {
  digits = {};
  positive = (val >= 0);
  if (val < 0) {
    val = -val;
  }
  if (0 == val) {
    digits.push_back(0);
  } else {
    while (val) {
      digits.push_back(static_cast<unsigned char>(val % 10));
      val /= 10;
    }
  }
}
void BigInt::makeZero() {
  BigInt temp(0);
  positive = temp.positive;
  digits.clear();
  digits = temp.digits;
}
void BigInt::unsignedAddition(const BigInt& other) {
  if (other.digits.size() > digits.size()) {
    digits.resize(other.digits.size(), 0);
  }
  int rem = 0;
  for (int dsum = 0, i = 0; i < other.digits.size(); i++) {
    dsum = digits[i] + other.digits[i] + rem;
    digits[i] = dsum % 10;
    rem = dsum / 10;
  }
  if (rem) {
      digits.push_back(rem);
  }
}
void BigInt::unsignedSubstraction(const BigInt& other) {
  assert(unsignedBigger(other));
  int k;
  int i = 0;
  for (; i < other.digits.size(); i++) {
    if (digits[i] < other.digits[i]) {
      digits[i] += 10;
      k = i + 1;
      while ((k < digits.size()) && (0 == digits[k])) {
        digits[k] = 9;
        k++;
      }
      digits[k]--;
    }
    digits[i] -= other.digits[i];
  }
  for (i = digits.size() - 1; ((i >= 1)&&(digits[i] == 0)); i--) {
    digits.pop_back();
  }
}
void BigInt::unsignedMultiplication(const BigInt& other) {
  std::vector<unsigned int> cross(digits.size() + other.digits.size(), 0);
  for (int i = 0; i < digits.size(); i++) {
    for (int j = 0; j < other.digits.size(); j++) {
      cross[i + j] += digits[i] * other.digits[j];
    }
  }
  digits.resize(cross.size());
  for (int dsum = 0, rem = 0, i = 0; i < cross.size(); i++) {
    dsum = rem + cross[i];
    cross[i] = dsum % 10;
    rem = dsum / 10;
    digits[i] = static_cast<unsigned char>(cross[i]);
  }
  for (int i = cross.size() - 1; ((i >= 1)&&(cross[i] == 0)); i--) {
    digits.pop_back();
  }
}
void BigInt::unsignedDivision(const BigInt& other) {
  BigInt one(1);
  if (unsignedEqual(other)) {
    digits = one.digits;
  } else if (!other.unsignedEqual(one)) {
    BigDigits result;
    BigDigits remainder;
    unsignedDivisionHelper(other, result, remainder);
    if (result.empty()) {
      makeZero();
    } else {
      digits.clear();
      digits = result;
    }
  }
}
void BigInt::unsignedModulus(const BigInt& other) {
  BigInt one(1);
  if (unsignedEqual(other)) {
    *this = 0;
  } else if (!other.unsignedEqual(one)) {
    BigDigits result{};
    BigDigits remainder{};
    unsignedDivisionHelper(other, result, remainder);
    if (remainder.empty()) {
      makeZero();
    } else {
      digits.clear();
      digits = remainder;
    }
  }
}
bool BigInt::unsignedSmaller(const BigInt& other) const {
  bool ret = false;
  if (digits.size() < other.digits.size()) {
    ret = true;
  } else if (digits.size() == other.digits.size()) {
    int i = digits.size() - 1;
    while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
    if ((i >= 0) && (digits[i] < other.digits[i])) {
      ret = true;
    }
  }
  return ret;
}
bool BigInt::unsignedBigger(const BigInt& other) const {
  bool ret = false;
  if (digits.size() > other.digits.size()) {
    ret = true;
  } else if (digits.size() == other.digits.size()) {
    int i = digits.size() - 1;
    while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
    if ((i >= 0) && (digits[i] > other.digits[i])) {
      ret = true;
    }
  }
  return ret;
}
bool BigInt::unsignedSmallerOrEqual(const BigInt& other, bool& equal) const {
  bool ret = false;
  equal = false;
  if (digits.size() < other.digits.size()) {
    ret = true;
  } else if (digits.size() == other.digits.size()) {
    int i = digits.size() - 1;
    while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
    if ((i < 0) || ((i >= 0) && (digits[i] < other.digits[i]))) {
      if (i < 0) {
        equal = true;
      }
      ret = true;
    }
  }
  return ret;
}
bool BigInt::unsignedSmallerOrEqual(const BigInt& other) const {
  bool equal;
  return unsignedSmallerOrEqual(other, equal);
}
bool BigInt::unsignedBiggerOrEqual(const BigInt& other, bool& equal) const {
  bool ret = false;
  equal = false;
  if (digits.size() > other.digits.size()) {
    ret = true;
  } else if (digits.size() == other.digits.size()) {
    int i = digits.size() - 1;
    while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
    if ((i < 0) || ((i >= 0) && (digits[i] > other.digits[i]))) {
      if (i < 0) {
        equal = true;
      }
      ret = true;
    }
  }
  return ret;
}
bool BigInt::unsignedBiggerOrEqual(const BigInt& other) const {
  bool equal;
  return unsignedBiggerOrEqual(other, equal);
}
bool BigInt::unsignedEqual(const BigInt& other) const {
  bool ret = false;
  if (digits.size() == other.digits.size()) {
    int i = digits.size() - 1;
    while (((i >= 0) && (digits[i] == other.digits[i]))) { i--; }
    if (i < 0) {
      ret = true;
    }
  }
  return ret;
}
void BigInt::unsignedDivisionHelper(const BigInt& other, BigDigits& result, BigDigits& remainder) const {
  BigInt temp, temp1;
  BigDigits dividend;
  int pos = digits.size() - 1;
  result.clear();
  remainder.clear();
  while (pos >= 0) {
    temp.digits = dividend;
    if ((dividend.size() > 0) || (digits[pos])) {
      dividend.insert(dividend.begin(), digits[pos]);
    }
    pos--;
    while ((dividend.size() < other.digits.size()) && (pos >= 0)) {
      if ((dividend.size() > 0) || (digits[pos])) {
        dividend.insert(dividend.begin(), digits[pos]);
      }
      pos--;
      if (!result.empty()) {
        result.insert(result.begin(), 0);
      }
    }
    if (dividend.empty()) {
      temp = 0;
    } else {
      temp.digits = dividend;
    }
    if ((temp.unsignedSmaller(other)) && (pos >= 0)) {
      if ((dividend.size() > 0) || (digits[pos])) {
        dividend.insert(dividend.begin(), digits[pos]);
        if (!result.empty()) {
          result.insert(result.begin(), 0);
        }
      }
      pos--;
    }
    if (dividend.empty()) {
      temp = 0;
    } else {
      temp.digits = dividend;
    }
    if (temp.unsignedEqual(other)) {
      result.insert(result.begin(), 1);
      dividend.clear();
    } else if (temp.unsignedBigger(other)) {
      for (int i = 2; i <= 10; i++) {
        temp1 = other * i;
        if (temp1.unsignedBigger(temp)) {
          result.insert(result.begin(), i - 1);
          temp1 -= other;
          temp -= temp1;
          if (temp == 0) {
            dividend.clear();
          } else {
            dividend = temp.digits;
          }
          break;
        }
      }
    } else if (!result.empty()) {
      result.insert(result.begin(), 0);
    }
    if ((dividend.size() == 1) && (dividend[0] == 0)) {
      dividend.clear();
    }
  }
  remainder = dividend;
}
BigInt::BigDigits BigInt::decToBin() const {
  BigDigits result;
  BigInt temp = *this;
  BigInt temp1;
  temp.positive = true;
  while (temp > 0) {
    temp1 = temp % 256;
    temp /= 256;
    result.push_back(static_cast<unsigned char>(temp1.getInt()));
  }
  return result;
}
BigInt BigInt::binToDec(BigDigits const& binStr) const {
  BigInt byteMultiply(1);
  BigInt result; //(static_cast<int>(binStr[0]));
  BigInt temp;
  for (int i = 0; i < binStr.size(); i++) {
    temp = (byteMultiply * (static_cast<int>(binStr[i])));
    result += temp;
    byteMultiply *= 256;
  }
  for (int pos = result.digits.size() - 1; (pos > 0) && (0 == result.digits[pos]); pos--) {
    result.digits.pop_back();
  }
  return result;
}

BigInt operator+(const BigInt& self, const BigInt& other) {
  BigInt temp = self;
  temp += other;
  return temp;
}
BigInt operator+(const BigInt& self, long long num) {
  BigInt temp = self;
  BigInt other(num);
  temp += other;
  return temp;
}
BigInt operator+(const BigInt& self, int num) {
  BigInt temp = self;
  BigInt other(num);
  temp += other;
  return temp;
}
BigInt operator-(const BigInt& self, const BigInt& other) {
  BigInt temp = self;
  temp -= other;
  return temp;
}
BigInt operator-(const BigInt& self, long long num) {
  BigInt temp = self;
  BigInt other(num);
  temp -= other;
  return temp;
}
BigInt operator-(const BigInt& self, int num) {
  BigInt temp = self;
  BigInt other(num);
  temp -= other;
  return temp;
}
BigInt operator*(const BigInt& self, const BigInt& other) {
  BigInt temp = self;
  temp *= other;
  return temp;
}
BigInt operator*(const BigInt& self, long long num) {
  BigInt temp = self;
  BigInt other(num);
  temp *= other;
  return temp;
}
BigInt operator*(const BigInt& self, int num) {
  BigInt temp = self;
  BigInt other(num);
  temp *= other;
  return temp;
}
BigInt operator/(const BigInt& self, const BigInt& other) {
  BigInt temp = self;
  temp /= other;
  return temp;
}
BigInt operator/(const BigInt& self, long long num) {
  BigInt temp = self;
  BigInt other(num);
  temp /= other;
  return temp;
}
BigInt operator/(const BigInt& self, int num) {
  BigInt temp = self;
  BigInt other(num);
  temp /= other;
  return temp;
}
BigInt operator%(const BigInt& self, const BigInt& other) {
  BigInt temp = self;
  temp %= other;
  return temp;
}
BigInt operator%(const BigInt& self, long long num) {
  BigInt temp = self;
  BigInt other(num);
  temp %= other;
  return temp;
}
BigInt operator%(const BigInt& self, int num) {
  BigInt temp = self;
  BigInt other(num);
  temp %= other;
  return temp;
}

}