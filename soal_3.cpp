#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int r, c, jarak;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    int R, C, x_awal, y_awal, x_tuju, y_tuju;
    cin >> R >> C;

    int G[R][C];
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> G[i][j];
        }
    }
    cin >> x_awal >> y_awal;
    cin >> x_tuju >> y_tuju;
    
    bool visited[R][C];
    for (int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            visited[i][j] = false;
        }
    }

    queue<Node> q;

    q.push({x_awal, y_awal, 0});
    visited[x_awal][y_awal] = true;

    int totalLangkah = -1;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.r == x_tuju && curr.c == y_tuju) {
            totalLangkah = curr.jarak;
            break;
        }

        for (int i=0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (G[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, curr.jarak + 1});
                }
            }
        }
    }

    cout << totalLangkah;
}