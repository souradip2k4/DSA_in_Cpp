// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {


  for(int i = 0; i < haystack.size(); i++){
    if(i + needle.size() > haystack.size()){
      return -1;
    }
    string str = haystack.substr(i, needle.size());

    if(str == needle){
      return i;
    }
  }

  return -1;
}

int main(){

  int r1 = strStr("sadbutsad", "sad");
  int r2 = strStr("leetcode", "leeto");

  cout << r1 << endl;
}
