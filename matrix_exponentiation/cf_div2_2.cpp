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

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int turn=0;
    
    int min1=arr[0];
    int max1=arr[0];
    int min2=INT_MAX;
    int max2=INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if(arr[i-1]>arr[i])
        turn++;

        if(turn ==0)
        {
           if(arr[i]<min1)
           {
            min1=arr[i];
           }

           if(arr[i]>max1)
           {
            max1=arr[i];
           }
        }

        if(turn==1)
        {
            if(arr[i]<min2)
           {
            min2=arr[i];
           }

           if(arr[i]>max2)
           {
            max2=arr[i];
           }

        }

        if(turn>1)
        break;
    }

    if(turn>1) 
    {
        cout<<"No"<<endl;
    }else if(turn==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        if(max2<=min1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
    }

    
}

return 0;
}