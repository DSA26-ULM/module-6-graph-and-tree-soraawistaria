#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N;

    int vertex[N];
    for (int i=0; i<N; i++) {
        cin >> vertex[i];
    }

    cin >> M;
    int U[M], V[M], W[M];
    for (int i=0; i<M; i++) {
        cin >> U[i] >> V[i] >> W[i]; //dari, ke, bobot
    }
}