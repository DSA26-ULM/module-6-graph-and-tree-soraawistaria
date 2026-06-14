#include <bits/stdc++.h>
using namespace std;

typedef struct vertexnode VertexNode;
struct vertexnode
{
    int vertex;
    VertexNode *Next;
};

typedef struct graph 
{
    int numVertices;
    VertexNode **adjLists;
} Graph;

VertexNode *createVertex(int vertexNum)
{
    VertexNode *new_vertex = (VertexNode *) malloc(sizeof(VertexNode));
    new_vertex->vertex = vertexNum + 1;
    new_vertex->Next = NULL;
    return new_vertex;
}

Graph *createAGraph(int size)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = size;
    graph->adjLists = (VertexNode **)malloc(sizeof(VertexNode *));

    for(int i = 0; i < size; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int s, int d)
{
    VertexNode *newNode = createVertex(d);
    newNode->Next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

void printGraph(Graph *graph)
{
    for(int i = 0; i < graph->numVertices; i++)
    {
        VertexNode *temp = graph->adjLists[i];
        printf("\n Vertex %d\n: ", i+1);
        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->Next;
        }
        cout << endl;
    }
}

int main()
{
    int size, i, temp;
    //char input1[100000];

    scanf("%d\n", &size);   // scan number of vertices
    Graph *graph = createAGraph(size);

    for(i = 0; i < size; i++)  // scan the adjacency MATRIX
    {
        char input1[100000];
        int j = 0;
        fgets(input1, sizeof(input1), stdin);
        char *piece = strtok(input1, " "); // extract first number
        while(piece != NULL)
        {
            temp = atoi(piece); // convert from char to int
            if(temp == 1)   // create new node
            {
                addEdge(graph, i, j); //add edge from vertex i to j
            }
            j++;
            piece = strtok(NULL, " ");
        }
    }

    printGraph(graph);
    return 0;
}
