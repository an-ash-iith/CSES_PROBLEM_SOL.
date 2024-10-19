// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

void dfs(int parent, int node, vector<int>& visited, vector<vector<int>>& adj, bool& iscycle, int& nd)
{
    if (iscycle) return;

    visited[node] = 1;  // Mark current node as visited
    
    for (auto it : adj[node])
    {
        if (it != parent)
        {
            if (visited[it] == 1)
            {
                iscycle = true;
                nd = it;  // Update `nd` to store a node in the cycle
                break;
            }
            else if (!visited[it])
            {
                dfs(node, it, visited, adj, iscycle, nd);
            }
        }
    }
}

bool dfs2(int parent, int node, int target, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans)
{
    if (parent != -1 && node == target)
    {  
        // cout<<"hi"<<endl;
        // ans.push_back(target);
        return true;
    }
    
    visited[node] = 1;  // Mark the node as visited
    bool found = false;

    for (auto it : adj[node])
    {
        if (it != parent && (!visited[it] || (it==target)))
        {
            ans.push_back(it);

            if (dfs2(node, it, target, adj, visited, ans))
            {
                found = true;
                break;
            }
            else
            {
                ans.pop_back();
            }
        }
    }

    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nd = -1;
    bool iscycle = false;
    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(-1, i, visited, adj, iscycle, nd);
            if (iscycle)
                break;
        }
    }

    if (!iscycle)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> visited2(n + 1, 0);
    vector<int> ans;
    // visited2[nd] = 1;
    ans.push_back(nd);

    dfs2(-1, nd, nd, adj, visited2, ans);
    
    cout<<ans.size()<<endl;
    for (auto it : ans)
        cout << it << " ";
    
    return 0;
}
