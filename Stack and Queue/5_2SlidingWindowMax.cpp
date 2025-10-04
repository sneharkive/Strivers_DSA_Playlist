/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k){

    deque<int> dq; // stores indexes of elements
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++){
      // Remove elements out of the current window
      if (!dq.empty() && dq.front() == i - k) dq.pop_front();

      // Remove all smaller elements (they’ll never be the max)
      while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

      dq.push_back(i);

      // Add to result only after first k elements
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }

    return ans;
  }
};
