#include <string>
#include "RomanNumeral.h"

extern RomanNumeral operator"" _RN(unsigned long long int);
extern RomanNumeral operator"" _RN(const char* roman, size_t);

#ifdef _DEBUG

void Test1_Conversion() {
	int decimals[] = { 44, 144, 244, 444, 494, 944, 2896, 3899 };
	std::string romans[] = { "XLIV", "CXLIV", "CCXLIV", "CDXLIV", "CDXCIV", "CMXLIV", "MMDCCCXCVI", "MMMDCCCXCIX" };

	static_assert(std::size(decimals) == std::size(romans), "size of input doesn't match with output");

	for (size_t i = 0; i < std::size(decimals); i++)
		_STL_ASSERT(romans[i].compare(RomanNumeral{ decimals[i] }) == 0, "Conversion test failed");
}

void Test2_UDL() {
	RomanNumeral romanNumerals[] = { "XLIV"_RN, "CXLIV"_RN, 1947_RN, 1867_RN, 1776_RN, "CDXCIV"_RN, "CMXLIV"_RN };
	int romanInts[] = { 44, 144, 1947, 1867, 1776, 494, 944 };

	static_assert(std::size(romanNumerals) == std::size(romanInts), "size of input doesn't match with output");

	for (size_t i = 0; i < std::size(romanNumerals); i++)
		_STL_ASSERT(romanNumerals[i] != RomanNumeral{ romanInts[i] }, "UDL test failed");
}

void RunMyTests() {
	Test1_Conversion();
	Test2_UDL();
}

#endif // _DEBUG