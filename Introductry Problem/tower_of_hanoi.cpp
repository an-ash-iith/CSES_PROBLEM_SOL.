#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> find_hanoi(int curr, int target, int mediate, int n)
{
    vector<pair<int, int>> ans;
    vector<pair<int, int>> ans1;

    if (n == 1)
    {
        ans.push_back(make_pair(curr, target));
        return ans;
    }

    if (n == 2)
    {
        ans.push_back(make_pair(curr, mediate));
        ans.push_back(make_pair(curr, target));
        ans.push_back(make_pair(mediate, target));

        return ans;
    }

    ans1 = find_hanoi(curr, mediate, target, n - 1);

    vector<pair<int, int>>::iterator it;

    for (auto it = ans1.begin(); it != ans1.end(); it++)
    {
        ans.push_back(*it);
    }

    ans.push_back(make_pair(curr, target));

    ans1 = find_hanoi(mediate, target, curr, n - 1);

    for (auto it = ans1.begin(); it != ans1.end(); it++)
    {
        ans.push_back(*it);
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> ans;

    //
    ans = find_hanoi(1, 3, 2, n);

        vector<pair<int, int>>::iterator it;
  

  cout<<ans.size()<<endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}