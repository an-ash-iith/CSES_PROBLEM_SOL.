// Author: Ashwin Kr.
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
    cin >> n;

    vector<int> arr(n);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    int maxsum = maxi * n;
    vector<ll> sum(maxsum + 1, 0); // will keep track record that this sume is possible or not
    sum[0] = 1;

    for (int i = 0; i < n; i++)
    {

        for (int j = maxsum; j >= 0; j--)
        {
            if (sum[j] == 1)
            {
                sum[j + arr[i]] = 1;
            }
        }
    }
  
    int count=0;

    for (int i = 1; i <= maxsum; i++)
    {
        if (sum[i] == 1)
        {
           count++;
        }
    }
    
    cout<<count<<endl;

        for (int i = 1; i <= maxsum; i++)
    {
        if (sum[i] == 1)
        {
           cout<<i<<" ";
        }
    }

    cout<<endl;
    return 0;
}