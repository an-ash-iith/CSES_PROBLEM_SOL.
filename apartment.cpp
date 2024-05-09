#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main()
{

ll n,m,k;
cin>>n>>m>>k;

ll desired[n];
ll present[m];

for (ll i = 0; i < n; i++)
{
    cin>>desired[i];

}
for (ll i = 0; i < m; i++)
{
    cin>>present[i];

}
sort(desired,desired+n);
sort(present,present+m);

ll count=0;
ll j=0;

for (ll i = 0; i < n; i++)
{   

    while(j!=m )
    {   
        if(desired[i]-k<= present[j] &&  present[j]<=desired[i]+k)
        { count++;
           break;
        }

        if(present[j]>desired[i]+k)
        {
            break;
        }

        j++;
        // cout<<"j "<<j<<endl;
    }

    if(j==m)
    {
        break;
    }
 
    
}

cout<<count<<endl;

return 0;
}