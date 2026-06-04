#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int count{0};
        for (int i = 0; i < size - count; ){
            if (nums[i] != 0){
                i++;
                continue;
            }else {
                count++;
                for (int j = i + 1; j < size; j++){
                    int temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};