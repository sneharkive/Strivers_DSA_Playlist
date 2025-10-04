/*
85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) 
          st.pop();
        
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) 
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      
      return maxA;
    }
 
    public:
    int maximalRectangle(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      vector<vector<int>> prefixSum(n, vector<int>(m));

      for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++) {
          sum += matrix[i][j];
          if(matrix[i][j] == 0) sum = 0;    
          prefixSum[i][j] = sum;
        }
      }
      
      int maxArea = 0;

      for(int i = 0; i < n; i++){
        int area = largestRectangleArea(prefixSum[i]);

        maxArea = max(maxArea, area);
      }

      return maxArea;
    }
};