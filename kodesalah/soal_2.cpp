#include <iostream>
using namespace std;


// Source - https://stackoverflow.com/q/69834663
// Posted by mrkupidooo, modified by community. See post 'Timeline' for change history
// Retrieved 2026-06-14, License - CC BY-SA 4.0
// tapi ini semua aku anu anukan!!, aku mikir dulu!!, tapi referensi dari stackoverflow 

typedef struct vertexnode vertexNode;
struct vertexnode{
    char namaVertex;
    int weight;
    vertexNode *Next;
};

typedef struct {
    int jumlahVertex;
    vertexNode **adjList;
} Graph;

vertexNode* createVertex(char nama, int w) {
    vertexNode *new_vertex = new vertexnode;
    new_vertex->namaVertex = nama;
    new_vertex->weight = w;
    new_vertex->Next = NULL;
    return new_vertex;
}

Graph* createGraph (int size) {
    Graph *graph = new Graph;
    graph->jumlahVertex = size;
    graph->adjList = new vertexNode*[size];

    for (int i=0; i<size; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge (Graph *graph, int s, char nama, int w) {
    vertexNode *newNode = createVertex(nama, w);

    if (graph->adjList[s] == NULL) {
        graph->adjList[s] = newNode;
    } else {
        vertexNode *temp = graph->adjList[s];
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void printAdj (Graph *graph, char namaVertex[]) {
    cout << "Adjacency List: \n";
    for (int i=0; i < graph->jumlahVertex; i++) {
        vertexNode *temp = graph->adjList[i];
        cout << namaVertex[i] << " -> ";

        if (temp == NULL) {
            cout << "-";
        } else {
            while (temp) {
                cout << "(" << temp->namaVertex << "," << temp->weight << ")";
                if (temp->Next) cout << ", ";
                temp = temp->Next;
            }
        }
        cout << endl;
    }
}

void clearGraph(Graph *graph) {
    for (int i = 0; i < graph->jumlahVertex; i++) {
        vertexNode *current = graph->adjList[i];
        while (current != NULL) {
            vertexNode *next = current->Next;
            delete current;
            current = next;
        }
        graph->adjList[i] = NULL;
    }
    delete[] graph->adjList;

    delete graph;
}

int main() {
    int N;
    cin >> N;

    char nama[N];
    for (int i=0; i < N; i++) {
        cin >> nama[i];
    }

    Graph *g = createGraph(N);

    int A[N][N];
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] > 0) {
                addEdge(g, i, nama[j], A[i][j]);
            }
        }
    }

    cout << endl;
    printAdj(g, nama);
    clearGraph(g);
    g = nullptr;
}