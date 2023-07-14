#include <bits/stdc++.h>

using namespace std;

using LL = long long;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int temp = 0;
        for(int i = 0; i < s.length();i++){
            temp+=widths[s[i]-'a'];
            if(temp > 100){
                lines++;
                temp = widths[s[i]-'a'];
            }
        }
        return {lines,temp};
    }
};


int main(){
    Solution solution;
    return 0;
}
