#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int somthing = nums[0];
        for(int i = 1; i < nums.size(); i++){
            somthing ^= nums[i];
        }

        return somthing;
    }
};