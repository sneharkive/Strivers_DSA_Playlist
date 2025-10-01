/*
2104. Sum of Subarray Ranges

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
      while (!st.empty() && arr[st.top()] >= currEle) st.pop();
      

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
  next greater elements */
  vector<int> findNGE(vector<int> &arr) {

    // Size of array
    int n = arr.size();

    // To store the answer
    vector<int> ans(n);

    // Stack
    stack<int> st;

    // Start traversing from the back
    for (int i = n - 1; i >= 0; i--){

      // Get the current element
      int currEle = arr[i];

      /* Pop the elements in the stack until
      the stack is not empty and the top
      element is not the greater element */
      while (!st.empty() && arr[st.top()] <= currEle)  st.pop();

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
  vector<int> findPSE(vector<int> &arr){

    // Size of array
    int n = arr.size();

    // To store the answer
    vector<int> ans(n);

    // Stack
    stack<int> st;

    // Traverse on the array
    for (int i = 0; i < n; i++)
    {

      // Get the current element
      int currEle = arr[i];

      /* Pop the elements in the stack until
      the stack is not empty and the top
      elements are greater than the current element */
      while (!st.empty() && arr[st.top()] > currEle) st.pop();
      

      // Update the answer
      ans[i] = !st.empty() ? st.top() : -1;

      /* Push the index of current
      element in the stack */
      st.push(i);
    }

    // Return the answer
    return ans;
  }

  /* Function to find the indices of
  previous greater or equal elements */
  vector<int> findPGE(vector<int> &arr) {

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
      elements are smaller than the current element */
      while (!st.empty() && arr[st.top()] < currEle) st.pop();

      // Update the answer
      ans[i] = !st.empty() ? st.top() : -1;

      /* Push the index of current
      element in the stack */
      st.push(i);
    }

    // Return the answer
    return ans;
  }

  /* Function to find the sum of the
  minimum value in each subarray */
  long long sumSubarrayMins(vector<int> &arr) {

    vector<int> nse = findNSE(arr);

    vector<int> pse = findPSE(arr);

    // Size of array
    int n = arr.size();

    // To store the sum
    long long sum = 0;

    // Traverse on the array
    for (int i = 0; i < n; i++)
    {

      // Count of first type of subarrays
      int left = i - pse[i];

      // Count of second type of subarrays
      int right = nse[i] - i;

      /* Count of subarrays where
      current element is minimum */
      long long freq = left * right * 1LL;

      // Contribution due to current element
      long long val = (freq * arr[i] * 1LL);

      // Updating the sum
      sum += val;
    }

    // Return the computed sum
    return sum;
  }

  /* Function to find the sum of the
  maximum value in each subarray */
  long long sumSubarrayMaxs(vector<int> &arr)
  {

    vector<int> nge = findNGE(arr);

    vector<int> pge = findPGE(arr);

    // Size of array
    int n = arr.size();

    // To store the sum
    long long sum = 0;

    // Traverse on the array
    for (int i = 0; i < n; i++)
    {

      // Count of first type of subarrays
      int left = i - pge[i];

      // Count of second type of subarrays
      int right = nge[i] - i;

      /* Count of subarrays where
      current element is minimum */
      long long freq = left * right * 1LL;

      // Contribution due to current element
      long long val = (freq * arr[i] * 1LL);

      // Updating the sum
      sum += val;
    }

    // Return the computed sum
    return sum;
  }

public:
  /* Function to find the sum of
  subarray ranges in each subarray */
  long long subArrayRanges(vector<int> &arr)
  {

    // Return the result
    return (sumSubarrayMaxs(arr) -
            sumSubarrayMins(arr));
  }
};

int main()
{
  vector<int> arr = {1, 2, 3};

  /* Creating an instance of
  Solution class */
  Solution sol;

  /* Function call to find the sum of
  subarray ranges in each subarray */
  long long ans = sol.subArrayRanges(arr);

  cout << "The sum of subarray ranges is: " << ans;

  return 0;
}