#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 
int main()
{

//nearly we can do it o(n^2) 

int n;
cin>>n;

// vector<bitset<3000>> nums(n,false);
 vector<bitset<3000>> nums(n);  //automaticaly constructor initializes all bits to 0 by default,

for(int i =0;i<n;i++)
{
    
        string temp;
        cin>>temp;

       for(int j=0;j<n;j++)
        if(temp[j]=='1') nums[i][j]=1;
    }

// //now perforf and operation 
ll ans=0;

for(int i =0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        // int sb = __builtin_popcount(nums[i] & nums[j]); //this dont work on integer  --
        int sb = (nums[i] & nums[j]).count();
        // cout<<nums[i]<<" " <<nums[j]<<" "<<sb<<" ";
        ans+=((ll)sb*(sb-1))/2;
    }
}

cout<<ans<<endl;



return 0;
}

// #include <bits/stdc++.h>
// #pragma GCC target("popcnt")
// #define ll long long
// using namespace std;
// const int mod2 = 1e9+7;

// int main() {
//     int n;
//     cin >> n;

//     bitset<3004> nums[n];

//     for(int i = 0; i < n; i++) {
//      cin>>nums[i];
//     }

//     ll ans = 0;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             int sb = (nums[i] & nums[j]).count();
//             ans += (ll)sb * (sb - 1) / 2;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// #pragma GCC target("popcnt")

// using namespace std;
// typedef long long ll;
// const int maxN = 3005;

// int N;
// ll ans;
// bitset<maxN> B[maxN];

// int f(int X){
//     return X*(X-1);
// }

// int main(){
//     cin.sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N;
//     for(int i = 0; i < N; i++)
//         cin >> B[i];

//     for(int i = 0; i < N; i++)
//         for(int j = i+1; j < N; j++)
//             ans += f((B[i]&B[j]).count());

//     cout << (ans/2)<<endl;
// }
