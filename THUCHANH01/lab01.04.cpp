#include <bits/stdc++.h> 
#include <stack>
#include <vector>
using namespace std;

int Smax(vector<int>& heights) {
    stack<int> st;
    int maxA = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, h * w);
        }
        st.push(i);
    }

    return maxA;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> height(m, 0);
    int maxA = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                height[j] += 1;
            } else {
                height[j] = 0;
            }
        }
        maxA = max(maxA, Smax(height));
    }

    cout << maxA << endl;
    return 0;
}
