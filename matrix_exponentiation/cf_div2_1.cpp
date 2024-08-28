#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main()
{

int t;
cin>>t;

while (t--)
{
    int n;
    cin>>n;

    ll arr[n];
    
    ll min1=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];

        if(arr[i]<min1) min1= arr[i];
    }

   ll min2= INT_MAX;

//find 2nd smallest element that is coprime of first
    for (int i = 0; i < n; i++)
    {
        if(arr[i]%min1!=0)
        {
            if(arr[i]<min2)
            min2=arr[i];
        }
    }

    if(min2==INT_MAX)
    {
        cout<<"Yes"<<endl;
        continue;
    }

    //now min 1 and min2 are contestent for the divisor to divide
    bool found = true;

    for (int i = 0; i < n; i++)
    {
        if((arr[i]%min1 !=0) && (arr[i]%min2!=0))
        {  
            found = false;
            break;
        }
    }
    
    if(found == false)
    {
        cout<<"No"<<endl;
    }else
    {
        cout<<"Yes"<<endl;
    }

    
}

return 0;
}