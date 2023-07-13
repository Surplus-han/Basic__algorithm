class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // 枚举第一个数
        for (int i = 0; i < n; i++) {
            // 计算第一个数的最高位数码
            vector<int> X;
            for (int x = nums[i]; x; x /= 10) X.push_back(x % 10);
            // 枚举第二个数
            for (int j = i + 1; j < n; j++)
                // 检查是否互质
                if (gcd(X.back(), nums[j] % 10) == 1) ans++;
        }
        return ans;
    }
};
