// Inefficient code -----------------

// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int mod2 = 1e9 + 7;
// const long long INF = 1e18 + 5;
// typedef pair<ll, ll> pi;
// typedef pair<int, pair<int, int>> pii;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pi>> adj(n + 1);

//     for (int i = 0; i < m; i++)
//     {
//         ll a, b, c;
//         cin >> a >> b >> c;
//         adj[a].push_back({b, c});
//     }

//     // this can be done using simple dijakstra ----
//     priority_queue<pi, vector<pi>, greater<pi>> pq;
//     vector<ll> distance(n+1, LLONG_MAX);
//     pq.push({0, 1});
//     distance[1] = 0;
//     while (!pq.empty())
//     {
//         pi temp = pq.top();
//         pq.pop();

//         ll dist = temp.first;
//         ll node = temp.second;

//         for (int i = 0; i < adj[node].size(); i++)
//         {
//             ll nbour = adj[node][i].first;
//             ll weight = adj[node][i].second;

//             if (dist + weight < distance[nbour])
//             {
//                 distance[nbour] = dist + weight;
//                 pq.push({distance[nbour], nbour});
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << distance[i] << " ";
//     }
//     cout<<endl;

//     return 0;
// }


// Effecient code  ------------------

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18 + 5;
typedef pair<ll, ll> pi;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<ll> distance(n + 1, INF);
    vector<bool> processed(n + 1, false);

    pq.push({0, 1});
    distance[1] = 0;

    while (!pq.empty())
    {
        ll node = pq.top().second;
        pq.pop();

        if (processed[node])
            continue;
        processed[node] = true;

        for (const auto& [nbour, weight] : adj[node])
        {
            if (distance[node] + weight < distance[nbour])
            {
                distance[nbour] = distance[node] + weight;
                pq.push({distance[nbour], nbour});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (distance[i] == INF ? -1 : distance[i]) << " ";
    }
    cout << endl;

    return 0;
}
