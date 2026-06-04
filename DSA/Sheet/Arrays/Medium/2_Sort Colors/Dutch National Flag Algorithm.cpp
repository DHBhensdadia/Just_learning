#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // 3 itrators
        auto low = nums.begin();
        auto mid = nums.begin();
        auto high = prev(nums.end());

        // itration through array
        
        while ( mid <= high ) { 
            switch (*mid) {
                case 0 :
                    swap(*low, *mid);
                    low++;
                    mid++;
                    break;
                
                case 1 :
                    mid++;
                    break;
                
                case 2 :  
                    swap(*mid, *high);
                    high--;
                    break;
            }

        }
        
    }
}; 