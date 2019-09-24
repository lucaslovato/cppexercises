#include <iostream>

using namespace std;

int main(){
  constexpr double cm_per_inch = 2.54;
  double length = 1;
  char unit = 'a';
  cout << "Please enter a length followed by a unit (c or i):" << endl;
  cin >> length >> unit;
  switch(unit){
    case 'i':
        cout << length << " in == " << cm_per_inch*length << " cm" << endl;
        break;
    case 'c':
        cout << length << " cm == " << length / cm_per_inch << " in" << endl;
        break;
    default:
        cout << "shit happened" << endl;
        break;
  }
}
