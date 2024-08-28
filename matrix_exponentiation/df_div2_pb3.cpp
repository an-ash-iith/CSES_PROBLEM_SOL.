#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll middleOfThree(ll a, ll b, ll c) {
    if ((a > b && a < c) || (a < b && a > c))
        return a;
    else if ((b > a && b < c) || (b < a && b > c))
        return b;
    else
        return c;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        ll arr[n];

        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        if(n==2)
        {
            cout<<min(arr[0],arr[1])<<endl;
            continue;
        }

        ll max1=LONG_LONG_MIN;;
  


  for (int i = 1; i < n; i++)
  {
    if(min(arr[i],arr[i-1])>max1)
    {
        max1= min(arr[i],arr[i-1]);
    }
  }


  for (int i = 2; i < n; i++)
  {
     ll temp = middleOfThree(arr[i-2],arr[i-1],arr[i]);

       if(temp>max1)
       {
        max1=temp;
       }
  }
  

  cout<<max1<<endl;
    
 }
return 0;
}