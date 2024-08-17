#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7;

bool ispossible(int mid,vector<ll>&arr,vector<ll>&apart,int k)
{
    ll count=0;

    int f=0;
    int s=0;

    int n= arr.size();
    int m= apart.size();

    while(f<n && s<m)
    {
        if(arr[f]-k<= apart[s] && apart[s]<=arr[f]+k )
        {
            count++;
            f++; s++;
        }else if(arr[f]+k<apart[s]) f++;
        else if(apart[s]<arr[f]-k) s++;
    }

    return count>=mid;
}

void searchit(int start,int end , vector<ll> &arr, vector<ll> & apart,int k,int &ans)
{
     if(start>end) return ;

     int mid = (start+end)/2;

     if(ispossible(mid,arr,apart,k))
     {
        ans=mid;
        searchit(mid+1,end,arr,apart,k,ans);
     }else{
        searchit(start,mid-1,arr,apart,k,ans);
     }
}
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

  int ans;
  searchit(0,n,arr,apart,k,ans);
  cout<<ans<<endl;

return 0;
}