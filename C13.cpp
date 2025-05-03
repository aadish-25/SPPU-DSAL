// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify the
// prominent land marks as nodes and perform DFS and BFS on that.

#include <bits/stdc++.h>
using namespace std;

void DFS(int adjMatrix[5][5], int start, int visited[5]){

    // Space Complexity = O(V)
    // Time Complexity = O(2E) the dfs runs for every neghbouring nodes, thus TC = summation of degress
    // and that being equal to 2E

    visited[start] = 1;
    cout << start << " ";

    for(int i=0; i<5; i++){
        if(adjMatrix[start][i] == 1 && visited[i] == 0){
            DFS(adjMatrix, i, visited);
        }
    }
    return;
}

void BFS(vector <int> adjList[5], int start){

    // Space Complexity = O(V) -> Queue, visited array and the adj list : all take up V space
    // Time Complexity = O(V) + O(2E) = O(V + E) 
    // TC = O(V + E) for directed graph as each edge is chcekd only once

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
    // enter only a single letter to stop i.e x
    // do not enter multiple letters like ab, pqrs, etc
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
    cout << "Enter the starting point (0-4) : ";
    cin >> start;

    cout << "\nDFS using the Adjacency Matrix\n";
    int visited[5] = {0};
    DFS(adjMatrix, start, visited);

    cout << "\nBFS using the Adjacency List\n";
    BFS(adjList, start);
}