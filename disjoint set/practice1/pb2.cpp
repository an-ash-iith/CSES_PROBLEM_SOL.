#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 

class Disjointset{
   public:
   vector<int> rank;
   vector<int> parent;
   vector<int> size;
   vector<int>mini;
   vector<int>maxi;

   void Disjoint(int n)
   {
     rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1,1);
     mini.resize(n+1,INT_MAX);
     maxi.resize(n+1,INT_MIN);

     for(int i =0;i<=n ;i++) {parent[i]=i; mini[i]=i; maxi[i]=i;}  //now every one is their self parent  --
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
         size[u]+=size[v];
         mini[u]=min(mini[u],mini[v]);
         maxi[u]=max(maxi[u],maxi[v]);

     }else if(rank[u]<rank[v])
     {
        parent[u]=v;
         size[v]+=size[u];
         mini[v]=min(mini[u],mini[v]);
         maxi[v]=max(maxi[u],maxi[v]);
     }else{
        parent[v]=u;
        size[u]+=size[v];
        mini[u]=min(mini[u],mini[v]);
        maxi[u]=max(maxi[u],maxi[v]);

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
     cin>>s;

     if(s=="union")
     {
        cin>>a>>b;
        st.Union(a,b);
     }else
     {   
        cin>>a;
        int u = st.ultimateParent(a);
        
        cout<< st.mini[u]<<" "<<st.maxi[u]<<" "<<st.size[u]<<endl;
     }
   }

//    for(int i =0;i<=n;i++) cout<<st.parent[i]<<" ";

return 0;
}