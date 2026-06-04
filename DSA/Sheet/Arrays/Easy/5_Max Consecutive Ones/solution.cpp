#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int size = nums.size();

        int tc;

        for (int i = 0; i < size; i++){
            if(nums[i] == 1){
                tc = 0;
                for( ; i < size; i++){
                    if (nums[i] == 0){
                        if (tc > max ){
                            max = tc;
                        }
                        break;
                    }
                    tc++;
                }
            }
        }

                        if (tc > max ){
                            max = tc;
                        }

        return max;
    }
};