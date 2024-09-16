//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
  int n,q;
  cin>>n>>q;

  ll arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  ll prexor[n];
  prexor[0]=arr[0];

  for(int i=1;i<n;i++)
  prexor[i]=prexor[i-1]^arr[i];

  while(q--)
  {
    int a,b;
    cin>>a>>b; a--;b--;
   
   if(a>0)
    cout<<(prexor[b]^prexor[a-1])<<endl;
    else cout<<prexor[b]<<endl;
  }
return 0;
}