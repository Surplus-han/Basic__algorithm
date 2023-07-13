#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//const int mod = 1e9+7;
//const int mod = 998244353;

inline void quickread(){
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
}
string replaceDigits(string s) {
        int n = s.size();
        for (int i = 1; i < n; i += 2){
            s[i] = s[i-1] + (s[i] - '0');
        }
        return s;
    }

int main(){
	quickread();
	std::string a;
    cin >> a;
	std::cout << replaceDigits(a) << std::endl;
	return 0;
}




