// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

void nodedistK(vector<vector<int>> &adj, vector<vector<ll>> &dp, int k, int node, int parent, ll &count) 
{
    int childcnt = 0;

    for (auto it : adj[node]) 
    {
        if (it != parent)  // Ensure we don't revisit the parent node
        {
            nodedistK(adj, dp, k, it, node, count);
            childcnt++;

            for (int i = 1; i <= k; i++) 
            {
                dp[node][i] += dp[it][i - 1];  // Accumulate distances from all children
            }
        }
    }

    dp[node][0] = 1;  // Distance from a node to itself

    count += dp[node][k];  // Add the paths that are exactly k-distance from node

    ll temp = 0;

    if(childcnt<=1) return;

    for(auto it: adj[node])
    {
        if(it!=parent)
        {
            for(int i=0;i<k-1;i++)
            {
                temp+=dp[it][i]*(dp[node][k-1-i]-dp[it][k-2-i]);
            }
        }
    }
    count += temp/2;
}

int main() 
{
    int n, k;
    cin >> n >> k;

    ll count = 0;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) 
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Assuming rerooting at 1 (1 as the root of the tree)
    nodedistK(adj, dp, k, 1, -1, count);
    cout << count << endl;

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     cout<<dp[i][j]<<" ";

    //     cout<<endl;
    // }

    return 0;
}
