// https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
// ̰��

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int rmost = 0;
        int max_sum = 0;
        for(int i = 0; i < n-1;i++)
        {
            if(max_sum  >= i)
            {
                max_sum= max(max_sum,i+nums[i]);
            }
            if( i == rmost){//��һ��
                rmost = max_sum;
                ans++;
            }
        }
        return ans;
    }
};