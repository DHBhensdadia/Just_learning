#include <bits/stdc++.h>
using namespace std;

int majorityElement(int* nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) 
    {
        if(nums[i] == -1)
        {
            continue;
        }
        
        int count = 1;
        for (int j = i + 1; j < numsSize; j++) 
        {
            if (nums[i] == nums[j]) 
            {
                nums[j] = -1;
                count++;
            }
        }
        if (count > numsSize / 2) 
        {
            return nums[i];
        }
    }

    return 0;
}