#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int a, b;
};

bool c(const Segment& s1, const Segment& s2) {
    return s1.b < s2.b;
}

int find(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), c);

    int count = 1; 
    int b = segments[0].b;

    for (int i = 1; i < segments.size(); ++i) {
         if (segments[i].a > b) {
            ++count;
            b = segments[i].b;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].a >> segments[i].b;
    }

    int s = find(segments);

    cout << s << endl;

    return 0;
}
