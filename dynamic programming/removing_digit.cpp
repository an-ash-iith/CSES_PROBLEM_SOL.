//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
  int n;
  cin>>n;

  //dp[i]  -- denotes the number of way to reduce the number i to 0 --
  vector<ll> dp(n+1,INT_MAX);
  dp[0]=0;
  for(int i=1;i<=n;i++)
  {
     ll temp =i;

     while(temp>0)
     {
        dp[i]=min(dp[i],1+dp[i-(temp%10)]);
        temp=temp/10;
     }
  }

  if(dp[n]==INT_MAX) dp[n]=-1;

  cout<<dp[n]<<endl;

return 0;
}