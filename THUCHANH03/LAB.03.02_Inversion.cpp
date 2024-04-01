#include <iostream>
#include <vector>

using namespace std;

const int M = 1000000007;

long long merge(vector<int>& arr, vector<int>& tmp, int left, int m, int right) {
    long long a = 0;
    int i = left;
    int j = m + 1;
    int k = left;

    while (i <= m && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            a += m - i + 1;
            a %= M;
        }
    }

    while (i <= m) {
        tmp[k++] = arr[i++];
    }

    while (j <= right) {
        tmp[k++] = arr[j++];
    }

    for (int i = left; i <= right; ++i) {
        arr[i] = tmp[i];
    }

    return a;
}

long long mergeSort(vector<int>& arr, vector<int>& tmp, int left, int right) {
    long long a = 0;
    if (left < right) {
        int m = left + (right - left) / 2;
        a += mergeSort(arr, tmp, left, m);
        a %= M;
        a += mergeSort(arr, tmp, m + 1, right);
        a %= M;
        a += merge(arr, tmp, left, m, right);
        a %= M;
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> tmp(n);
    long long a = mergeSort(arr, tmp, 0, n - 1);

    cout << a << endl;

    return 0;
}
