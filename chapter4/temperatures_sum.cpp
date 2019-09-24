//#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

int main(){
  vector<double> temps;
  for(double temp; cin>>temp; ) temps.push_back(temp);
  double sum = 0 ;
  for(int x : temps) sum += x;
  cout << "Average temperature: " << sum/temps.size() << endl;
  sort(temps.begin(), temps.end());
  cout << "Median temperature: " << temps[temps.size()/2] << endl;
}
