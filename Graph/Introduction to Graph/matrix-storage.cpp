#include<iostream>
using namespace std;

int main() {
    //n is the number of the node's
    //m is the number of the edge between the two nodes
    int n, m;
    int adjMatrix[n+1][n+1];
    cout<<"Enter the number of the nodes : ";
    cin>>n;
    cout<<"Enter the number of the edges : ";
    cin>>m;
    for(int i = 0; i<m; i++) {
        int u, v;
        cout<<"Enter the node 1 : ";
        cin>>u;
        cout<<"Enter the node 2 : ";
        cin>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
