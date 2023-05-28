#include <vector>
#include <algorithm>
#include "RomanNumeral.h"


RomanNumeral::RomanNumeral(int number) {
	intValue = std::max(std::min(number, kMaxValue), 1);
}

RomanNumeral::RomanNumeral(const char* romanValue) {
	strValue = romanValue;
}

void RomanNumeral::initializeMaps() {
	auto insertIntoMaps = [&](int deci, char roman)
	{
		intToCharMap.emplace(deci, roman);
		charToIntMap.emplace(roman, deci);
	};

	insertIntoMaps(1, 'I');
	insertIntoMaps(5, 'V');
	insertIntoMaps(10, 'X');
	insertIntoMaps(50, 'L');
	insertIntoMaps(100, 'C');
	insertIntoMaps(500, 'D');
	insertIntoMaps(1000, 'M');
}

int RomanNumeral::toInteger() const {
	if (intValue == 0)
	{
		int intVer = 0, lastValue = 1000;
		for (size_t i = 0; i < strValue.length(); i++)
		{
			int currValue = charToIntMap[strValue[i]];

			if (currValue > lastValue)
				intVer -= 2 * lastValue;
			intVer += currValue;
			lastValue = currValue;
		}
		intValue = intVer;
	}

	return intValue;
}

RomanNumeral::operator const char*() const {
	if (strValue == "")
		strValue = toString();
	return strValue.c_str();
}

RomanNumeral& RomanNumeral::operator=(int newValue) {
	intValue = std::min(newValue, kMaxValue);
	if (intValue != newValue)
		strValue.erase();

	return *this;
}

RomanNumeral& RomanNumeral::operator=(std::string newValue)  {
	strValue = newValue;
	if (strValue != newValue)
		intValue = 0;

	return *this;
}

RomanNumeral RomanNumeral::operator+(const RomanNumeral& other) const {
	return RomanNumeral{ toInteger() + other.toInteger() };
}

RomanNumeral RomanNumeral::operator-(const RomanNumeral& other) const {
	return RomanNumeral{ toInteger() - other.toInteger() };
}

RomanNumeral RomanNumeral::operator*(const RomanNumeral& other) const {
	return RomanNumeral{ toInteger() * other.toInteger() };
}

RomanNumeral RomanNumeral::operator/(const RomanNumeral& other) const {
	return RomanNumeral{ toInteger() / other.toInteger() };
}

RomanNumeral RomanNumeral::operator%(const RomanNumeral& other) const {
	return RomanNumeral{ toInteger() % other.toInteger() };
}

RomanNumeral RomanNumeral::operator^(const RomanNumeral& other) const {
	return RomanNumeral{ static_cast<int>(pow(toInteger() * 1.0, other.toInteger() * 1.0)) };
}

bool RomanNumeral::operator>(const RomanNumeral& other) const {
	return toInteger() > other.toInteger();
}

bool RomanNumeral::operator<(const RomanNumeral& other) const {
	return toInteger() < other.toInteger();
}

bool RomanNumeral::operator==(const RomanNumeral& other) const {
	return toInteger() == other.toInteger();
}

std::vector<unsigned short> RomanNumeral::computeCoefficients() const {
	std::vector<unsigned short> coefficients(intToCharMap.size());
	int currValue = intValue, counter = 0;
	for (const auto &element : intToCharMap) {
		int quotient = currValue / element.first;
		coefficients[counter] = quotient;

		currValue = currValue % element.first;
		counter++;
	}

	return coefficients;
}

std::string RomanNumeral::toString() const {
	std::string stringVer = "";
	auto coefficients = computeCoefficients();
	int counter = 0;
	char lastChar = 'M', previousChar = 'M', lastAddedElement = '\0';
	for (const auto &element : intToCharMap) {
		if (coefficients[counter] == 4) {
			if (!stringVer.empty() && (lastAddedElement == 'V' || lastAddedElement == 'L' || lastAddedElement == 'D')) {
				stringVer.pop_back();
				stringVer += element.second;
				stringVer += previousChar;
			}
			else {
				stringVer += element.second;
				stringVer += lastChar;
			}
		}
		else {
			stringVer += repeatCharacter(element.second, coefficients[counter]);
		}
		previousChar = lastChar;
		lastChar = element.second;
		if (coefficients[counter] > 0)
			lastAddedElement = element.second;
		counter++;
	}
	return stringVer;
}

std::string RomanNumeral::repeatCharacter(char character, short numOfTimes) {
	std::string returnString = "";
	for (int i = 0; i < numOfTimes; i++)
		returnString += character;
	return returnString;
}

std::map<int, char, std::greater<int>> RomanNumeral::intToCharMap;
std::unordered_map<char, int> RomanNumeral::charToIntMap;