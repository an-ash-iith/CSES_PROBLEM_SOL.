// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(m+2, 0));
    if (arr[0] == 0)
    {
        // you can keep any value --
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }

    else
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {

            for (int j = 1; j <= m; j++)
            {
               

                dp[i][j] = (dp[i - 1][j - 1]+ (dp[i][j] + dp[i - 1][j + 1] + dp[i - 1][j])%mod2) % mod2;
            }
        }
        else
        {
            dp[i][arr[i]] = (dp[i - 1][arr[i] + 1] +(dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]])%mod2) % mod2;
        }
    }
    int ans=0;

    for(int i=1;i<=m;i++)
    {
      ans=(ans+dp[n-1][i])%mod2;  
    }

    cout<<ans<<endl;

    return 0;
}