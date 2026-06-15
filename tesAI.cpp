#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Struktur untuk menyimpan koordinat dan jarak dari titik awal
struct Node {
    int r, c, dist;
};

// Array arah untuk bergerak ke 4 tetangga: Atas, Bawah, Kiri, Kanan
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    int R = 8, C = 10;
    vector<vector<int>> grid(R, vector<int>(C));

    // 1. Membaca input matriks
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    // Membaca titik awal (0 0) dan titik akhir (7 9)
    int startR, startC, endR, endC;
    cin >> startR >> startC;
    cin >> endR >> endC;

    // Matriks visited untuk mencatat koordinat yang sudah dikunjungi
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    
    // Queue untuk menampung Node (baris, kolom, jarak)
    queue<Node> q;

    // Inisialisasi titik awal
    q.push({startR, startC, 0});
    visited[startR][startC] = true;

    int totalLangkah = -1;

    // 2. Loop BFS Grid
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        // Jika sudah mencapai titik tujuan, simpan jaraknya dan keluar loop
        if (curr.r == endR && curr.c == endC) {
            totalLangkah = curr.dist;
            break;
        }

        // Cek 4 arah mata angin (tetangga)
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            // Validasi: pastikan tetangga berada di dalam grid, bernilai 0 (jalan), dan belum visited
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, curr.dist + 1}); // Jarak bertambah 1 langkah
                }
            }
        }
    }

    // 3. Cetak Output
    cout << totalLangkah << endl;

    return 0;
}