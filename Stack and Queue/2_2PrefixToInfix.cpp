#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(string s){
  
  stack <string> st;

  for(int i = s.length() - 1; i >= 0; i--){
    char c = s[i];

    // if operand, push to stack
    if (isalnum(c)) st.push(string("") + c);

    else if (isOperator(c)){

      string op1 = st.top(); st.pop();
      string op2 = st.top(); st.pop();
      string exp = "(" + op1 + c + op2 + ")";

      st.push(exp);
    }
  }

  return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";  // Example
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
    return 0;
}
