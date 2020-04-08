/* The intention of this code is to solve the Game Of Thrones challenge from hackerrank
 * The challenge can be seen here -> https://www.hackerrank.com/challenges/game-of-thrones/problem?h_r=internal-search
 * Author: Lucas Lovato
 * Date: 08/04/2020
 * Update:
*/

#include <bits/stdc++.h>

#define SIZE 255
using namespace std;

int LETTERS_ARRAY[SIZE];

void init()
{
  for (int counterIndex = 0; counterIndex < SIZE; ++counterIndex)
  {
    LETTERS_ARRAY[counterIndex] = 0;
  }
}

bool isAnagramOfPalindrome()
{
  int quantityOfOddNumbers = 0;
  for (int counterIndex = 0; counterIndex < SIZE; ++counterIndex)
  {
    if (LETTERS_ARRAY[counterIndex] & 1)
    {
      ++quantityOfOddNumbers;
    }
  }
  if (quantityOfOddNumbers > 1)
    return false;

  return true;
}

int main()
{
  init();
  string receivedWord;
  cin >> receivedWord;

  for (int receivedWordIndex = 0; receivedWordIndex < receivedWord.size(); ++receivedWordIndex)
  {
    LETTERS_ARRAY[receivedWord[receivedWordIndex]]++;
  }

  if (isAnagramOfPalindrome())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
