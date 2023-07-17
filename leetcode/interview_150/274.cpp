// h指数
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        int ans = 0;
        int i = n - 1;
        while(i >= 0 && citations[i] > ans){
            ans++;
            i--;
        }
        return ans;

    }
};