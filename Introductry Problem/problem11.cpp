#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{

    string s;
    cin >> s;

    unordered_map<char, long long > mp;
    long long n = s.size();
    //cout<<n<<endl;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    int count = 0;
    char mid;
    for (int i = 0; i < 26; i++)
    { 
       // cout<<mp[char('A'+i)]<<endl;
        if (mp[char('A' + i)] % 2 == 1)
        {
            count++;
            mid = char('A' + i);
        }

        if (count > 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    string ans = "";

    if(count==1)
    ans=ans+mid;

    for (int i = 0; i < 26; i++)
    {
        char charec = char('A' + i);
        long long  val = mp[charec];
        

        for (long long j = 0; j < val / 2; j++)
        {
            ans = charec + ans + charec;
        }
    }
  //cout<<ans.size()<<endl;
cout<<ans<<endl;

//   for (int i = 0; i < ans.size(); i++)
//   {
//     cout<<ans[i];
//     // cout<<i<<" ";
//   }
  
    //cout << endl;

    return 0;
}