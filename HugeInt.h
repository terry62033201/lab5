#include<iostream>
#include<string>
using namespace std;

class HugeInt{
	friend ostream &operator << (ostream &, const HugeInt &);
	friend istream &operator >> (istream &, HugeInt &);
	public:
		HugeInt(long = 0);
		HugeInt(const string &);
		HugeInt operator + (const HugeInt &op)const;
		HugeInt operator - (const HugeInt &op)const;
	private:
		static const int digit = 32;
		short integer[digit];
};
