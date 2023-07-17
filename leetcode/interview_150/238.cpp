// https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

// nums[i] == i 以前的数字乘积 * i 位置 以后的数字的乘积

// ans[i] = 前缀积 * 后缀积
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> L(n, 0), R(n, 0);

        vector<int> ans(n);

        L[0] = 1;
        for (int i = 1; i < n; i++)
        {
            L[i] = nums[i - 1] * L[i - 1];
        }

        R[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            R[i] = nums[i + 1] * R[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};