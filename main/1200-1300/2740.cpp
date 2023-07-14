#include <bits/stdc++.h>

using namespace std;

using LL = long long;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i = 1;i < n;i++){
            ans = min(abs(nums[i-1]-nums[i]),ans);
        }
        return ans;
        
    }
};
int main(){
    Solution solution;
    vector<int>nums{100,1,10};
    cout << solution.findValueOfPartition(nums) << endl;
    return 0;
}









