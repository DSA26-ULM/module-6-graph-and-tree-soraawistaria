#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    char vertex[N];
    for (int i=0; i<N; i++) {
        cin >> vertex[i];
    }

    int Graph[N][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> Graph[i][j];
        }
    }

    cout << "\nAdjacency List : \n";
    for (int i=0; i<N; i++) {
        cout << vertex[i] << " -> ";

        bool hasEdge = false;
        for (int j=0; j<N; j++) {
            if (Graph[i][j] > 0) {
                if (hasEdge) cout << ", ";
                cout << "(" << vertex[j] << "," << Graph[i][j] << ")";
                hasEdge = true;
            }
        }

        if (!hasEdge) cout << "-";

        cout << endl;
    }
}