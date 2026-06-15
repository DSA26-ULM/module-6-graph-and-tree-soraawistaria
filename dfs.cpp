#include <iostream>
#include <vector>

using namespace std;

void dfsRecursive(int node, vector<vector<int>> &adj, vector<bool> &visited) {

    visited[node] = true;

    cout << node << " ";

    for (int neighbor : adj[node]) {

        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }

    }

}

int main() {

    int nodes = 5;
    vector<vector<int>> adj(nodes);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(nodes, false);

    cout << "DFS Traversal starting from node 0: ";

    dfsRecursive(0, adj, visited);
    cout << endl;

    return 0;

}