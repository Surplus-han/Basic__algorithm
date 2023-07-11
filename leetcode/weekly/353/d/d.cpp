/**
 * 差分数组+贪心
*/

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>f(n+1);
        f[0] = nums[0];
        f[n] = -nums[n-1];
        for(int i = 1;i < n;i++){
            f[i] = nums[i]- nums[i-1];
        }
        
        for(int i = 0;i + k <= n;i++){
            if(f[i] > 0){
                f[i+k] += f[i];
                f[i] = 0;
            }
        }
        for(auto num:f){
            if(num != 0){
                return false;
            }
        }
        return true;
    }
};