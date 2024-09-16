#include <iostream>
#include <vector> 
using namespace std;
int main()
{

long long  n ;
cin>>n;

long long sum = n*(n+1)/2;

if(sum%2==1)
{
    cout<<"NO"<<endl;
    return 0;
}

long long need_sum=sum/2;

int arr[n];
for (int i = 0; i < n; i++)
{
    arr[i]=i+1;
}

vector<int> ans1;
vector<int> ans2;

long long val = 0;

if(sum %2 == 1)
{
  cout<<"NO"<<endl;
  return 0;
}
else
{
  cout<<"YES"<<endl;
}

int i=n-1;
while(val!=need_sum )
{
  if(val+arr[i]<=need_sum)
  {
    val+=arr[i];
    ans1.push_back(arr[i]); 
  }
  else
  {
    ans2.push_back(arr[i]);
  }
  i--;
}


for (int k = 0; k <=i; k++)
{
   ans2.push_back(arr[k]);
}

cout<<ans1.size()<<endl;

for (int i = 0; i < ans1.size(); i++)
{
  cout<<ans1[i]<<" ";
}
cout<<endl;

cout<<ans2.size()<<endl;

for (int i = 0; i < ans2.size(); i++)
{
  cout<<ans2[i]<<" ";
}
cout<<endl;



return 0;
}