// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    int n, sum;
    cin >> n >> sum;
    int coins[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<ll> dp(sum + 1, 0);

    dp[0] = 1;

     for (int j = 1; j <= sum; j++)
    {
        for (int i = 0; i < n; i++)
        {   
            if(j>=coins[i])
            dp[j] =(dp[j]+dp[j - coins[i]])% mod2;
          
        }
    }

    cout << dp[sum] << endl;

    return 0;
}