#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string movies;
    cin >> movies;

    int count[256];

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; i < movies.size(); i++)
        count[movies[i]] = count[movies[i]] + 1;

    vector<int>num;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] == 1)
            num.push_back(i);
    }

    for (int i = 0; i < movies.size(); i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (movies[i] == num[j])
                cout << i << " ";
        }
    }
    return 0;
}