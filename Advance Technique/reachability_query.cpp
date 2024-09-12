// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
 
void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, st);
        }
    }
    st.push(node);
}
 
void dfs2(int node, vector<int> &visited, vector<vector<int>> &adj, vector<int> &parent, int leader)
{
    visited[node] = 1;
    parent[node] = leader;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs2(it, visited, adj, parent, leader);
        }
    }
}
 
// Function to find number of strongly connected components in the graph.
vector<vector<int>> kosaraju(int V, vector<vector<int>> &adj, vector<int> &parent)
{
    vector<int> visited(V, 0);
    stack<int> st;
 
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }
 
    // Reverse adjacency list
    vector<vector<int>> rev_adj(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            rev_adj[it].push_back(i);
        }
    }
 
    vector<int> vist(V, 0);
    vector<int> leader;
    vector<vector<int>> adj_cond(V);
 
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vist[node])
        {
            leader.push_back(node);
            dfs2(node, vist, rev_adj, parent, node);
        }
    }
 
    for (int v = 0; v < V; v++)
    {
        for (auto u : adj[v])
        {
            if (parent[v] != parent[u])
            {
                adj_cond[parent[v]].push_back(parent[u]);
            }
        }
    }
 
    return adj_cond;
}
 
void dfs3(int node, vector<bitset<50001>> &track, vector<vector<int>> &adj, vector<int> &visited)
{
    if (visited[node])
        return;
    visited[node] = 1;
 
    for (auto it : adj[node])
    {
        dfs3(it, track, adj, visited);
        track[node] |= track[it];
        track[node][it] = 1;
    }
}
 
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<int>> adj(n);
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
 
    vector<bitset<50001>> track(n); // Correct size
 
    for (int i = 0; i < n; i++) // 0-based indexing
    {
        track[i][i] = 1;
    }
 
    vector<int> parent(n, 0);
    vector<vector<int>> new_adj = kosaraju(n, adj, parent);
 
    vector<int> visited(n, 0);
 
    for (int i = 0; i < n; i++) // 0-based indexing
    {
        if (!visited[i])
        {
            dfs3(i, track, new_adj, visited);
        }
    }
 
    while (q--)
    {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
 
        if (parent[r] == parent[s])
        {
            cout << "YES" << endl;
        }
        else
        {
            int u = parent[r];
            int v = parent[s];
 
            if (track[u][v] == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
 
    return 0;
}