#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;
int main()
{
    // as the largest number can be 2*10^5 so the largest divisor can be 10^6 only --
    // lets make one map that will keep track record number of element with this factor --

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> count(1e6 + 1, 0);

    for (int i = 0; i < n; i++)
    {   
        int j=1;
        for(j=1;j*j<arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                count[j]++;
                count[arr[i]/j]++;
            }
        }

        if(j*j==arr[i])count[j]++;
    }

    for(int i=1e6+1;i>0;i--)
    {
        if(count[i]>=2)
        {
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}