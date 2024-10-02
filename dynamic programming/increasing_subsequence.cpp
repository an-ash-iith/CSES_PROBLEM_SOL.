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
 
 int n;
 cin>>n;
 
 vector<ll> arr(n);
 for(int i=0;i<n;i++) cin>>arr[i];

 vector<ll> ans;

 //this can be done using two approach -- 
 //one is dp approach with time complexity of 0(n^2) 
 //but using some observation and keepint track track record of the 
 //best last element for the given length can solve this proble in 0(nlogn)

 vector<ll> track;

 for(int i=0;i<n;i++)
 {
    int ind = lower_bound(track.begin(),track.end(),arr[i])- track.begin();

    if(ind==track.size())
    {
        track.push_back(arr[i]);
    }else{
        track[ind] = arr[i];
    }
 }

 cout<<track.size()<<endl;

return 0;
}