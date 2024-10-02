// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

vector<vector<ll>> dp;

ll solve(int i, int j, vector<ll> &arr)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int n = arr.size();
    int turn = 1;

    if ((j - i + 1) % 2 == n % 2)
    {
        turn = 0;
    }

    if (turn == 0) // Player 1's turn (maximize score)
    {
        return dp[i][j] = max(arr[i] + solve(i + 1, j, arr),
                              arr[j] + solve(i, j - 1, arr));
    }
    else // Player 2's turn (minimize Player 1's score)
    {
        return dp[i][j] = min(solve(i + 1, j, arr),
                              solve(i, j - 1, arr));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp.resize(n, vector<ll>(n, -1)); // Initialize dp with -1

    cout << solve(0, n - 1, arr) << endl;

    return 0;
}
