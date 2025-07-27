#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> array;
    int num;

    vector<int>oddNums;
    int sizeOfArray = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num % 2 != 0)
            oddNums.push_back(num);
        else
        {
            array.push_back(num);
            sizeOfArray++;
        }
    }

    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << array[i] << endl;
    }
    for (int i = 0; i < oddNums.size(); i++)
    {
        cout << oddNums[i] << endl;
    }
    return 0;
}