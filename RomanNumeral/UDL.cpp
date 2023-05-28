#include "RomanNumeral.h"

RomanNumeral operator"" _RN(unsigned long long int roman) {
	return RomanNumeral{ static_cast<int>(roman) };
}

RomanNumeral operator"" _RN(const char* roman, size_t) {
	return RomanNumeral{ roman };
}