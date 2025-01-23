#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Tomato {
    int x, y, day;
};

int M, N;
vector<vector<int>> box;
vector<vector<bool>> visited;
queue<Tomato> q;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M && box[x][y] == 0 && !visited[x][y];
}

int bfs() {
    int days = 0;
    while (!q.empty()) {
        Tomato current = q.front();
        q.pop();    
        days = current.day;

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                box[nx][ny] = 1;
                q.push({nx, ny, current.day + 1});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) return -1;
        }
    }

    return days;
}

int main() {
    cin >> M >> N;
    box.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    cout << bfs() << endl;
    return 0;
}
