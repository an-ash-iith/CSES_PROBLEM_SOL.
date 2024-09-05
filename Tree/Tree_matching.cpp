#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod2 = 1e9 + 7;
const ll INF = 1e18 + 5;

vector<vector<ll>> dp;

ll dfs(ll node, ll parent, ll cantake, const vector<vector<ll>>& adj) {
    if (dp[node][cantake] != -1) {
        return dp[node][cantake];
    }

    ll count = 0;
    ll t = adj[node].size();

    // Store the sum of `count_nt` and `count_t` values
    ll sum_nt = 0, sum_t = 0;
    vector<ll> count_t(t, 0);
    vector<ll> count_nt(t, 0);

    for (ll i = 0; i < t; i++) {
        if (adj[node][i] != parent) {
            count_nt[i] = dfs(adj[node][i], node, 1, adj);
            sum_nt += count_nt[i];
            if (cantake) {
                count_t[i] = 1 + dfs(adj[node][i], node, 0, adj);
                sum_t += count_t[i];
            }
        }
    }

    if (!cantake) {
        count = sum_nt;
    } else {
        count = sum_nt;
        for (ll i = 0; i < t; i++) {
            if (adj[node][i] != parent) {
                count = max(count, sum_nt - count_nt[i] + count_t[i]);
            }
        }
    }

    return dp[node][cantake] = count;
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);
    dp.assign(n + 1, vector<ll>(2, -1));

    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << dfs(1, -1, 1 , adj) << endl;

    return 0;
}
