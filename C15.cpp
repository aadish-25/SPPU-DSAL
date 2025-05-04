// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices with
// a minimum total cost. Solve the problem by suggesting appropriate data structures. 

// Prim's algorithm

#include <bits/stdc++.h>
using namespace std;

void primMST(int V, int costMatrix[10][10], int start, int visited[]){

    int minCost = 0;
    int minCostEdge, minEdge;
    visited[start] = 1;
    // cout << start << " ";    

    for(int count=1; count < V; count++){
        minCostEdge = 999999;  
        minEdge = INT_MAX; 


        for(int i=0; i<V; i++){
            if(costMatrix[start][i] < minCostEdge && costMatrix[start][i]!=0 && visited[i]==0){
              minCostEdge = costMatrix[start][i];
              minEdge = i;
            }
        }
        
        for(int i=0; i<V;i++){
            if(visited[i] == 1){
                for(int j=0; j<V; j++){
                    if(visited[j] == 0 && costMatrix[i][j]!=0 && costMatrix[i][j] < minCostEdge){
                        minEdge = j;
                        start = i;
                        minCostEdge = costMatrix[i][j];
                    }
                }
            }
        }

        minCost = minCost + costMatrix[start][minEdge];
        visited[minEdge] = 1;
        // cout << minEdge << " ";  
        cout << "(" << start << "," << minEdge << ") ";      
        start = minEdge;
    }

    cout << "\nCost of MST : " << minCost;
}


int main(){
    int V;
    cout << "Enter number of offices : ";
    cin >> V;

    int adjMatrix[10][10];
    int visited[10] = {0};
    int costMatrix[10][10];

    // initializing all matrixx entires to 0
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            adjMatrix[i][j] = 0;
            costMatrix[i][j] = 0;
        }
    }


    cout << "Enter the pair of cities (0-" << V-1 << ") you want a phone line between (Enter a character to exit): \n"; 
    int p, q, cost, start = -1;

    // fill in the adjacency matrix and cost matrix
    while(cin >> p >> q){
        if(p >= 0 && p < V && q>=0 && q < V){
            cout << "Enter the cost of the phone line between office " << p << " and " << q << ": ";
            cin >> cost;
            adjMatrix[p][q] = 1;
            adjMatrix[q][p] = 1;

            costMatrix[p][q] = cost;
            costMatrix[q][p] = cost;

            if(start == -1){
                start = p;
            }
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nCost Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << setw(4) << left << costMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "MST : ";
    primMST(V, costMatrix, start, visited);
}