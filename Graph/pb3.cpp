#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 
const long long  INF = 1e18 + 5;

void dfs(int node,vector<vector<int>> &adj,vector<int> &visited)
{
    visited[node]=1;

    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            dfs(adj[node][i],adj,visited);
        }
    }

}
int main()
{
  int n,m;
  cin>>n>>m;

  //there are n nodes -- 

  vector<int> visited(n+1,0);

  //lets make the adjacency list -- 
  
  vector<vector<int>> adj(n+1);

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 vector<int> ans;

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
        ans.push_back(i);
        dfs(i,adj,visited);
    }
  }

  //number of roads will one less than number of the element -- 

  cout<<ans.size()-1<<endl;

  for(int i=0;i<ans.size()-1;i++)
  {
    cout<<ans[i]<<" "<<ans[i+1]<<endl;
  }

return 0;
}