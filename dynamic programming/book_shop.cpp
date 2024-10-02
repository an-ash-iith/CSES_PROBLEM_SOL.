// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    // standard easy question of dp --
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> page(n);

    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int j = 0; j < n; j++)
        cin >> page[j];

    // this question is quite similar to coin combination without permutation ---
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
            // cout << dp[j] << " ";
        }

    }

    cout << dp[x] << endl;

    //    for(int i=0;i<=x;i++)
    //    {
    //     cout<<dp[i]<<" ";
    //    }

    return 0;
}