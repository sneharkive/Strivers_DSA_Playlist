#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int>& arr) {
      stack<int> st;
      int n = arr.size();
      vector<int> nse(n);
      vector<int> pse(n);

      for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        nse[i] = !st.empty() ? st.top() : n;
        st.push(i);
      }

      while(!st.empty()) st.pop();

      for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        pse[i] = !st.empty() ? st.top() : -1;
        st.push(i);
      }

      int ans = 0;
      for (int i = 0; i < n; i++) 
        ans = max(ans, arr[i] * (nse[i] - pse[i] + 1));

      return ans;
    }
};