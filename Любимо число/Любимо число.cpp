#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getCandies(long long idx, int P) {
    long long left = 0;
    long long right = pow(3LL, P);
    int depth = 1;

    while (right - left > 1) {
        long long size = (right - left) / 3;
        long long mid_start = left + size;
        long long mid_end = left + 2 * size;

        if (idx >= mid_start && idx < mid_end) {
            return depth;
        }

        if (idx < mid_start) {
            right = mid_start;
        }
        else {
            left = mid_end;
        }

        depth++;
    }

    return depth;
}

int main() {
    int P, N;
    cin >> P >> N;
    vector<long long> invited(N);

    for (int i = 0; i < N; ++i) {
        cin >> invited[i];
        invited[i]--;
    }

    for (int i = 0; i < N; ++i) {
        cout << getCandies(invited[i], P) << '\n';
    }

    return 0;
}
