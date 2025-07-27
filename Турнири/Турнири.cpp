#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    for (int i = 0; i < Q; ++i) {
        int minW, maxW;
        cin >> minW >> maxW;

        if (minW > maxW) {
            cout << 0 << '\n';
            continue;
        }

        auto low = lower_bound(weights.begin(), weights.end(), minW);
        auto high = upper_bound(weights.begin(), weights.end(), maxW);

        cout << (high - low) << '\n';
    }

    return 0;
}
