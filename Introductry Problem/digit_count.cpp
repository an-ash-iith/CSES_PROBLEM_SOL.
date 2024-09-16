#include <iostream>
#include <math.h>
#define max 1000000000000000000
#define ll long long
using namespace std;

int main()
{

int t;
cin>>t;

while(t--)
{  
    ll n;
    cin>>n;
    
    ll val;
    ll i=0;

    
       while((pow(10,i)*(9*i-1)+1)/9<n)
             { i++;}


    // i denotes the number of digit
// cout<<val<<endl;
    ll j = i-1;
    ll rest = n-(pow(10,j)*(9*j-1)+1)/9;
   
//    cout<<rest<<"rs"<<endl;

// cout<<"i"<<i-1<<endl;
ll x,y;


    x = rest/(i);
    y = rest%(i);

// cout<<x<<" "<<y<<endl;

   ll final = pow(10,j)+x-1;
    //   cout<<final<<endl;
   string ans1= to_string(final);

  string ans2= to_string(final+1);

    if(y==0)
   cout<<ans1[i-1]<<endl;

   else
   cout<<ans2[y-1]<<endl;

}
return 0;
}