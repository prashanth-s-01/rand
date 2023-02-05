#include "Int.h" 

class Char {
	char c;

public:
	Char() {
		c = '\0';
	}

	Char(char ch) {
		c = ch;
	}

	void setChar(char ch) {
		c = ch;
	}

	char getChar() {
		return c;
	}

	Int operator - (const char& i) {
		int n;
		n = c - i;
		Int num(n);
		return num;
	}

	bool operator >= (const char& i) {
		return c >= i;
	}

	bool operator <= (const char& i) {
		return c <= i;
	}

	bool operator == (const char& i) {
		return c == i;
	}

	bool operator == (const Char& rhs) {
		return c == rhs.c;
	}
};
