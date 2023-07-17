// 数组反转再反转
class Solution {
public:
    void reverse(vector<int>&nums,int start,int end){
        while(start < end){
            std::swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};