// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

ll powerit(ll base, ll exp)
{
    ll result = 1;
    base = base % mod2; // Take modulo initially to avoid overflow

    while (exp > 0)
    {
        if (exp % 2 == 1) // If the current bit of exp is 1
        {
            result = (result * base) % mod2;
        }

        base = (base * base) % mod2; // Square the base
        exp = exp >> 1; // Halve the exponent
    }

    return result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // this is standard question --

    int n;
    cin >> n;

    vector<ll> num(n);

    ll sum = 0;

    for (int i = 1; i <= n; i++)
    {
        num[i-1] = i;
        sum += num[i-1];
    }

    // cout<<sum<<endl;

    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    sum /= 2;

    vector<vector<ll>> dp(n, vector<ll>(sum + 1, 0));

    // dp[i][j]  -- number of way to get the sum j till the ith index -

    dp[0][num[0]] = 1;
    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= num[i])
            {
                dp[i][j] += dp[i-1][j - num[i]];
                dp[i][j] = dp[i][j] % mod2;
            }
            
        }
    }

    // for(int i=0;i<=sum;i++)
    // {
    //     cout<<dp[n-1][i]<<" ";
    // }

    cout << (dp[n - 1][sum]*powerit(2,mod2-2))%mod2 << endl;

    return 0;
}