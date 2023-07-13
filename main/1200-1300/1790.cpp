#include <bits/stdc++.h>
#include <string>

//const int mod = 1e9+7;
//const int mod = 998244353;

inline void quickread(){
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
}
bool areAlmostEqual(std::string s1, std::string s2) {
	 if(s1 == s2){
            return true;
        }
        int n = s1.size();
        std::vector<int>tmp;
        for(int i = 0;i < n;i++)
        {
            if(s1[i] != s2[i]){
                tmp.emplace_back(i);
            }
        }
        if(tmp.size() != 2){
            return false;
        }
        return s1[tmp[0]] == s2[tmp[1]] and s1[tmp[1]] == s2[tmp[0]];
}

int main(){
	quickread();
	std::string a;
	std::string b;
	std::cin >> a;
	std::cin >> b;
	bool ans = areAlmostEqual(a,b);
	if(ans){
		std::cout << "true" << std::endl;
	}
	else{
		std::cout << "false" << std::endl;
	}
	return 0;
}