#include <iostream>
using namespace std;
int main()
{
int n;
cin>>n;

int arr[n+1];

int a;
for (int i = 0; i < n-1; i++)
{
    cin>>a;
    arr[a] = 1;
}

for (int i = 1; i <= n; i++)
{  
    if(arr[i]!=1)
    cout<<i<<endl;
    
}


return 0;
}