#include <iostream>

using namespace std;
int main()
{

string s;
cin>>s;

int n = s.size();

int max=1;
int count=1;

char previous;
 
previous = s[0];

for (int i = 1; i < n; i++)
{  
    
    if(s[i]==previous)
    count++;

    else

    {
        if(count>max)
        {
            max=count;
        }

        previous=s[i];
        count=1;
    }
    


}

   if(count>max)
        {
            max=count;
        }

cout<<max<<endl;


return 0;
}