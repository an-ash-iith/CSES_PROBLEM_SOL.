#include <iostream>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{

     long long n ;
    cin>>n;

    //after solving the recurrence for this question answer will x*(x+1)/2   where x= 2^n  thus our motive is to find 2^n
    //we cant use shift operator because our number can be greater than 32 bit int

    ll mult =2;
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            ans=(ans*mult)%mod;
        }

        n=n/2;
        mult=(mult*mult)%mod;

    }   

cout<<ans*(ans+1)/2%mod<<endl;
return 0;
}