#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int curr_max = arr[0];
    long long move = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < curr_max)
        {
            move += curr_max - arr[i];
        }
        else
            curr_max = arr[i];
    }

    cout << move << endl;

    return 0;
}