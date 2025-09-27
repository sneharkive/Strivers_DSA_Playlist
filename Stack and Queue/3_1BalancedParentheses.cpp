// 20. Valid Parentheses 

#include<iostream>
#include<stack>
using namespace std;

class Solution {
  private:
    bool isOpening(char c){
        if(c == '(' || c == '{' || c == '[') return true;
        return false;
    }

  public:
  bool isValid(string s) {

    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        if(isOpening(s[i])) st.push(s[i]);
        
        else {
            if(st.empty()) return false;
            else if((s[i] == ')' && st.top() == '(') ||(s[i] == '}' && st.top() == '{') ||(s[i] == ']' && st.top() == '['))
                st.pop();
            else return false;
        }
    }
    return st.empty();
  }
};