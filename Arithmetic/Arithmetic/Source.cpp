#include <iostream> 
#include <deque> 
#include "Char.h" 

using namespace std;

class Number {

public:
	deque<Int> digits;

	Number() {

	}

	void insertDigits(Char c) {
		digits.push_back(c - '0');
	}

	void padDigits() {
		digits.push_front(0);
	}

	int dqsize() {
		return digits.size();
	}

	Number* add(Number* num) {
		Number* result = new Number();
		Int carry(0);

		for (auto i1 = digits.end() - 1, i2 = num->digits.end() - 1;; i1--, i2--) {
			Int sum = (*i1) + (*i2) + carry;
			carry = sum / 10;
			sum = sum % 10;
			result->digits.push_front(sum);

			if (i1 == digits.begin() || i2 == num->digits.begin())
				break;
		}

		if (carry != 0) {
			result->digits.push_front(carry);
		}
		return result;
	}

	Number* subtractHelp(deque<Int> num1, deque<Int> num2) {
		bool borrow = false;
		Number* res = new Number();
		for (auto i1 = num1.end() - 1, i2 = num2.end() - 1;; i1--, i2--) {
			if (borrow) {
				(*i1)--;
				borrow = false;
			}
			if ((*i1) < (*i2)) {
				borrow = true;
				(*i1) = (*i1) + 10;
			}

			res->digits.push_front(*i1 - *i2);

			if (i1 == num1.begin() || i2 == num2.begin())
				break;
		}
		return res;
	}
	Number* subtract(Number* num) {
		
		int sign = 1;
		for (auto i1 = digits.begin(), i2 = num->digits.begin(); i1 != digits.end() && i2 != num->digits.end(); i1++, i2++) {
			if (*i1 != *i2) {
				if (*i1 < *i2)
					sign = -1;
				break;
			}
		}

		cout << "The difference is : ";
		Number* result;
		if (sign == -1) {
			result = subtractHelp(num->digits, digits);
			cout << "-";
			result->print();
		}
		else {
			result = subtractHelp(digits, num->digits);
			result->print();
		}
		return result;
	}

	void print() {
		for (auto i = digits.begin(); i != digits.end(); i++) {
			cout << (*i).getInt();
		}
		cout << endl;
	}

	void resize() {
		digits.resize(50);
	}

};

Number* numberInputs();

int main() {
	Number* num1, * num2;
	num1 = numberInputs();
	num1->print();
	num2 = numberInputs();
	num2->print();

	Number* sum = num1->add(num2);
	cout << "Sum = ";
	sum->print();

	Number* diff = num1->subtract(num2);
	cout << "Absolute difference = ";
	diff->print();

	delete num1, num2, sum, diff;

	return 0;
}



Number* numberInputs() {
	Number* num = new Number();
	Char c;
	Int i;

	cout << "Enter digits of the number: ";
	for (i = 0; i <= 50; i++) {
		char c1;
		if ((c1 = getchar()) == '\n') {
			cout << "End of number" << endl;
			break;
		}
		c.setChar(c1);
		if (c >= '0' && c <= '9') {
			num->insertDigits(c);
		}
		else {
			i--;
		}
	}
	
	//To pad remaining positions with zeroes; 

	while (num->dqsize() < 50) {
		num->padDigits();
	}

	num->resize();
	return num;
}