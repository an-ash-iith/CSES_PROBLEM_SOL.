// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
typedef pair<ll, ll> pi;

// DFS to validate the distances along the path
bool dfs(int node, int dest, vector<int> &ispart, vector<vector<ll>> &adj, vector<int> &visited, bool &ok)
{
    visited[node] = 1;

    if (node == dest)
    {
        visited[node] = 2;

        if (ispart[node])
        {
            ok = false;
        }

        return true;
    }

    bool path_exists = false;

    for (auto it : adj[node])
    {
        if (visited[it] == 0) // Correct node check
        {
            if (dfs(it, dest, ispart, adj, visited, ok))
            {
                path_exists = true;
                visited[node] = 2;
            }
        }
        else if (visited[it] == 2)
        {
            path_exists = true;
            visited[node] = 2;
        }
    }

    if (path_exists && ispart[node]) // Final check for current node
    {
        ok = false;
    }

    return path_exists;
}

void mark_cycle(int node, vector<int> &ispart, vector<vector<ll>> &adj, vector<int> &visited)
{
    visited[node] = 1;  // Mark node as visited
    ispart[node] = 1;   // Mark node as part of the cycle
    
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])  // If neighbor is not visited, continue DFS
        {
            mark_cycle(neighbor, ispart, adj, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Bellman-Ford algorithm to detect negative weight cycles
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> edges;
    vector<vector<ll>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        edges.push_back({a, b, -c}); // Reverse the edge weight
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    // Bellman-Ford algorithm with n-1 iterations
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
        {
            ll u = edges[i][0], v = edges[i][1], w = edges[i][2];

            if (dist[u] != LLONG_MAX)
            {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    vector<int> ispart(n + 1, 0);
    vector<int> visit(n+1,0);
    for (int i = 0; i < m; i++)
    {
        ll u = edges[i][0], v = edges[i][1], w = edges[i][2];

        if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w)
        {
           if(!visit[v])
          mark_cycle(v,ispart,adj,visit);

        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<ispart[i]<<" ";
    // }

    // DFS to validate the distances
    bool ok = true;

    vector<int> visited(n + 1, 0);

    dfs(1, n, ispart, adj, visited, ok);

    if (!ok || dist[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << -dist[n] << endl; // Negate the distance to reverse the sign
    }

    return 0;
}
