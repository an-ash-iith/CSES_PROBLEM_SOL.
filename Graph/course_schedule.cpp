//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);

// this is the standard question of topo srot -- 

int n ,m;
cin>>n>>m;

vector<vector<int>> adj(n+1);

vector<int> indegree(n+1,0);

for(int i=0;i<m;i++)
{
    int a,b;
    cin>>a>>b;

    adj[a].push_back(b);
    indegree[b]++;
}

//there is path from a to b --

vector<int> ans;

queue<int> q;

for(int i=1;i<=n;i++)
{
   if(indegree[i]==0)
   {
    q.push(i);
   }
}

bool ok = true;

while(!q.empty())
{
 int temp = q.front();
 q.pop();
 ans.push_back(temp);

 for(auto it:adj[temp])
 {
    indegree[it]--;
    if(indegree[it]<0)
    {
        ok=false;
        break;
    }

    if(indegree[it]==0)
    q.push(it);

 }

}
 if(ans.size()!=n || !ok)
 {
    cout<<"IMPOSSIBLE"<<endl;
 }else 
 {
    for(auto it: ans)
    cout<<it<<" ";
 }
return 0;
}