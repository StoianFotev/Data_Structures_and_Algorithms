#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSplit(const vector<int>& people, int teams, long long maxSum) {
    int count = 1;
    long long currentSum = 0;

    for (int skill : people) {
        if (skill > maxSum) return false;

        if (currentSum + skill <= maxSum) {
            currentSum += skill;
        }
        else {
            count++;
            currentSum = skill;
        }
    }

    return count <= teams;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> people(n);
    long long totalSum = 0;
    int maxSkill = 0;

    for (int i = 0; i < n; ++i) {
        cin >> people[i];
        totalSum += people[i];
        maxSkill = max(maxSkill, people[i]);
    }

    long long low = maxSkill;
    long long high = totalSum;
    long long answer = totalSum;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canSplit(people, k, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
