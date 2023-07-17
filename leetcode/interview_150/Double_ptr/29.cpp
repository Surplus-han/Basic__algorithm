// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int f = 2;
        int s = 2;
        while(f < n){
            if(nums[s-2] != nums[f]){
                nums[s] = nums[f];
                ++s;
            }
            ++f;
        }
        return s;

    }
};