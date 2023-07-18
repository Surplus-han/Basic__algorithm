#include <bits/stdc++.h>

using namespace std;
//const int mod = 1e9+7;
//const int mod = 998244353;

inline void quickread(){
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
}
void solve(){
	int n;
	cin >> n;
	int ans = INT_MIN;
	vector<int>v(n);
	for(int i = 0;i < n;i++){
		cin >> v[i];
	}
	
	vector<int>dp(n);
	dp[0] = v[0];
	for(int i = 1;i < n;i++){
		dp[i] = max(v[i],dp[i-1] + v[i]);
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;


}

int main(){
	quickread();
	solve();
	return 0;
}




