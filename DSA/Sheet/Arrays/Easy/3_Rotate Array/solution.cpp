#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int till = size - (k%size);
        vector<int> v(nums.begin() + till, nums.end());

        for (int i = 0; i < till; i++){
            v.emplace_back(nums[i]);
        }

        copy(v.begin(), v.end(), nums.begin());
    }
};