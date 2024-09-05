#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;

typedef pair<int,int> pi;
vector<vector<pi>> dp(2e5 + 1);
int dfs(int node,int parent,vector<vector<int>> &adj)
{
    int k = adj[node].size();
    vector<pair<int,int>> height;
     
    if(k==0){dp[node].push_back({0,-1}); return 0;}
    for(int i=0;i<k;i++)
    {  
        if(adj[node][i]!=parent)
        height.push_back({1+dfs(adj[node][i],node,adj),adj[node][i]});
    }

    sort(height.begin(),height.end(),greater<pi>());

    if(height.size()>=2)
    {
        dp[node].push_back(height[0]);
        dp[node].push_back(height[1]);
    }else 
    {
          dp[node].push_back(height[0]);
    }

    return height[0].first;
}

void dfs2(int node, int parent,vector<vector<int>> & adj,vector<pi> &ans)
{
     
     int k = adj[node].size();
     
     int maxi =0;

     if(parent!=-1)
     {
        //for the given node maximum from the child 

        for(auto it: dp[node])
        {
            maxi = max(maxi,it.first);
        }

        //maximum from the parent -- 

        if(ans[parent].second!=node)
        {
            maxi = max(maxi,ans[parent].first);
        }else{

        for(auto it: dp[parent])
        {
            maxi = max(maxi,it.first);
        }
        }
       

     }

     for(int i =0;i<k;i++)
     {
        int nbour = adj[node][i];

        if(nbour!=node)
        {
          dfs2(nbour,node,adj,ans);
        }
     }
}

int main()
{
   
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
    vector<pi> ans(n+1);
    ans[1] = dp[1][0];

    //apply dfs and calculate for other -- 

    dfs2(1,-1,adj,ans);

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}