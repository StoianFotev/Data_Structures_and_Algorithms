#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T >> N;

    list<int> lru_list;
    unordered_map<int, list<int>::iterator> cache;

    for (int i = 0; i < T; ++i) {
        int M;
        cin >> M;

        if (cache.find(M) != cache.end()) {
            lru_list.erase(cache[M]);
            lru_list.push_back(M);
            cache[M] = prev(lru_list.end());
            cout << "true\n";
        }
        else {
            cout << "false\n";

            if ((int)cache.size() == N) {
                int oldest = lru_list.front();
                lru_list.pop_front();
                cache.erase(oldest);
            }

            lru_list.push_back(M);
            cache[M] = prev(lru_list.end());
        }
    }

    return 0;
}
