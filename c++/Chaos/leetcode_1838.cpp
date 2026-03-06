#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        map<int, int> m;
        for(auto i : nums){
            m[i]++;
        }
        int nsize = nums.size();
        int msize = m.size();
        
        vector<int> count(msize);
        vector<pair<int, int>> base(m.begin(), m.end());
    
        
        //stage 1
        for (int i = 0; i < msize; i++){
            
            // refresh
            vector<pair<int, int>> v = base;
            int wk = k;
            auto itm = v.begin();
            advance(itm, i);
            
            if(i == 0){
                // no use of k
            }else{
                // we have elements to which we can add k
                // stage 2
                auto itp = itm;
                itp--;
                    // k finisher
                    while(1){
                        if(itp != v.begin() && itp->second == 0){
                            itp--;
                        }else if (itp == v.begin() && itp->second == 0){
                            break;
                        }

                        int diff = (itm->first) - (itp->first);
                        int reducable_k = wk/diff;
                        if (reducable_k > itp->second){
                            wk -= (itp->second)*diff;
                            (itm->second) += (itp->second);
                            (itp->second) = 0;
                            continue;
                        }else if (reducable_k <= itp->second) {
                            itm->second += reducable_k;
                            itp->second -= reducable_k;
                            break;
                        }

                    }
            }

            //stage 3
            count[i] = itm->second;
        }

        //stage 4
        int max = *max_element(count.begin(), count.end());

        return max;
        
    }
};