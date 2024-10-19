// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
typedef pair<ll, pair<ll, ll>> pi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // will apply dijakstra + dp --

    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >>c;

        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MAX));

    dp[1][0] = 0;
    // dp[1][1] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // first contain distance and second contain node and thd discound used or not

    pq.push({0, {1, 0}});

pq.push({0, {1, 0}}); // Distance 0 for node 1 with discount unused.


    while (!pq.empty())
    {
        pi temp = pq.top();
        pq.pop();

        ll node = temp.second.first;
        ll used = temp.second.second;
        ll dist = temp.first;
        
            if (dist > dp[node][used]) continue;

        for (auto it : adj[node])
        {
            ll nbour = it.first;
            ll add = it.second;
         
         // i am not goind to change the state of used -- 

            if (dist + add < dp[it.first][used])
            {
                dp[it.first][used] = dist + add;
                pq.push({dist + add, {nbour, used}});
            }

            
                if (!used && dist + (add / 2) < dp[it.first][1 - used])
                {
                    dp[it.first][1 - used] = dist + add / 2;
                    pq.push({dist + add / 2, {nbour, 1}});
                }
            
        }
    }

     dp[n][0] = min(dp[n][0],dp[n][1]);

     cout<<dp[n][0]<<endl;
    return 0;
}