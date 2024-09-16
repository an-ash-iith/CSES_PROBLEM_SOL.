//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
    //it can be done with segment tree also -- but most suitabel algorith is using sparse table -- 

    int n,q;
    cin>>n>>q;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    //lets create the sparse table - 
    // int k = (int)log2(n);  //this is the max power that will be accomodated --
    int k = __bit_width(n)-1;
    int dp[k+1][n];   //dp[j][i]  denotes you are starting at ith index and seeing 2^j from there -- or min of i to 2^j-1 elements 
    
    for (int i = 0; i < n; i++) {
      dp[0][i] = arr[i]; }
    
    //creation of the table -- 
    for(int i=1;i<=k;i++)
    {   
        for(int j=0;(j+(1<<i))<=n;j++)
        {      
               dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))]); 
        }
    }
 
    while(q--)
    {
        int a,b;
        cin>>a>>b; 
        a--;b--;

        int mid = __bit_width(b-a+1)-1;
        cout<< min(dp[mid][a],dp[mid][b-(1<<mid)+1])<<endl;   //it should be noted that here some numbers 
        //will be intersection so it cant be use in sum finding but can be used in minimum value  -- 
    }
return 0;
}