//跳跃游戏
// https://leetcode.cn/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_jump = 0;
        for(int i = 0;i < n;i++){
            if(i <= max_jump){
                max_jump = max(max_jump,i+nums[i]);
                if(max_jump >= n-1){
                    return true;
                }
            }
        }
        return false;
    }
};