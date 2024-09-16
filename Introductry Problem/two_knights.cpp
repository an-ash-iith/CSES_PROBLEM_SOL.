#include <iostream>
using namespace std;
int main()
{

int n;
cin>>n;
unsigned long long int ans;


 for (long long  i = 1; i <= n; i++)
{
if(i==1)
{
    cout<<0<<endl;
}
else if (i==2)
{
    cout<<6<<endl;
}
else if(i==3)
{
    cout<<28<<endl;
}
else
{
    ans= (i*i*i+i*i-8*i+16)/2;
    ans=ans*(i-1);

    cout<<ans<<endl;
}
  
}

return 0;
}