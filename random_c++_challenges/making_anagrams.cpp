/* This code wass used to solve Hackerranks challenge:
https://www.hackerrank.com/challenges/making-anagrams/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
It needs to be organized a bit before inputing it there though. The code passed all tests in the challenge.

This code receives two strings and checks how many deletions are necessary to turn them into anagrams of each other.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <algorithm>

using namespace std;
int A[26] = {0}; // All alphabet, from 0 to 25;
int B[26] = {0};
int C[26] = {0};
void evaluateS(string,int[]);
void subtractArrays(int[],int[],int[]);
int howManyDeletions(int[]);

int main() {
  string s1,s2;

  cin >> s1 >> s2;
  evaluateS(s1, A);
  evaluateS(s2, B);
  subtractArrays(A,B,C);
  int c = howManyDeletions(C);
  cout << c << endl;

}
// Gets a string and checks how many of each letter it has, defined by a size 26 int array
void evaluateS(string S,int K[26]){
  for (int i = 0; i < S.length(); i++){
      K[ S[i] - 'a']++;
  }
}
// Receives two int arrays and subtracts each corresponding value between them
void subtractArrays(int A[], int B[],int C[]){
 for (int i = 0; i < 26; i++){
   C[i] = A[i] - B[i];
 }
}

// Finds the number of deletions required to turn them into anagrams
int howManyDeletions(int K[]){
  int count = 0;
    for (int i = 0; i < 26; i++){
      count += abs(K[i]);

  }
  return count;
}
