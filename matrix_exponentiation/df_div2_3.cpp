#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;
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

        ll max1=INT_MIN;
  
        for (int i = 0; i < n; i++)
        {

            if(i<n-1)
            {
            if(arr[i]<=arr[i+1])
            {
              if(arr[i]>max1)
              max1=arr[i];
            }

            }
      
      if(i>=1)
      {
            if(arr[i]<=arr[i-1]) 
            {
                if(arr[i]>max1)
                max1=arr[i];
            }

      }

            
        }

 for (int i = 0; i < n; i++)
 {
    if(i>=2)
    {
    if(arr[i-1]==arr[i] || arr[i-2]==arr[i])
    {
          
              if(arr[i]>max1)
              max1=arr[i];
    }
  
    }

    if(i<=n-3)
    {
        if(arr[i+1]==arr[i] || arr[i+2]==arr[i])
    {
        
              if(arr[i]>max1)
              max1=arr[i];
        
    }

    }

    
 }
 

 cout<<max1<<endl;
        
        
    }

return 0;
}