#include <iostream>
#include <vector>

using namespace std;


vector<string> find_grey(int n)
{
    vector<string> ans1;
    vector<string> ans2;
     
     if(n==1)
     {
        ans1.push_back("0");
        ans1.push_back("1");
        return ans1;
     }

     ans1 =find_grey(n-1);
     ans2=ans1;

     int k = ans1.size();

     for (int i = 0; i < k; i++)
     {
        ans2.push_back(ans1[k-1-i]);
     }
     
     for (int i = 0; i <k ; i++)
     {
        ans2[i]="0" + ans2[i];
     }

     for (int i = k; i < 2*k; i++)
     {
        ans2[i]="1" + ans2[i];
     }
     
     return ans2;
}


int main()
{

int n;
cin>>n;

vector<string> ans;

ans = find_grey(n);

for (int i = 0; i <ans.size(); i++)
{
    cout<<ans[i]<<endl;
}

return 0;
}