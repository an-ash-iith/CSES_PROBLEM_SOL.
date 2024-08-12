#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 

bool compare(int num1, int num2)
{
    if (__builtin_popcount(num1) <= __builtin_popcount(num2)) {
        return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> temp;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        temp.push_back(stoi(s, nullptr, 2));
    }

    // Apply merge sort -- first sort on the basis of number of 0 -- if no of 0 matches then sort which is closest to prev 
    // sort(temp.begin(), temp.end(), compare);

    int mini = 30;  // when all the bits differ

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // if (__builtin_popcount(temp[j]) - __builtin_popcount(temp[i]) >= mini) break;

            mini = min(mini, __builtin_popcount(temp[j] ^ temp[i]));
        }
    }

    cout << mini << endl;

    return 0;
}
