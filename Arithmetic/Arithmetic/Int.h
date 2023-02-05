class Int {
	int num;

public:
	Int() {}

	Int(int n) {
		num = n;
	}

	void setInt(int n) {
		num = n;
	}

	int getInt() {
		return num;
	}

	Int operator + (const Int& obj) {
		Int tp;
		tp.num = num + obj.num;
		return tp;
	}

	Int operator % (const Int& obj) {
		Int tp;
		tp.num = num % obj.num;
		return tp;
	}

	Int operator / (const Int& obj) {
		Int tp;
		tp.num = num / obj.num;
		return tp;
	}

	Int operator * (const Int& obj) {
		Int tp;
		tp.num = num * obj.num;
		return tp;
	}

	Int operator - (const Int& obj) {
		Int tp;
		tp.num = num - obj.num;
		return tp;
	}

	Int& operator ++ (int x) {
		num++;
		return *this;
	}

	Int& operator -- (int x) {
		num--;
		return *this;
	}

	bool operator < (const Int& obj) {
		return num < obj.num;
	}

	bool operator < (const int& i) {
		return num < i;
	}

	bool operator <= (const int& i) {
		return num <= i;
	}

	bool operator != (const int& i) {
		return num != i;
	}

	bool operator != (const Int& obj) {
		return num != obj.num;
	}
};
