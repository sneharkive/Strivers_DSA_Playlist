// Lec - 5 Next Greater Element (Stack and Queue Playlist)

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();
            st.push(nums[i]);
        }

        return nge;
    }
};