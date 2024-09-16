#include <iostream>
#include <set>
using namespace std;
int main()
{

int n;
cin>>n;

set<int> st;

for (int i = 0; i <n; i++)
{
    int val;
    cin>>val;
st.insert(val);
}

cout<<st.size()<<endl;

return 0;
}