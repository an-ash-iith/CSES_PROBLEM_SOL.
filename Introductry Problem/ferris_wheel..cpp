#include <iostream>
#include <bits/stdc++.h>

#define ll long long 
using namespace std;
int main()
{

ll n,k;
cin>>n>>k;

ll arr[n];

for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}

sort(arr,arr+n);

int count=0;

int ini_ptr=0;
int fin_ptr=n-1;

while(ini_ptr<=fin_ptr)
{  
   if(ini_ptr==fin_ptr)
   {
     count++;
    ini_ptr++;
    fin_ptr--;
   }
   else if(arr[ini_ptr]+arr[fin_ptr]<=k)
   {
    ini_ptr++;
    fin_ptr--;
    count++;
   }
   else 
   {
       count++;
       fin_ptr--;
   }
}

cout<<count<<endl;

return 0;
}