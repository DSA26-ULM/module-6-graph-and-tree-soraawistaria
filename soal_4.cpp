#include <iostream>
using namespace std;

int R, C, x_tuju, y_tuju;
int G[7][7];
bool visited[7][7];
int totalJalur = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == x_tuju && c == y_tuju) {
        totalJalur++;
        return;
    }

    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C && G[nr][nc] == 0 && !visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc);
            visited[nr][nc] = false;
        }
    }
}


int main() {
    cin >> R >> C;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> G[i][j];
        }
    }
    int x_awal, y_awal;
    cin >> x_awal >> y_awal;
    cin >> x_tuju >> y_tuju;
    
    visited[x_awal][y_awal] = true;
    dfs(x_awal, y_awal);

    cout << totalJalur;
}