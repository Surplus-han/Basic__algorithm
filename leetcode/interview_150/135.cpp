// 分糖果
// 维护左右数组
// r[i] > r[i-1] 则  i 处位置的孩子的糖果数量 > i-1 位置的
// r[i] > r[i+1] 则  i 处位置的孩子的糖果数量 > i+1 位置的
// left(n), right(n)
// 时间复杂度O(n)
// 空间复杂度O(n)
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
            {
                left[i] = 1;
            }
        }

        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1 && ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            else
            {
                right[i] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += max(left[i], right[i]);
        }

        return ans;
    }
};