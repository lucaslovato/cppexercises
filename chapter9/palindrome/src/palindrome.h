#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <set>

class Palindrome {
public:

  class Exception {};

  Palindrome(std::string);
  void removeSpecialChars(std::string&);
  void readWordsFromFile();
  bool isPalindrome(std::string);
  bool isPermutedPalindrome(std::string);
  inline int getNumPalindromes() {
    return numPalindromes;
  }

  inline int getNumPermutedPalindromes() {
    return numPermutedPalindromes;
  }

  ~Palindrome();
private:
  const std::regex ponctuation { "[[:punct:]]" };
  char const* chars { (char *) ".,?!.:;_,!'$%*#^&+/-" };
  int numPalindromes = 0;
  int numPermutedPalindromes = 0;
  std::string fileName;
  void toLowerCase(std::string&);
  inline void incrementPalindromes(int &palindrome) {
    palindrome++;
  }

  inline void incrementPermutedPalindromes(int &palindrome) {
    palindrome++;
  }
};
