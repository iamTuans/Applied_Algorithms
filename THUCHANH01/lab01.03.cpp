//C++ 
#include <bits/stdc++.h> 
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 5;
const int logn = 20;

int a[maxn];
int m[maxn][logn];

void build(int n) {
    for (int i = 0; i < n; ++i) {
        m[i][0] = a[i];
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r) {
    int k = log2(r - l + 1);
    return min(m[l][k], m[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(n);

    cin >> m;
    int q = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        q += rmq(l, r);
    }

    cout << q;
    return 0;
}
