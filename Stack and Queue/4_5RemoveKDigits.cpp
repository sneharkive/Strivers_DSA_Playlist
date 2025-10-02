// 402. Remove K Digits

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  string removeKDigits(string num, int k) {

    stack<char> st;

    for (int i = 0; i < num.length(); i++) {
      while (!st.empty() && st.top() > num[i] && k != 0){
        st.pop();
        k--;
      }

      st.push(num[i]);
    }

    while (k != 0 && !st.empty()){
      st.pop();
      k--;
    }

    if (st.empty())return "0";

    string s = "";

    while (!st.empty()){
      s += st.top(); 
      st.pop();      
    }
    
    while(s.size() > 0 && s.back() == '0') 
      s.pop_back();
    
    reverse(s.begin(), s.end());

    if (s.empty())return "0";

    return s;
  }
};
