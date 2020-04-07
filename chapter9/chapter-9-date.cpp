#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Year {
  static constexpr int min = 1800;
  static constexpr int max = 2200;

public:
  class Invalid {};

  Year() { y = 2000; }

  Year(int x): y{x} {
    if (x < min || max <= x) {
      throw Invalid {};
    }
  }

  int year() { return y; }

private:
  int y;
};

enum Month
{
  Jan = 1,
  Feb,
  Mar,
  Apr,
  May,
  Jun,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec
};

Month operator += (Month &m, int n) {
  m = n > 0 ? Month((m + n) % 12) : m;
  return Month(m);
}

Month operator -= (Month &m, int n) {
  m = n > 0
      ? m - n > 0
      ? Month(m - n)
      : Month(m - n + 12)
      : m;
  return Month(m);
}

class Date {
  Year y;
  Month m;
  int d;

public:
  Date(Year y, Month m, int d);
  Year year() { return y; }

  Month month() { return m; }

  int day() { return d; }

  string strMonth() {
    static const string months[] =
    { "January", "February", "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December" };
    return months[m - 1];
  }

  void addYear(int n) { y = n > 0 ? Year(y.year() + n) : y; }

  void subYear(int n) { y = n > 0 ? Year(y.year() - n) : y; }

  void setYear(Year year) { y = year; }

  void setYear(int year) { y = Year(year); }

  void addMonth(int n) { m += n; }

  void subMonth(int n) { m -= n; }

  void setMonth(Month month) { m = month; }

  void setMonth(int month) { m = Month(month); }

  void setDay(int n) { if (checkDay(n)) { d = n; } }

  bool checkDay(int n) {
    return n > 0 && n <= 31;
  }
};

Date::Date(Year year, Month month, int day) {
  try {
    y = year;
    m = month;
    d = day;
    if (!checkDay(d)) {
      throw string("Error: day out of range");
    }
  } catch (string e) {
    cout << e << endl;
    exit(1);
  }
}

string leadingZero(int n) {
  return n < 10 ? "0" + to_string(n) : to_string(n);
}

void printDate(Date d) {
  int year = d.year().year();
  int month = d.month();
  int day = d.day();
  cout << "The date is " << year << "-" << leadingZero(month) << "-" <<
    leadingZero(day) << endl;
}

int main() {
  Date today { Year { 2020 }, May, 25 };
  printDate(today);
  cout << "The month is " << today.strMonth() << endl;

  cout << "\n# Add 5 months" << endl;
  today.addMonth(5);
  printDate(today);
  cout << "The month is " << today.strMonth() << endl;

  cout << "\n# Set month to January" << endl;
  today.setMonth(Jan);   // works also for .setMonth(Month(1)) and .setMonth(1)
  printDate(today);
  cout << "The month is " << today.strMonth() << endl;

  cout << "\n# Subtract 4 months" << endl;
  today.subMonth(4);
  printDate(today);
  cout << "The month is " << today.strMonth() << endl;

  cout << "\n# Set day to 14" << endl;
  today.setDay(14);
  printDate(today);
  cout << "The month is " << today.strMonth() << endl;

  cout << "\n# Set year to 2003" << endl;
  today.setYear(2003);   // works also for .setYear(Year(2003))
  printDate(today);

  cout << "\n# Add 10 years" << endl;
  today.addYear(10);
  printDate(today);

  cout << "\n# Sub 20 years" << endl;
  today.subYear(20);
  printDate(today);

  return 0;
}
