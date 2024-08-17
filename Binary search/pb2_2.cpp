#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7;


int main()
{
  
  int n,m,k;
  cin>>n>>m>>k;

  //apply the binary search  --

  vector<ll> arr(n);
  vector<ll> apart(m);

  for(int i =0;i<n;i++) cin>>arr[i];
  for(int j=0;j<m;j++) cin>>apart[j];
  
  sort(arr.begin(),arr.end());
  sort(apart.begin(),apart.end());


 ll count=0;

    int f=0;
    int s=0;

    while(f<n && s<m)
    {
        if(arr[f]-k<= apart[s] && apart[s]<=arr[f]+k )
        {
            count++;
            f++; s++;
        }else if(arr[f]+k<apart[s]) f++;
        else if(apart[s]<arr[f]-k) s++;
    }

    cout<<count<<endl;

return 0;
}