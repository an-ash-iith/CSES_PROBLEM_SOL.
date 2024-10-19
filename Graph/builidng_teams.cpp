#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 
const long long  INF = 1e18 + 5;
typedef pair<int,int> pi;
int main()
{
 int n,m;
 cin>>n>>m;

     vector<vector<int>> adj(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

vector<int> color(n+1,-1);
//lets start with any color---

queue<int> pq;

for(int k =1;k<=n;k++)
{

if(color[k]!=-1) continue;

pq.push(k);
color[k]=0;

int turn =0;

while(!pq.empty())
{
    int sz = pq.size();
     turn=1-turn;

    while(sz--)
    {
         int node = pq.front();
         pq.pop();
          
         for(int i=0;i<adj[node].size();i++)
         {
            if(color[adj[node][i]]==-1)
            {
                color[adj[node][i]]=turn;
                pq.push(adj[node][i]);
            }else{

                   if(color[adj[node][i]]!=turn)
                   {
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                   }
            }
         }
    }
}

}

for(int i=1;i<=n;i++)
{
    cout<<color[i]+1<<" ";
}

cout<<endl;

return 0;
}