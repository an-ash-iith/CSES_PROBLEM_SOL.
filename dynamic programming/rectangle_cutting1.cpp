
// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

int main() {
    int n, m;
    cin >> n >> m;

    if (n < m) swap(n, m);

    // dp[i][j] = minimum number of cuts to make square with dimensions i and j
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0; // No cuts needed if it's already a square
            } else {
                dp[i][j] = INT_MAX;
                // Try all possible horizontal cuts
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }

                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
