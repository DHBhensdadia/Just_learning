#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int* nums, int numsSize) 
{
    int k = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i-1] != nums[i])
        {
            nums[++k] = nums[i]; 
        }
    }        

    return k + 1;
}