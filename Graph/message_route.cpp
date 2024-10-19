#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;
typedef pair<int, int> pi;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);

    // this is bfs where we will keep track of the parent ---
    queue<int> pq;
    pq.push(1);
    parent[1] = 0;

    while (!pq.empty())
    {
        int sz = pq.size();

        for (int i = 0; i < sz; i++)
        {
            int node = pq.front();
            pq.pop();

            for (auto it : adj[node])
            {
                if (parent[it] == -1)
                {
                    parent[it] = node;
                    pq.push(it);
                }
            }
        }
    }

    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> ans;
        int node = n;

        while (node != 1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(node);

        cout << ans.size() << endl;

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }

        cout<<endl;
    }

    return 0;
}