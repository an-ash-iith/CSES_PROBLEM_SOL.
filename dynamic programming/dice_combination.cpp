// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    int n;
    cin >> n;

    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < 6; i++)
        {   
            if(j>=arr[i])
            dp[j] += dp[j - arr[i]];
            dp[j] = dp[j] % mod2;
        }
    }

    cout << dp[n] << endl;

    return 0;
}