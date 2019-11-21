#include <iostream>

using namespace std;

class X {
private:
	int x = 42;
public:
	int printX() {
		cout << "The private value x = " << x << endl;
	}
};

struct Y {
	int y = 123;
};

struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

enum Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

void printDate(Date d);

int main() {
	X X;
	//cout << X.x << endl; // note: int x declared private
	X.printX();

	Y Y;
	cout << "We can access struct values because they are public, y = " << Y.y << endl;

	Date date;
	date.y = 2019;
	date.m = 11;
	date.d = 20;

	printDate(date);
	Date discoveryOfBrazil {1500,4,22}; // The worst portuguese error ever!
	printDate(discoveryOfBrazil);

	Month m = sep;
	cout << "Month m = " << m << endl;

	return 0;
}

void printDate(Date d) {
	cout << "The date is " << d.y << "-" << d.m << "-" << d.d << endl;
}