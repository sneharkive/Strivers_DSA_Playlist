/*
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  vector<int> asteroidCollision(vector<int> &asteroids){

    int n = asteroids.size();

    vector<int> st;

    for (int i = 0; i < n; i++){

      // Push the asteroid in stack if a right moving asteroid is seen 
      if (asteroids[i] > 0)
        st.push_back(asteroids[i]);

      // Else if the asteroid is moving left, perform the collisions 
      else {

      //  Until the left moving asteroids are smaller in size, keep on destroying them 
        while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
          st.pop_back();   // Destroy the asteroid
        

      //  If there is left moving asteroid which is of same size 
        if (!st.empty() && st.back() == abs(asteroids[i]))  st.pop_back(); // Destroy both the asteroids
          
      // Otherwise, if there is no left moving asteroid, the right moving asteroid will not be destroyed 
        else if (st.empty() || st.back() < 0)  st.push_back(asteroids[i]); // Storing the array in final state
        
      }
    }

    return st;
  }
};

int main() {
  vector<int> arr = {10, 20, -10};

  /* Creating an instance of Solution class */
  Solution sol;

  /* Function call to determine the state of asteroids after all collisions */
  vector<int> ans = sol.asteroidCollision(arr);

  cout << "The state of asteroids after collisions is: ";
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  return 0;
}