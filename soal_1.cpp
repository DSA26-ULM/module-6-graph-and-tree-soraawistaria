#include <iostream>
using namespace std;
#define SIZE 10
#define NO_EDGE -1

typedef struct {
    int adjMatrix[SIZE][SIZE];
    char vertex[SIZE];
} Graph;


void init(Graph *g, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            g->adjMatrix[i][j] = NO_EDGE;
        }
        g->vertex[i] = 0;
    }
}

void addEdge(Graph *g, int u, int v, int w, int n) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        g->adjMatrix[u][v] = w;
    }
}


void addVertex (Graph *g, int v, char namaVertex, int n) {
    if (v >= 0 && v < n) {
        g->vertex[v] = namaVertex;
    }
}

void printGraph (Graph *g, int n) {
    cout << "Adjacency Matrix:\n";

    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout << g->vertex[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    for (int i=0; i < n; i++) {
        cout << g->vertex[i]; 
        for (int j=0; j<n; j++) {
            cout << " ";
            if (g->adjMatrix[i][j] == NO_EDGE) {
                cout << '0';
            } else {
                cout << g->adjMatrix[i][j];
            }
        }
        cout << endl;
    }
}


int main() {
    Graph g;
    int N, M;
    cin >> N;
    init(&g, N);


    for (int i=0; i<N; i++) {
        char vertex;
        cin >> vertex;
        addVertex(&g, i, vertex, N);
    }

    cin >> M;
    char U, V;
    int W;
    for (int i=0; i<M; i++) {
        cin >> U >> V >> W;
        addEdge(&g, (U - 'A'), (V - 'A'), W, N);
    }

    printGraph(&g, N);
}