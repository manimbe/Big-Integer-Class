#ifndef BIGNTEGER
#define BIGNTEGER

#include <iostream>
#include <string>

class Bignteger{
private:

	bool negative = 0;
	std::string value;

	/* --------- Methods --------- */

	std::string intReturn() const;

	inline bool symbolReturn() const;

	inline std::string valueReturn() const;

	inline size_t lengthReturn() const;

	std::string normalize(std::string number) const;

	bool greaterThan(const Bignteger& other) const;

	bool equalTo(const Bignteger& other) const;

	bool lessThan(const Bignteger& other) const;

	std::string valueSum(const Bignteger &other) const;

	std::string valueSubtraction(const Bignteger &other) const;

	std::string valueMultiplication(const Bignteger &other) const;

	std::string valueDivision(Bignteger B) const;

	std::string valueModulo(const Bignteger& other) const;

public:

	/* --------- Constructors --------- */

	Bignteger();

	Bignteger(const char* v);

	Bignteger(const std::string&& v);

	Bignteger(const Bignteger& v);

  Bignteger(const Bignteger&& v);

	/* --------- Operators --------- */

	Bignteger& operator = (const Bignteger& other);

	Bignteger& operator = (const Bignteger&& other);

	Bignteger& operator = (const char*&& other);

	Bignteger& operator = (std::string&& other);

	bool operator > (const Bignteger& y) const;

	bool operator >= (const Bignteger& y) const;

	bool operator < (const Bignteger& y) const;

  bool operator <= (const Bignteger& y) const;

	bool operator == (const Bignteger& y) const;

  bool operator != (const Bignteger& y) const;

	std::string operator + (Bignteger& y);

	std::string operator - (Bignteger& y);

	std::string operator * (const Bignteger& y) const;

	std::string operator / (const Bignteger& y) const;

	std::string operator % (const Bignteger& y) const;

	friend std::ostream& operator << (std::ostream& output, const Bignteger& x);

};

std::ostream& operator << (std::ostream& output, const Bignteger& x);

#endif //BIGNTEGER
