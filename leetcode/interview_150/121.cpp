// 一次遍历
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minp = INT_MAX;
        int maxP = 0;
        for (auto p : prices)
        {
            maxP = max(maxP, p - minp);
            minp = min(p, minp);
        }
        return maxP;
    }
};