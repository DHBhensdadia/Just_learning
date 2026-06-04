#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans; 
        map<int, int> mp;
        
        

        for (int i = 0; i < size; i++) {
            int required = target - nums[i];

            auto re = mp.find(required);

            if (re == mp.end()){
                mp[nums[i]] = i;
            }else {
                ans.push_back(i);
                ans.push_back(re->second);
            }
        }

        return ans;
    }
};