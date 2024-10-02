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

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i-1][j-1] != '*')
            {

                if (i == 1 && j == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] =(dp[i][j] +dp[i - 1][j] + dp[i][j - 1])%mod2;
                }
            }
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}