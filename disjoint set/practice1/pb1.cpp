#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 

class Disjointset{
   public:
   vector<int> rank;
   vector<int> parent;

   void Disjoint(int n)
   {
     rank.resize(n+1,0);
     parent.resize(n+1);

     for(int i =0;i<=n ;i++) parent[i]=i;  //now every one is their self parent  --
   }

   int ultimateParent(int i)
   {
       return parent[i]=(parent[i]== i ? i : ultimateParent(parent[i]));
   }

   void Union(int a,int b)
   {
     int u = ultimateParent(a);
     int v=  ultimateParent(b);
     
     if(u==v)return;

     if(rank[u]>rank[v]) 
     {
         parent[v]=u;
     }else if(rank[u]<rank[v])
     {
        parent[u]=v;
     }else{
        parent[v]=u;
        rank[u]++;
     }
   }
};

int main()
{
   int n,m;
   cin>>n>>m;

   Disjointset st;
   st.Disjoint(n);

   while(m--)
   {
     string s;
     int a,b;
     cin>>s>>a>>b;

     if(s=="union")
     {
        st.Union(a,b);
     }else
     {
        if(st.ultimateParent(a)==st.ultimateParent(b))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
   }

//    for(int i =0;i<=n;i++) cout<<st.parent[i]<<" ";

return 0;
}