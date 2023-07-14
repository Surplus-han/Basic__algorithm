#include <bits/stdc++.h>

using namespace std;

using LL = long long;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0){
            return 0;
        }
        vector<int>nums(n+1);
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 2;i <= n;i++){
            nums[i] = nums[i/2] + i % 2 * nums[i/2+1];
        }
        return *max_element(nums.begin(),nums.end());
    }
};


int main(){
    Solution solution;
    cout << solution.getMaximumGenerated(7) << std::endl;
    return 0;
}









