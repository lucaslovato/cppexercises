#include <iostream>

using namespace std;

void menu(void);

int main(){
  menu();
}

void menu(){
  int i = 33;
  while(i < 127){
    cout << int(i) <<" "<<char(i) << endl;
    i++;
  }
}
