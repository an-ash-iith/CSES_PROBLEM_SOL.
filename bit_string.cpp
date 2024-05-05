#include <iostream>
using namespace std;
int main()
{

long long n;
cin>>n;

long long modulo = (long long)1000000007;

long long ans=1;

for (int i = 0; i < n; i++)
{
    ans =ans*2;

    if(ans>=modulo)
    {
        ans = ans%modulo;
    }
}

cout<<ans<<endl;

return 0;
}