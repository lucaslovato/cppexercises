#include <iostream>
#include "header8.h"

using namespace std; // Make names from std directly accessible

int a {3}; // Avoid declare with no value
//const int c; // Error const can't be declared with no value, this doen't make sense
int global_x; // From header8.h
float pi =
#include "pi.h"
;

int inc(int n);
int incRef(int &n);
void hr();

int main() {
	cout << "PI = " << pi << endl;
	hr();
	cout << "int a = " << a << endl;
	cout << "square(" << a << ") = " << square(a) << endl;
	hr();
	cout << "int a = " << a << endl;
	cout << "inc(" << a << ") = " << inc(a) << endl;
	hr();
	cout << "int a = " << a << endl;
	cout << "incRef(" << a << ") = " << incRef(a) << endl;
	cout << "int a = " << a << endl;
}

int inc(int n) {
	return ++n;
}

int incRef(int &n) {
	return ++n;
}

void hr() {
	cout << "--------------------" << endl;
}