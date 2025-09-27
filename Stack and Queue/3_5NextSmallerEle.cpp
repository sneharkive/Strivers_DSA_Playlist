// Next Smaller Element

// Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
// If there is no smaller element to the right, then the NSE is -1.

// Input: arr = [4, 8, 5, 2, 25]
// Output: [2, 5, 2, -1, -1]


// Input: arr = [10, 9, 8, 7]
// Output: [9, 8, 7, -1]


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> nse(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= nums[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();
            st.push(nums[i]);
        }

        return nse;
    }
};