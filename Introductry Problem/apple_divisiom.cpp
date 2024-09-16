#include <iostream>
#include <math.h>

using namespace std;

void dp(long long *arr,int i ,long long &min1,int n,long long sum,long long total_sum)
{
  
  if(i>=n)
  {
    if(abs(total_sum-2*sum)<min1)
      min1 = abs(total_sum-2*sum);

    return;
  }

//considering the index value 
 dp(arr,i+1,min1,n,sum+arr[i],total_sum);

  //without considering the index value
 dp(arr,i+1,min1,n,sum,total_sum);

  return;
}



int main() 
{

int n;
cin>>n;
long long arr[n];

long long total_sum =0;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
    total_sum=total_sum+arr[i];
}

long long min=INT32_MAX;
dp(arr,0,min,n,0,total_sum);

cout<<min<<endl;

return 0;
}