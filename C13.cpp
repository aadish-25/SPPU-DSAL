// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify the
// prominent land marks as nodes and perform DFS and BFS on that.

#include <bits/stdc++.h>
using namespace std;

void DFS(int adjMatrix[5][5]){

    return;
}

void BFS(vector <int> adjList[5], int start){
    queue <int> q;
    int visited[5] = {0};
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int current = q.front();
        cout << current << " ";
        q.pop();

        for(int i=0; i<adjList[current].size(); i++){
            int neighbour = adjList[current][i];
            if(visited[neighbour] == 0){
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }      
    }
    return;
}

int main(){
    int V = 5;
    int adjMatrix[5][5] = {0}; //2d array
    vector <int> adjList[5]; // array of size 5, where each slot is vector of int


    
    cout << "The landmarks are : \n0 - Main Gate \n1 - Hostel \n2 - Library \n3 - Seminar Hall \n4 - Classroom" << endl;
    cout << "Enter between which places you want a route : (press any letter to exit)\n";

    int p, q;
    while(cin >> p >> q){
        if(p >= 0 && p < V && q>=0 && q < V){
            adjMatrix[p][q] = 1;
            adjMatrix[q][p] = 1;

            adjList[p].push_back(q);
            adjList[q].push_back(p);
            cout << "Route added between " << p << " and " << q << endl;
        }
        else{
            cout << "Invalid landmarks, try again!!" << endl;
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++){
        cout << i << ": ";
        for (int j : adjList[i]){
            cout << j << " ";
        }
        cout << "\n";
    }

    cin.clear();
    cin.ignore();
    int start;
    cout << "Enter the starting point (0-5) : ";
    cin >> start;

    cout << "\nDFS using the Adjacency Matrix\n";
    DFS(adjMatrix);
    cout << "\nBFS using the Adjacency List\n";
    BFS(adjList, start);
}