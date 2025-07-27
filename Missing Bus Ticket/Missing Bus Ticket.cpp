#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> numbers;

    unsigned size;
    int num;
    int min = 1;
    cin >> size;
    for (unsigned i = 0; i < size; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    if (size == 1) {
        if (numbers[0] == 1) {
            min = 2;
        }
    }
    for (unsigned int i = 0; i < size - 1; i++) {
        if (numbers[i] == min && numbers[i] > 0) {
            if (numbers[i + 1] != min || i == size - 2) {
                min++;
            }
        }
    }
    if (numbers[size - 1] == min) {
        min++;
    }
    cout << min;
    return 0;
}