#include <bits/stdc++.h>

using namespace std;
// const int mod = 1e9+7;
// const int mod = 998244353;

inline void quickread()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1)
    {
        cout << "YES\n";
        cout << n << '\n';
        for (int i = 1; i <= n; i++)
            cout << 1 << " ";
        cout << '\n';
    }
    else if ((n % 2 && k == 2) || k == 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << n / 2 << '\n';
        for (int i = 1; i < n / 2; i++)
            cout << 2 << " ";
        cout << 2 + (n % 2) << '\n';
    }
}
int main()
{
    quickread();
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
