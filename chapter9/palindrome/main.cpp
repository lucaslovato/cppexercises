#include "src/palindrome.h"

int main(int argc, char const *argv[]) {

  Palindrome palindrome = { "the-tragedy-of-hamlet-by-w-shakspeare.txt" };
  palindrome.readWordsFromFile();
}
