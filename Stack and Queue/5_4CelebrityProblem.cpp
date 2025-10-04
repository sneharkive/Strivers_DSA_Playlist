/*
Celebrity Problem
Problem Statement: A celebrity is a person who is known by everyone else at the party but does not know anyone in return. 
Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. 
Return the index of the celebrity or -1 if no such person exists.
Note that M[i][i] is always 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int celebrity(vector<vector<int>> &arr){
    int n = arr.size();

    int top = 0, down = n - 1;

    while(top < down){
      if(arr[down][top] == 1) down--;
      else if(arr[top][down] == 1 ) top++;
      else {
        top++;
        down--;
      }
    }

    if(top > down) return -1;

    for(int i = 0; i < n; i++){
      if(i == top) continue;

      // Check if it is not a celebrity
      if(arr[top][i] == 1 || arr[i][top] == 0) 
        return -1;

    }
      
    return top;
  }
};



int main() {
  vector<vector<int>> M = {
        {0, 1, 1, 0}, 
        {0, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}
  };
    
  /* Creating an instance of 
  Solution class */
  Solution sol; 
  
  // Function call to find the index of celebrity
  int ans = sol.celebrity(M);
  
  cout << "The index of celebrity is: " << ans;
  
  return 0;
}
