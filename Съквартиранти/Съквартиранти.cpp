#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;


    for (int i = 0; i < Q; i++)
    {
        int len;
        cin >> len;
        int count = 0;
        vector<char>arr;

        for (int j = 0; j < len; j++)
        {
            char symbol;
            cin >> symbol;
            arr.push_back(symbol);
            if (j >= 1)
            {
                if (arr[j - 1] == arr[j])
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}