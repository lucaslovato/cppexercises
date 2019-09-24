#include <iostream>

using namespace std;

constexpr double cm_per_inch = 2.54;

void caseInches(double);
void caseCentimeters(double);
void menu();

int main(){
  menu();
}

void menu(){
  double length = 1;
  char unit = 'a';
  cout << "Please enter a length followed by a unit (c or i):" << endl;
  cin >> length >> unit;
  switch(unit){
    case 'i':
      caseInches(length);
      break;
    case 'c':
      caseCentimeters(length);  
      break;
    default:
      cout << "shit happened" << endl;
      break;
  }
}

void caseInches(double length){
  cout << length << " in == " << cm_per_inch*length << " cm" << endl;
}

void caseCentimeters(double length){
  cout << length << " cm == " << length / cm_per_inch << " in" << endl;
}
