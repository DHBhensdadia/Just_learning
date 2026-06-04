#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        int count{0};
        for (int i = 1; i < size; i++){
            if (nums[i - 1] > nums[i]){
                count++;
            }
        }

        if (count == 0){
            return true;
        }else if (count == 1){
            if (nums[0] >= nums[size - 1]){
                return true;
            }
        }

        return false;
    }
};