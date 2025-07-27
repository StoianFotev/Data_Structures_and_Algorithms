#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    vector<int>array;

    int N;
    cin >> N;

    int num;
    int price = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        array.push_back(num);
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (array[i] < array[i + 1])
            price = price + (-array[i] + array[i + 1]);
    }
    cout << price << endl;
    return 0;
}
