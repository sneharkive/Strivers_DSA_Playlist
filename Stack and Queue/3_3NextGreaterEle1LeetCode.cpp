// 496. Next Greater Element I

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // Value, GreaterValue
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            nge[nums2[i]] = st.empty() ? -1 : st.top();
            
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) 
            ans[i] = nge[nums1[i]];
        
        return ans;
    }
};