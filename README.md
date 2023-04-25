# BigInt
Unlike Java, .NET or any other VEM platform, C++ doesn't support native Big Integers.
This library provides an implementation for platform independent Big Integer class.

You just need to add BigInt.h and BigInt.cpp in your project

# Advantage:
This library doesn't need you to specify the BigInt size during object creation.
Size increases or decreases as per the current number.

# Disadvantage:
This auto-growing/auto-shrinking feature of the class causes issue with binary operations.
For example,
X = A & B
Y = X | A
Z = X | B
Here,
Y != A if A.size() != X.size().
Or,
Z != B if B.size() != X.size().

I'll try to improve this limitation in future, but I think for now it is in good to condition.

# Contact
For any queries or suggestions or bugs, please feel to drop me an email:
saurabh.smn@gmail.com
