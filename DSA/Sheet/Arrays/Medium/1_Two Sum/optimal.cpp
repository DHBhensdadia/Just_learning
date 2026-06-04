#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans; 
        multimap<int, int> mp;

        for (int i = 0; i < size; i++) {
            mp.insert({nums[i], i}); 
        }
        
        vector<pair<int, int>> vmp(mp.begin(), mp.end());
        
        auto lit = vmp.begin();
        auto rit = vmp.end();
        rit--;
        for ( ; lit < rit ; ) {
            if (lit->first + rit->first == target) {
                ans.push_back(lit->second);
                ans.push_back(rit->second);
                lit++;
                rit--;
            }else if (lit->first + rit->first < target) {
                lit++;
            }else {
                rit--;
            }
        }

        return ans;
    }
};