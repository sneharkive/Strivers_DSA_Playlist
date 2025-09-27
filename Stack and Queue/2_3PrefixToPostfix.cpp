// Prefix to Postfix Conversion

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



int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix (string s){

  stack <char> st;

  string result;

  for(int i = 0; i < s.length(); i++){

    char c = s[i];

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    else if(c == '(')
      st.push(c);
    
    else if(c == ')'){
      while(st.top() != '('){
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    else{
      while(!st.empty() && prec(c) <= prec(st.top())){
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while(!st.empty()){
    result += st.top();
    st.pop();
  }

  return result;
}


int main() {
    string prefix = "*-A/BC-/AKL";  // Example
    cout << endl << "Prefix: " << prefix << endl;

    string infix = prefixToInfix(prefix);
    cout << "Infix: " << infix << endl;

    cout << "Postfix : " << infixToPostfix(infix) << endl ;

    return 0;
}

