#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n0 = 0;
        int n1 = 0;
        int n2 = 0;

        int size = nums.size();

        for (int i = 0; i < size; i++){
            switch (nums[i]) {
                case 0 :
                    n0++;
                    break;
                case 1 :
                    n1++;
                    break;
                case 2 :
                    n2++;
                    break;
            }
        }

        int i = 0; 
        for(int j = 0; j < n0; i++, j++){
            nums[i] = 0;
        }
        for(int j = 0; j < n1; i++, j++){
            nums[i] = 1;
        }
        for(int j = 0; j < n2; i++, j++){
            nums[i] = 2;
        }
        
    }
};