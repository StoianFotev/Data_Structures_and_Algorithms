#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<string>& arr1, vector<int>& arr, size_t l, size_t m, size_t r) {
    vector<int> a;
    for (size_t i = l; i <= m; i++) {
        a.push_back(arr[i]);
    }
    vector<int> b;
    for (size_t i = m + 1; i <= r; i++) {
        b.push_back(arr[i]);
    }
    vector<string> c;
    for (size_t i = l; i <= m; i++) {
        c.push_back(arr1[i]);
    }
    vector<string> d;
    for (size_t i = m + 1; i <= r; i++) {
        d.push_back(arr1[i]);
    }
    size_t i = 0, j = 0, inx = l;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            arr[inx] = a[i];
            arr1[inx++] = c[i++];
        }
        else if (a[i] == b[j] && c[i] < d[j]) {
            arr[inx] = a[i];
            arr1[inx++] = c[i++];
        }
        else {
            arr[inx] = b[j];
            arr1[inx++] = d[j++];
        }
    }
    while (i < a.size()) {
        arr[inx] = a[i];
        arr1[inx++] = c[i++];
    }
    while (j < b.size()) {
        arr[inx] = b[j];
        arr1[inx++] = d[j++];
    }
}

void mergeSort(vector<string>& arr1, vector<int>& arr, int l, int r) {
    if (l < r) {
        int  mid = l + (r - l) / 2;
        mergeSort(arr1, arr, l, mid);
        mergeSort(arr1, arr, mid + 1, r);
        merge(arr1, arr, l, mid, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> names;
    vector<int> points;
    size_t size;
    cin >> size;
    string buffer;
    int num;
    for (size_t i = 0; i < size; i++) {
        cin >> buffer;
        names.push_back(buffer);
    }
    for (size_t i = 0; i < size; i++) {
        cin >> num;
        points.push_back(num);
    }
    mergeSort(names, points, 0, points.size() - 1);
    for (size_t i = 0; i < size; i++) {
        cout << names[i] << " " << points[i] << '\n';
    }
    return 0;
}