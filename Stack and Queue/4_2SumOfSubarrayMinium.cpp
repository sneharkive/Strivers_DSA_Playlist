/*
907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  /* Function to find the indices of
  next smaller elements */
  vector<int> findNSE(vector<int> &arr) {

    // Size of array
    int n = arr.size();

    // To store the answer
    vector<int> ans(n);

    // Stack
    stack<int> st;

    // Start traversing from the back
    for (int i = n - 1; i >= 0; i--) {

      // Get the current element
      int currEle = arr[i];

      /* Pop the elements in the stack until
      the stack is not empty and the top
      element is not the smaller element */
      while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
      

      // Update the answer
      ans[i] = !st.empty() ? st.top() : n;

      /* Push the index of current
      element in the stack */
      st.push(i);
    }

    // Return the answer
    return ans;
  }

  /* Function to find the indices of
  previous smaller or equal elements */
  vector<int> findPSE(vector<int> &arr) {

    // Size of array
    int n = arr.size();

    // To store the answer
    vector<int> ans(n);

    // Stack
    stack<int> st;

    // Traverse on the array
    for (int i = 0; i < n; i++) {

      // Get the current element
      int currEle = arr[i];

      /* Pop the elements in the stack until
      the stack is not empty and the top
      elements are greater than the current element */
      while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
      

      // Update the answer
      ans[i] = !st.empty() ? st.top() : -1;

      /* Push the index of current
      element in the stack */
      st.push(i);
    }

    // Return the answer
    return ans;
  }

public:
  /* Function to find the sum of the
  minimum value in each subarray */
  int sumSubarrayMins(vector<int> &arr) {

    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    // Size of array
    int n = arr.size();

    int mod = 1e9 + 7; // Mod value

    // To store the sum
    int sum = 0;

    // Traverse on the array
    for (int i = 0; i < n; i++) {

      // Count of first type of subarrays
      int left = i - pse[i];

      // Count of second type of subarrays
      int right = nse[i] - i;

      /* Count of subarrays where
      current element is minimum */
      long long freq = left * right * 1LL;

      // Contribution due to current element
      int val = (freq * arr[i] * 1LL) % mod;

      // Updating the sum
      sum = (sum + val) % mod;
    }

    // Return the computed sum
    return sum;
  }
};

int main() {
  vector<int> arr = {3, 1, 2, 5};

  /* Creating an instance of
  Solution class */
  Solution sol;

  /* Function call to find the sum of the
  minimum value in each subarray */
  int ans = sol.sumSubarrayMins(arr);

  cout << "The sum of minimum value in each subarray is: " << ans;

  return 0;
}