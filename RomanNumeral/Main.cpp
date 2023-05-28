#include <iostream>
#include "RomanNumeral.h"


int main() {
	RomanNumeral::initializeMaps();

	extern RomanNumeral operator"" _RN(unsigned long long int);
	extern RomanNumeral operator"" _RN(const char* roman, size_t);

#ifdef _DEBUG
	extern void RunMyTests();
	RunMyTests();
#endif // _DEBUG

	RomanNumeral r1{ 45 }, r2{ 32 }, r3{ "XXIV" }, r4{ "LXXXVIII" }, rExp{ "II" };

	std::cout << "r1: " << r1 << " [" << r1.toInteger() << "]" << std::endl;
	std::cout << "r2: " << r2 << " [" << r2.toInteger() << "]" << std::endl;
	std::cout << "r1 + r2: " << r1 + r2 << " [" << (r1 + r2).toInteger() << "]" << std::endl;
	std::cout << "r1 - r2: " << r1 - r2 << " [" << (r1 - r2).toInteger() << "]" << std::endl;
	std::cout << "r1 * r2: " << r1 - r2 << " [" << (r1 * r2).toInteger() << "]" << std::endl;
	std::cout << "r1 / r2: " << r1 / r2 << " [" << (r1 / r2).toInteger() << "]" << std::endl;
	std::cout << "r1 % r2: " << r1 % r2 << " [" << (r1 % r2).toInteger() << "]" << std::endl;
	std::cout << "r1 to the power of 2: " << (r1 ^ rExp) << " [" << (r1 ^ rExp).toInteger() << "]" << std::endl;
	std::cout << "The greater of r1 and r2 is: " << ((r1 > r2) ? r1 : r2) << " [" << ((r1 > r2) ? r1 : r2).toInteger() << "]" << std::endl;
	std::cout << "The lesser of r1 and r2 is: " << ((r1 < r2) ? r1 : r2) << " [" << ((r1 < r2) ? r1 : r2).toInteger() << "]" << std::endl << std::endl;
	std::cout << "r3: " << r3 << " [" << r3.toInteger() << "]" << std::endl;
	std::cout << "r4: " << r4 << " [" << r4.toInteger() << "]" << std::endl;
	std::cout << "r3 + r4: " << r3 + r4 << " [" << (r3 + r4).toInteger() << "]" << std::endl;
	std::cout << "r4 - r3: " << r4 - r3 << " [" << (r4 - r3).toInteger() << "]" << std::endl;
	std::cout << "r3 * r4: " << r3 * r4 << " [" << (r3 * r4).toInteger() << "]" << std::endl;
	std::cout << "r4 / r3: " << r4 / r3 << " [" << (r4 / r3).toInteger() << "]" << std::endl;
	std::cout << "r4 % r3: " << r4 % r3 << " [" << (r4 % r3).toInteger() << "]" << std::endl;
	std::cout << "r3 to the power of 2: " << (r3 ^ rExp) << " [" << (r3 ^ rExp).toInteger() << "]" << std::endl;
	std::cout << "The greater of r3 and r4 is: " << ((r3 > r4) ? r3 : r4) << " [" << ((r3 > r4) ? r3 : r4).toInteger() << "]" << std::endl;
	std::cout << "The lesser of r3 and r4 is: " << ((r3 < r4) ? r3 : r4) << " [" << ((r3 < r4) ? r3 : r4).toInteger() << "]" << std::endl << std::endl;

	r1 = 56;
	r2 = "CXC";

	std::cout << "The new value of r1 is: " << r1 << " [" << r1.toInteger() << "]" << std::endl;
	std::cout << "The new value of r2 is: " << r2 << " [" << r2.toInteger() << "]" << std::endl << std::endl;

	std::cout << "User-defined literals:\n";
	std::cout << "243_RN: " << 243_RN << " [" << 243 << "]" << std::endl;
	std::cout << "\"XCIV\"_RN: " << "XCIV"_RN << " [" << ("XCIV"_RN).toInteger() << "]" << std::endl;

	return 0;
}