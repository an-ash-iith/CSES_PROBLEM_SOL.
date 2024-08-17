#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 

class Disjointset{
   public:
   vector<int> rank;
   vector<int> parent;
   vector<int> parent2;
   vector<int> exp;

   void Disjoint(int n)
   {
     rank.resize(n+1,0);
     parent.resize(n+1);
     parent2.resize(n+1);
     exp.resize(n+1,0);
  

     for(int i =0;i<=n ;i++) {parent[i]=i;parent2[i]=i; }  //now every one is their self parent  --
   }

      int ultimateParent1(int i)
   {
       return parent2[i]=(parent2[i]== i ? i : ultimateParent1(parent2[i]));
   }


   int getexp(int i)
   { 
    if(parent[i]==i) 
     return exp[i];

     return exp[i]+getexp(parent[i]);
   }

   void Union(int a,int b)
   {
     int u = ultimateParent1(a);
     int v=  ultimateParent1(b);
     
     if(u==v)return;

     if(exp[u]<=exp[v]) 
     {
         parent[v]=u;
         parent2[v]=u;
         exp[v]-=exp[u];
     }
     else {
        parent[u]=v;
        parent2[u]=v;
        exp[u]-=exp[v];
    
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

     if(s=="join")
     {
        cin>>a>>b;
        st.Union(a,b);

     }else if(s=="add")
     {   
        cin>>a>>b;
        int u = st.ultimateParent1(a);
        st.exp[u]+=b;  
      
     }else{
        cin>>a;
        int u = st.getexp(a);
        cout<<u<<endl;
     }
   }

//    for(int i =0;i<=n;i++) cout<<st.exp[i]<<" ";

return 0;
}