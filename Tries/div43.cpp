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

int count =0;
ll maxi=0;
ll sum=0;

       for(int i =0;i<n;i++)
       {
        cin>>arr[i];
        sum+=arr[i];

        maxi=max(maxi,arr[i]);
        if(maxi==sum-maxi)count++;

       }

cout<<count<<endl;

    }
return 0;
}