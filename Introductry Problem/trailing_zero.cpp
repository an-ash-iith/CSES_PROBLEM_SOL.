#include <iostream>
using namespace std;
int main()
{

long long n;
cin>>n;

long long val =5;
long long count =0;

while(val<=n)
{
    count =count+ n/val;
    val=val*5;

}
cout<<count<<endl;

return 0;
}