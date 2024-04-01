#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a(const vector<int>& p, int C, int dis) {
    int count = 1;
    int pv = p[0];

    for (int i = 1; i < p.size(); ++i) {
        if (p[i] - pv >= dis) {
            ++count;
            pv = p[i];
        }
    }

    return count >= C;
}

int b(const vector<int>& p, int C) {
    int left = 0;
    int right = p.back() - p.front();
    int maxD = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a(p, C, mid)) {
            maxD = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxD;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, C;
        cin >> N >> C;

        vector<int> p(N);
        for (int i = 0; i < N; ++i) {
            cin >> p[i];
        }

        sort(p.begin(), p.end());

        int maxD = b(p, C);
        cout << maxD << endl;
    }

    return 0;
}
