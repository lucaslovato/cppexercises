#include <iostream>
#include "header8.h"

using namespace std;

void print_global_x() {
	cout << "This is print_global_x() function declared on header8.h and defined on header8.cpp" << endl;
}

int square(int n) {
	return n*n;
}