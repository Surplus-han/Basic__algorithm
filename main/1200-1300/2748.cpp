class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // ö�ٵ�һ����
        for (int i = 0; i < n; i++) {
            // �����һ���������λ����
            vector<int> X;
            for (int x = nums[i]; x; x /= 10) X.push_back(x % 10);
            // ö�ٵڶ�����
            for (int j = i + 1; j < n; j++)
                // ����Ƿ���
                if (gcd(X.back(), nums[j] % 10) == 1) ans++;
        }
        return ans;
    }
};
