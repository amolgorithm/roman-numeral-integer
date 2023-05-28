#pragma once

#include <map>
#include <unordered_map>
#include <string>

/**
 * @brief Represents a Roman Numeral providing mathematical operations and conversion to/from corresponding integer value.
 * @details The RomanNumeral class is an object representing a roman number using a string value.
 * The string value of a RomanNumeral object instance is set to the value of the argument given in the second constructor, if it is a string.
 * Otherwise, the integer value of the object instance is set to the value of the argument given in the first constructor.
 * If a string argument is given, it has to be a valid Roman Numeral Value, since RomanNumeral doesn't validate.
 * If an integer argument is given, it has to be within the range of 1 to 3999.
 * The RomanNumeral class allows it such that two or more RomanNumeral objects can use arithmetic or comparison operators between themselves.
 * The supported operations are addition, subtractions, multiplication, division, exponents and modulo.
 * The supported comparisons are: greater than, less than, and equal to.
 * When a RomanNumeral object is used or mentioned, the roman form (string) is returned, regardless of the type of value the constructor received.
 * (e.g.

 * RomanNumeral r1{ 67 };
 *	std::cout << r1;
 *	-------------------
 *	Output: LXVII
 *	)
 * @remark **The RomanNumeral class doesn't validate the string argument given as a valid Roman Numeral.
 * If an integer argument is given, it must be within the range of 1 to 3999. If it crosses the limit of 3999, the value will automatically be set to 3999.
 * @author Amol S.
 * @version 1.0
 */
class RomanNumeral {
public:

	/**
	 * @brief Constructs an object of RomanNumeral given its integer value.
	 * (e.g. RomanNumeral r1{ 34 }; )
	 * @param number
	 */
	explicit RomanNumeral(int number);

	/**
	 * @brief Constructs an object of RomanNumeral given its roman string.
	 * (e.g. RomanNumeral r2{ "XXI" }; )
	 * @param romanValue
	 */
	explicit RomanNumeral(const char* romanValue);

	/**
	 * @brief Initializes the intToCharMap ordered map and charToIntMap unordered map.
	 */
	static void initializeMaps();

	/**
	 * @brief The public method toInteger converts the string strValue to the appropriate decimal numeral and returns that integer value.
	 */
	int toInteger() const;
	
	/**
	 * @brief 
	 */
	operator const char*() const;

	/**
	 * @brief This is the function where the = operator is overloaded. It sets intValue to the newValue, if the argument recieved was an integer.
	 * @param newValue
	 */
	RomanNumeral& operator=(int newValue);

	/**
	 * @brief This is the function where the = operator is overloaded. It sets strValue to the newValue, if the argument recieved was a string.
	 * @param newValue
	 */
	RomanNumeral& operator=(std::string newValue);

	/**
	 * @brief This is the function where the + operator is overloaded.
	 * When two or more RomanNumeral objects have the + between, a RomanNumeral object with the value of the sum is returned.
	 * @param other
	 */
	RomanNumeral operator+(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the - operator is overloaded.
	 * When two or more RomanNumeral objects have the - operator between, a RomanNumeral object with the value of the difference is returned.
	 * @param other
	 */
	RomanNumeral operator-(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the * operator is overloaded.
	 * When two or more RomanNumeral objects have the * operator between, a RomanNumeral object with the value of the product is returned.
	 * @param other
	 */
	RomanNumeral operator*(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the / operator is overloaded.
	 * When two or more RomanNumeral objects have the / operator between, a RomanNumeral object with the value of the quotient is returned.
	 * @param other
	 */
	RomanNumeral operator/(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the % operator is overloaded.
	 * When two or more RomanNumeral objects have the % operator between, a RomanNumeral object with the value of the remainder is returned.
	 * @param other
	 */
	RomanNumeral operator%(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the ^ operator is overloaded.
	 * When two or more RomanNumeral objects have the ^ operator between, a RomanNumeral object with the value of the power is returned.
	 * @param other
	 */
	RomanNumeral operator^(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the > operator is overloaded.
	 * The boolean of the statement of RomanNumeral objects with > between them is returned.
	 * @param other
	 */
	bool operator>(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the < operator is overloaded.
	 * The boolean of the statement of RomanNumeral objects with < between them is returned.
	 * @param other
	 */
	bool operator<(const RomanNumeral& other) const;

	/**
	 * @brief This is the function where the == operator is overloaded.
	 * If the two RomanNumeral objects are equal to each other, it returns true, else false.
	 * @param other
	 */
	bool operator==(const RomanNumeral& other) const;

private:

	std::vector<unsigned short> computeCoefficients() const;

	// Converts intValue to its corresponding roman numeral form and returns that value.
	std::string toString() const;

	/**
	 * @brief The private static member function repeatCharacter returns a string composed of character repeated numOfTimes times.
	 * @param character, numOfTimes
	 */
	static std::string repeatCharacter(char character, short numOfTimes);

	mutable unsigned int intValue = 0; // intValue is the decimal numeral form that is the value of this class.
	mutable std::string strValue; // strValue is the roman numeral form that is the value of this class.

	static std::map<int, char, std::greater<int>> intToCharMap; // intToCharMap is the ordered map that holds the roman numeral letters as the value and the corresponding decimal numeral as the key.
	static std::unordered_map<char, int> charToIntMap; // charToIntMap is the unordered map that holds the roman numeral letters as the key and the corresponding decimal numeral as the value.

	static constexpr int kMaxValue = 3999;
};
