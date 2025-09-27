
#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

string PostfixToInfix(string s){

  stack<string> st;

  for(int i = 0; i < s.length(); i++){

    if(isalnum(s[i])) st.push(string("") + s[i]);

    else {
      string op1 = st.top(); st.pop();
      string op2 = st.top(); st.pop();
      string exp = "(" + op2 + s[i] + op1 + ")";

      st.push(exp);
    }
  }

  return st.top();
}


int main() {
    string postfix = "AB-DE+F*/";  // Example
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << PostfixToInfix(postfix) << endl;
    return 0;
}