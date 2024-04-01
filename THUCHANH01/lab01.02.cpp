#include <iostream>
#include <queue>

using namespace std;

struct coord {
    int x;
    int y;

    coord(int x, int y) : x(x), y(y) {}
};

int main() {
    int n, m, **maze, r, c;
    queue<coord> q;

    cin >> n >> m >> r >> c;
    --r;
    --c;

    maze = new int*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 1) {
                maze[i][j] = -1;
            }
        }
    }
    
    q.push(coord(r, c));
    while (!q.empty()) {
        coord cur = q.front();
        q.pop();
        int step = -maze[cur.x][cur.y] + 1;

        if (cur.x == 0 || cur.x == n - 1 || cur.y == 0 || cur.y == m - 1) {
            cout << step;
            return 0;
        }

        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                maze[nx][ny] = -step;
                q.push(coord(nx, ny));
            }
        }
    }
    cout << -1;
    return 0;
}
