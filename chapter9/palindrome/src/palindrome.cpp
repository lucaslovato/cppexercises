#include "palindrome.h"

Palindrome::Palindrome(std::string fName)
  : fileName{fName} {}

Palindrome::~Palindrome() {}

void Palindrome::readWordsFromFile() {

  std::smatch matches;
  std::ifstream ist;
  std::string word;
  std::vector<std::string> vec;
  std::string path = "artifacts/";

  ist.open(path + fileName, std::ifstream::in);

  try {
    if (!ist.is_open()) {
      throw Exception {};
    }
  }
  catch (Palindrome::Exception) {
    std::cerr << "Open file error" << '\n';
  }

  while (ist >> word) {
    bool match = std::regex_search(word, matches, ponctuation);

    if ((match == true)) {
      removeSpecialChars(word);
      if (word.length() >= 3) {
        isPalindrome(word);
        isPermutedPalindrome(word);
      }
    } else {
      if (word.length() >= 3) {
        isPalindrome(word);
        isPermutedPalindrome(word);
      }
    }
  }
  ist.close();
}

bool Palindrome::isPalindrome(std::string str) {

  bool palindrome = true;
  toLowerCase(str);
  for (size_t i = 0; i < str.length(); i++) {
    if (str.at(i) != str.at((str.length()) - i - 1)) {
      palindrome = false;
      break;
    }
  }
  if (palindrome) {
    incrementPalindromes(numPalindromes);
    std::cout << str << " is The Palindrome #" << getNumPalindromes() <<
      "\n";
  }

  return palindrome;
}

bool Palindrome::isPermutedPalindrome(std::string str) {

  std::set<char> mySet;
  int limit;
  toLowerCase(str);
  if (str.length() % 2 == 0) {
    limit = 0;
  } else {
    limit = 1;
  }
  for (size_t i = 0; i < str.length(); i++) {
    if (!mySet.insert(str.at(i)).second) {
      mySet.erase(str.at(i));
    }
  }
  if (limit == mySet.size()) {
    incrementPermutedPalindromes(numPermutedPalindromes);
    std::cout << str << " is The Permuted Palindrome #" <<
      getNumPermutedPalindromes() <<
      "\n";
  }

  return limit == mySet.size();
}

void Palindrome::toLowerCase(std::string &str) {

  std::for_each(str.begin(), str.end(), [](char & c) {
    c = ::tolower(c);
  });
}

void Palindrome::removeSpecialChars(std::string &str) {
  for (size_t i = 0; i < strlen(chars); ++i) {
    str.erase(std::remove(str.begin(), str.end(), chars[i]), str.end());
  }
}
