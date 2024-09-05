#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;

vector<int> dp(2e5 + 1, 0);
int dfs(int node,int parent,vector<vector<int>> &adj)
{
    int k = adj[node].size();
    vector<int> height(k,0);
     
    if(k==0) return 0;
    for(int i=0;i<k;i++)
    {  
        if(adj[node][i]!=parent)
        height[i]=1+dfs(adj[node][i],node,adj);
    }

    sort(height.begin(),height.end(),greater<int>());

    if(height.size()>=2)
    {
        dp[node] = height[0]+height[1];
    }else 
    {
          dp[node]=height[0];
    }

    return height[0];
}
int main()
{
    // there are two way to do this --
    // one is to use the dp and another is very nice observation and is hard to proof ----

    // algorithm --- chose any node and find the furthest node from this and that
    // furthest node initiate another bfs to to find the furthest node and the node
    // and the distance between these two node will be the diameter of the tree  --
    
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //assuming 1 as root node -- 
    dfs(1,-1,adj);
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}