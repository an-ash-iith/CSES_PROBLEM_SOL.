#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 
const long long  INF = 1e18 + 5;

ll powerit(ll a, ll b)
{  
    if(a==0) return 1;
    
     ll ans=1;
     ll mult=a;

     while(b>0)
     {
         if(b%2==1)
         {
            ans=ans*mult%mod2;
         }

         mult=(mult*mult)%mod2;
         b=b/2;
     }

     return ans%mod2;
}
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        ll a,b;
        cin>>a>>b;

        cout<<powerit(a,b)<<endl;
    }
return 0;
}