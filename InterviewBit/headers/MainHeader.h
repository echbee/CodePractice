#ifndef __MAIN_HEADER__
#define __MAIN_HEADER__


#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> spiral1(vector<vector<int> > &a);

int reverse(int);

vector<vector<int> > generate(int A);
vector<vector<int> > prettyPrint(int A);

int findCount(const vector<int> &A, int B);

int findMin(const vector<int> &A);

int sqrt(int A);

int searchMatrix(vector<vector<int> > &A, int B);

int searchIn(const vector<int> &A, int B);

int isPalindrome(string A);

string countAndSay(int);

int Myatoi(const string&);

string convert(string A, int B);

string addBinary(string A, string B);

vector<int> getRow(int A);

string longestPalindrome(string s);

void rotate2d(vector<vector<int> > &arr);

int colorful(int A);

vector<vector<int> > anagrams(const vector<string> &A);

int lengthOfLongestSubstring(string A);

vector<vector<int> > generateMatrix(int A);

int maxPoints(vector<int> &A, vector<int> &B);

#endif
