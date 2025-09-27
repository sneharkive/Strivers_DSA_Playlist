// 155. Min Stack

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st; // value, min

    MinStack() {
        
    }
    
    void push(int val) {
        
        if (st.empty()) st.push({val, val});
        else {
            int minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */