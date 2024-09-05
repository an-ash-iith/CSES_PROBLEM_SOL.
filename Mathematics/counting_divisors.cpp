#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 
const long long  INF = 1e18 + 5;
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
       
        int count=0;
        int i=1;
        for( i=1;i*i<a;i++)
        {
            if(a%i==0)
            {
                count+=2;
            }
        }

        if(i*i==a) count++;
          
         cout<<count<<endl;
    }
return 0;
}