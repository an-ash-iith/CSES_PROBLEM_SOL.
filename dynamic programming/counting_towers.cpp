// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    vector<vector<ll>> dp(1e6 + 1, vector<ll>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < 1e6 + 1; i++)
    {
        dp[i][0] = ((2 * dp[i - 1][0] + mod2) % mod2 + dp[i - 1][1]) % mod2;
        dp[i][1] = (dp[i - 1][0] + (4 * dp[i - 1][1] + mod2) % mod2) % mod2;
    }
    
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << (dp[n - 1][0] + dp[n - 1][1] + mod2) % mod2 << endl;
    }
    return 0;
}