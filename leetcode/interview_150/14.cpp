class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
       int m = strs[0].size();
       if(!strs.size()) return "";
       for(int i = 0; i < m;i++)
       {
           char c = strs[0][i];
           for(int j = 1; j < n;j++)
           {
               if(i == m || strs[j][i] != c)
               {
                   return strs[0].substr(0,i);
               }
           }
       }
       return strs[0];
    }
};