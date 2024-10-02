// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
typedef pair<ll, pair<ll, ll>> pi;

ll jobScheduling(vector<int> &start, vector<int> &end,
                  vector<int> &profit)
{

    // sort on the basis of end time

    vector<pi> job;
    int n = start.size();

    for (int i = 0; i < n; i++)
    {
        job.push_back({end[i], {start[i], profit[i]}});
    }

    sort(job.begin(), job.end());

    sort(end.begin(), end.end());

    vector<ll> dp(n + 1, 0);

    // dp[i] denotes the maximum profit till ith index --
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        pi temp = job[i - 1];
        int ind = upper_bound(end.begin(), end.end(),
                              temp.second.first-1) -
                  end.begin();

        // you know the just greate index --

        dp[i] = max(dp[i - 1], 1ll*temp.second.second + dp[ind]);
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> start(n), end(n), profit(n);

    for (int i = 0; i < n; i++)
    {
        cin >> start[i], cin >> end[i], cin >> profit[i];
    }

    cout<<jobScheduling(start, end, profit)<<endl;

    return 0;
}